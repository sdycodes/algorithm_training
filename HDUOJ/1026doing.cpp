#include <iostream>
#include <queue>

using namespace std;

struct Node{
	int r, c, t, pr, pc;
	bool operator<(const Node&b){
		return this->t<=b.t;
	}
};


char cas[105][105];

int N, M;
int bfs(){
	priority_queue<vector<int>,  less<int> > q;
	Node tmp, next;
	tmp.pr = -1;
	tmp.pr = -1;
	tmp.r = 0;
	tmp.c = 0;
	tmp.t = 0;
	q.push(tmp);
	while(!q.empty()){
		tmp = q.pop();
		if(tmp.r+1>=0&&tmp.r+1<N){
			next.pr = tmp.r;
			next.pr = 
		}
		
	}
}
int main(int argc, char *argv[]) {
	while(scanf("%d%d", &N, &M)!=EOF){
		memset(visited, 0, sizeof(visited));
		getchar();
		for(int i=0;i<N;i++){
			for(int j=0;j<M;j++){
				scanf("%c", &cas[i][j]);
			}
			getchar();
		}
		//calculate dp
		int res = bfs();
		//output
		if(rec[0][0]=='N')	printf("God please help our poor hero.\n");
		else{
			printf("It takes %d seconds to reach the target position, let me show you the way.\n", res);
			int r = 0, c = 0, t = 1;
			while(1){
				if(cas[r][c]!='.'){
					for(int i=1;i<=cas[r][c]-'0';i++)
						printf("%ds:FIGHT AT (%d,%d)\n", t++, r, c);
				}
				if(rec[r][c]=='F')	break;
				switch(rec[r][c]){
					case 'R':
						printf("%ds:(%d,%d)->(%d,%d)\n", t++, r, c, r, c);
						c++;
					break;
					case 'D':
						printf("%ds:(%d,%d)->(%d,%d)\n", t++, r, c, r, c);
						r++;
					break;
					case 'U':
						printf("%ds:(%d,%d)->(%d,%d)\n", t++, r, c, r, c);
						r--;
					break;
					case 'L':
						printf("%ds:(%d,%d)->(%d,%d)\n", t++, r, c, r, c);
						c--;
					break;
					defult:
					break;
				}
			}
		}
		printf("FINISH\n");
	}

}