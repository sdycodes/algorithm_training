#include <iostream>
#include <cstring>

using namespace std;
int b[500], a[500];
int state[305][305][305];
int n;
void dfs(int idx, int pre, int cur){
	if(state[idx][pre][cur])	return;
	state[idx][pre][cur] = 1;
	if(idx==n-1){
		for(int i=0;i<=2;i++){
			a[n] = 3 * b[n-1] + i - pre - cur;
			if((a[n-1]+a[n])/2==b[n]){
				for(int j=1;j<=n;j++)
					cout<<a[j]<<' ';
				exit(0);
			}
		}
	}
	//recursion
	for(int i=0;i<=2;i++){
		a[idx+1] = 3 * b[idx] + i - pre - cur;
		if(a[idx+1]>0)
			dfs(idx+1, cur, a[idx+1]);
	}
}
int main(int argc, char *argv[]) {
	memset(state, 0, sizeof(state));
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>b[i];	
	
	for(int i=1; i<=2*b[1]; i++){
		a[1] = i;
		a[2] = 2*b[1]-i;
		dfs(2, a[1], a[2]);
		a[2] = 2*b[1]-i+1;
		dfs(2, a[1], a[2]);
	}
}