#include <cstdio>
#include <queue>
#include <stack>
using namespace std;
//good
//dij nlogn的算法 使用优先队列优化 这里面涉及使用结构体 友元 运算符重载（注意重载<，并且不满足条件出队）
//有没有visited看起来无关紧要 但是这样的好处是加速
//四个方向判断可达性最好包含陷阱 这样可以避免INF出现在加法中导致溢出
//队列中的元素已经无法更改了 所以松弛之后的结果是插入的新的，所以加速策略是遇到中点直接结束
//注意通过时间和到达时间的问题  必须把决策时所处的点的通过时间（打怪兽）算在内，因为dij到这个点的最前面进行决策
int n, m;
struct Node{
	int r, c;
	char t;
	int arr_time, pss_time;
	int pr, pc;
	friend bool operator<(Node a, Node b){
		return a.arr_time>b.arr_time;
	}
};
Node cas[105][105];
bool vis[105][105];
int main(int argc, char *argv[]){
	
	while(scanf("%d%d", &n, &m)!=EOF){
		//输入到结构体中
		getchar();
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				scanf("%c", &(cas[i][j].t));
				cas[i][j].r = i;
				cas[i][j].c = j;
				cas[i][j].pr = -1;
				cas[i][j].pc = -1;
				cas[i][j].arr_time = INT_MAX;
				cas[i][j].pss_time = cas[i][j].t=='.'?1:(cas[i][j].t=='X'?INT_MAX:cas[i][j].t-'0'+1);
			}
			getchar();
		}
		//计算前的初始化
		cas[0][0].pss_time = cas[0][0].t=='.'?0:(cas[0][0].t-'0');	//经过第一个点需要时间
		cas[0][0].arr_time = cas[0][0].pss_time;
		int curtime = 0;
		//使用队列进行DJ算法 nlogn
		priority_queue<Node> q;
		memset(vis, 0, sizeof(vis));
		q.push(cas[0][0]);
		Node tmp;
		while(!q.empty()){
			tmp = q.top();
			q.pop();
			int i = tmp.r;
			int j = tmp.c;
			vis[i][j] = true;
			if(i==n-1&&j==m-1)	break;
			curtime = tmp.arr_time;
			if(tmp.r+1<n && cas[i+1][j].t!='X' && !vis[i+1][j] && cas[i+1][j].arr_time>curtime+cas[i+1][j].pss_time){
				cas[i+1][j].arr_time = curtime+cas[i+1][j].pss_time;
				cas[i+1][j].pr = i;
				cas[i+1][j].pc = j;
				q.push(cas[i+1][j]);			
			}
			if(tmp.r-1>=0 && cas[i-1][j].t!='X' && !vis[i-1][j] && cas[i-1][j].arr_time>curtime+cas[i-1][j].pss_time){
				cas[i-1][j].arr_time = curtime+cas[i-1][j].pss_time;
				cas[i-1][j].pr = i;
				cas[i-1][j].pc = j;
				q.push(cas[i-1][j]);
			}
			if(tmp.c+1<m && cas[i][j+1].t!='X' && !vis[i][j+1] && cas[i][j+1].arr_time>curtime+cas[i][j+1].pss_time){
				cas[i][j+1].arr_time = curtime+cas[i][j+1].pss_time;
				cas[i][j+1].pr = i;
				cas[i][j+1].pc = j;
				q.push(cas[i][j+1]);
			}
			if(tmp.c-1>=0 && cas[i][j-1].t!='X' && !vis[i][j-1] && cas[i][j-1].arr_time>curtime+cas[i][j-1].pss_time){
				cas[i][j-1].arr_time = curtime+cas[i][j-1].pss_time;
				cas[i][j-1].pr = i;
				cas[i][j-1].pc = j;
				q.push(cas[i][j-1]);
			}
		}
		if(cas[n-1][m-1].pr==-1){
			printf("God please help our poor hero.\nFINISH\n");
		}
		else{
			printf("It takes %d seconds to reach the target position, let me show you the way.\n", cas[n-1][m-1].arr_time);
			stack<int> rec;
			vector<pair<int, int> > st;
			int x = n-1, y = m-1;
			while(x!=-1){
				tmp = cas[x][y];
				rec.push(x*m+y);
				x = tmp.pr;
				y = tmp.pc;
			}
			while(!rec.empty()){
				int a = rec.top();
				rec.pop();
				st.push_back(make_pair(a/m, a%m));
			}
			int timecnt = 1, w = 0;
			for(;w<st.size()-1;w++){
				if(cas[st[w].first][st[w].second].t!='.'){
					for(int tcnt=0;tcnt<cas[st[w].first][st[w].second].t-'0';tcnt++)
						printf("%ds:FIGHT AT (%d,%d)\n", timecnt++, st[w].first, st[w].second);
				}
				printf("%ds:(%d,%d)->(%d,%d)\n", timecnt++, st[w].first, st[w].second, st[w+1].first, st[w+1].second);
			}
			if(cas[st[w].first][st[w].second].t!='.'){
				for(int tcnt=0;tcnt<cas[st[w].first][st[w].second].t-'0';tcnt++)
					printf("%ds:FIGHT AT (%d,%d)\n", timecnt++, st[w].first, st[w].second);
			}
			printf("FINISH\n");
		}
	}
	return 0;
}