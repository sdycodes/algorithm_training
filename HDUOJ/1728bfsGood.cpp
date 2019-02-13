#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

//优先队列的使用
//注意 提高空间效率 只有被松弛(<=)才入队 等于的情况因为方向更多 保留充分的备选 也要加入
//这也是为什么不能使用vis数组标记出队结点的原因 他们可能以不同的方向但是相同的转向数再次入队
//方向问题的处理方法  小数组 亦或 0xf

struct Node{
	int x, y, turn, dir;
	char a;
	friend bool operator<(Node a, Node b){
		return a.turn > b.turn;
	}
}g[105][105];

int k, x1, y1, x2, y2;
int m, n;
int bfs(){
	priority_queue<Node> q;
	int itmp;
	g[y1][x1].dir = 0xf;
	g[y1][x1].turn = 0;
	q.push(g[y1][x1]);
	int dx[4] = {0, 0, -1, 1}, dy[4] = {-1, 1, 0, 0};
	while(!q.empty()){
		Node tmp = q.top();
		q.pop();
		if(tmp.x==x2&&tmp.y==y2)
			return tmp.turn;	//找到直接返回
		if(tmp.turn>k)
			return k+1;
		for(int i=0;i<4;i++){
			int nx = tmp.x + dx[i], ny  = tmp.y + dy[i];
			if(nx<=m&&nx>=1&&ny<=n&&ny>=1&&g[ny][nx].a!='*'){
				if(((1<<i)&tmp.dir)!=0 && g[ny][nx].turn>=tmp.turn){
					g[ny][nx].turn = tmp.turn;
					g[ny][nx].dir = 1<<i;
					q.push(g[ny][nx]);
				}
				else if(((1<<i)&tmp.dir)==0 && g[ny][nx].turn>=tmp.turn+1){
					g[ny][nx].turn = tmp.turn+1;
					g[ny][nx].dir = 1<<i;
					q.push(g[ny][nx]);
				}
			}
		}
	}
	return k+1;
}

int main(int argc, char *argv[]) {
	int T;
	scanf("%d", &T);
	while(T--){
		memset(g, 0, sizeof(g));
		scanf("%d%d", &n, &m);
		for(int i=1;i<=n;i++){
			getchar();
			for(int j=1;j<=m;j++){
				scanf("%c", &(g[i][j].a));
				g[i][j].x = j;
				g[i][j].y = i;
				g[i][j].turn = 100;
			}
		}
		scanf("%d%d%d%d%d", &k, &x1, &y1, &x2, &y2);
		if(bfs()<=k)	printf("yes\n");
		else	printf("no\n");
	}
}