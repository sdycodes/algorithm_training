#include <iostream>
#include <cmath>
using namespace std;
int res[20];
bool used[20];
int n;

bool isPrime(int n){
	for(int i=2;i<=(int)sqrt(n)+1&&i<n;i++){
		if(n%i==0)	return false;
	}
	return true;
}

void dfs(int loc){
	if(loc==n){
		if(isPrime(res[loc-1]+1)){
			for(int i=0;i<n-1;i++)
				printf("%d ", res[i]);
			printf("%d\n", res[n-1]);
		}
		return;
	}
	for(int i=2;i<=n;i++){
		if(used[i]||!isPrime(res[loc-1]+i))	continue;
		res[loc] = i;
		used[i] = true;
		dfs(loc+1);
		used[i] = false;
	}
}
int main(int argc, char *argv[]) {
	int cnt = 1;
	while(scanf("%d", &n)!=EOF){
		printf("Case %d:\n", cnt++);
		memset(res, 0, sizeof(res));
		memset(used, 0, sizeof(used));
		res[0] = 1;
		used[1] = true;
		dfs(1);
		printf("\n");
	}
			
}