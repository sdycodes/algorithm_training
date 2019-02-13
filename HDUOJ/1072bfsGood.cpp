#include <iostream>
#include <queue>

using namespace std;

struct Node{
	int x, y, time, rem;
}g[10][10];
int map[10][10];

int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
int sx, sy, n, m;

void bfs(){
	queue<Node> q;
	g[sx][sy].time = 0;
	g[sx][sy].rem = 6;
	q.push(g[sx][sy]);
	while(!q.empty()){
		Node tmp = q.front();
		q.pop();
		if(map[tmp.x][tmp.y]==3){
			printf("%d\n", g[tmp.x][tmp.y].time);
			return;
		}
		for(int i=0;i<4;i++){
			int nx = tmp.x + dx[i], ny = tmp.y + dy[i];
			if(nx>=0&&nx<n&&ny>=0&&ny<m&&map[nx][ny]!=0&&tmp.rem>1){
				g[nx][ny].time = tmp.time + 1;
				g[nx][ny].rem = tmp.rem - 1;
				if(map[nx][ny]==4){
					g[nx][ny].rem = 6;
					map[nx][ny] = 0;
				}
				q.push(g[nx][ny]);			
			}
		}
	}
	printf("-1\n");
}
int main(int argc, char *argv[]) {
	int T;
	scanf("%d", &T);
	while(T--){
		scanf("%d%d", &n, &m);
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				scanf("%d", &(map[i][j]));
				g[i][j].x = i;
				g[i][j].y = j;
				g[i][j].time = 0;
				g[i][j].rem = 0;
				if(map[i][j]==2){
					sx = i;
					sy = j;
				}
			}
		}
		bfs();
	}
}