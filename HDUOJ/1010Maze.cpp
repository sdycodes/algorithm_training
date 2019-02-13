#include <iostream>

using namespace std;

char g[7][7];
int N, M, T; //N rows M cols
bool dfs(int x, int y, int t){
	if(x<0||y<0||x>=N||y>=M||g[x][y]=='X'||(g[x][y]=='D'&&t!=T)||t>T)	return false;
	if(g[x][y]=='D'&&t==T)	return true;
	g[x][y] = 'X';
	bool res = dfs(x+1, y, t+1)||dfs(x-1, y, t+1)||dfs(x, y+1, t+1)||dfs(x, y-1, t+1);
	g[x][y] = '.';
	return res;
}
int main(int argc, char *argv[]) {
	int sx, sy;
	while(scanf("%d%d%d", &N, &M, &T)&&N!=0&&M!=0&&T!=0){
		getchar();
		for(int i=0;i<N;i++){
			for(int j=0;j<M;j++){
				scanf("%c", &(g[i][j]));
				if(g[i][j]=='S'){
					sx = i;
					sy = j;
				}
			}
			getchar();
		}
		if(dfs(sx, sy, 0))
			printf("YES\n");
		else
			printf("NO\n");
	}	
}