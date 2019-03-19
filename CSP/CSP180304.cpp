#include <iostream>
#include <cstring>
using namespace std;
int a[3][3];
int finish(){
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++)
			if(a[i][j]==0)
				return 0;
	}
	return 1;
}
int max(int a, int b){
	return a>=b?a:b;
}
int min(int a, int b){
	return a<=b?a:b;
}
int whoWin(){
	// judge row
	for(int i=0;i<3;i++){
		if(a[i][0]==1&&a[i][1]==1&&a[i][2]==1)
			return 1;
		else if(a[i][0]==2&&a[i][1]==2&&a[i][2]==2)
			return 2;
	}
	//judge col
	for(int j=0;j<3;j++){
		if(a[0][j]==1&&a[1][j]==1&&a[2][j]==1)
			return 1;
		else if(a[0][j]==2&&a[1][j]==2&&a[2][j]==2)
			return 2;
	}
	//judge diag
	if(a[0][0]==1&&a[1][1]==1&&a[2][2]==1)
		return 1;
	else if(a[0][0]==2&&a[1][1]==2&&a[2][2]==2)
		return 2;
	else if(a[0][2]==1&&a[1][1]==1&&a[2][0]==1)
		return 1;
	else if(a[0][2]==2&&a[1][1]==2&&a[2][0]==2)
		return 2;
	return 0;
}
int cal_score(){
	int res = 1;
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			if(a[i][j]==0)
				res ++;
	return res;
}
int dfs(int who){
	int winner = whoWin();
	if(winner==1){
		return cal_score();
	}
	else if(winner==2){
		return -cal_score();
	}
	else if(finish()){
		return 0;	
	}
		
	if(who==1){
		int res = -100;
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				if(a[i][j]==0){
					a[i][j] = 1;
					res = max(res, dfs(2));
					a[i][j] = 0;	
				}
			}
		}
		return res;
	}
	else {
		int res = +100;
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				if(a[i][j]==0){
					a[i][j] = 2;
					res = min(res, dfs(1));
					a[i][j] = 0;	
				}
			}
		}
		return res;
	}
}
int main(int argc, char *argv[]) {
	int T;
	cin>>T;
	while(T--){
		memset(a, 0, sizeof(a));
		for(int i=0;i<3;i++)
			for(int j=0;j<3;j++)
				scanf("%d", &a[i][j]);
		printf("%d\n", dfs(1));
	}
	return 0;
}