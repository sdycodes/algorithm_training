#include <stdio.h>
#include <stdlib.h>

int** MatPow(int** a,int **b){
	int** c;
	c = (int**)malloc(sizeof(int*)*2);
	c[0] = (int*)malloc(sizeof(int)*2);
	c[1] = (int*)malloc(sizeof(int)*2);
	c[0][0] = (a[0][0]*b[0][0]+a[0][1]*b[1][0])%7;
	c[0][1] = (a[0][0]*b[0][1]+a[0][1]*b[1][1])%7;
	c[1][0] = (a[1][0]*b[0][0]+a[1][1]*b[1][0])%7;
	c[1][1] = (a[1][0]*b[0][1]+a[1][1]*b[1][1])%7;
	return c;
}


int** quickPow(int** a, int k){
	int** res;
	res = (int**)malloc(sizeof(int*)*2);
	res[0] = (int*)malloc(sizeof(int)*2);
	res[1] = (int*)malloc(sizeof(int)*2);
	res[0][0] = 1;
	res[0][1] = 0;
	res[1][0] = 0;
	res[1][1] = 1;
	while(k){
		if(k%2)
			res = MatPow(res, a);
		a = MatPow(a, a);
		k = k>>1;
	}
	return res;
}
int dp[100000005];
void f(int A, int B){
	dp[1] = 1;
	dp[2] = 1;
	for(int i=3;i<=10000;i++)
		dp[i] = (A*dp[i-1]+B*dp[i-2])%7;
}

int sol(int n, int A, int B){
	int** a,k;
	a = (int**)malloc(sizeof(int*)*2);
	a[0] = (int*)malloc(sizeof(int)*2);
	a[1] = (int*)malloc(sizeof(int)*2);
	//while(1){
		//scanf("%d%d%d", &A, &B, &n);
		if(n==0)	return 0; //break;
		a[0][0] = (A*A+B)%7;
		a[0][1] = (A*B)%7;
		a[1][0] = A%7;
		a[1][1] = B%7;
		if(n<=2){
			return 1;
			//printf("%d\n", 1);
			//continue;
		}
		else{
			if(n%2==0){
				k = (n-2)>>1;
				a = quickPow(a, k);
				return (a[0][0]+a[0][1])%7;
				//printf("%d\n", (a[0][0]+a[0][1])%7);
			}
			else{
				k = (n-1)>>1;
				a = quickPow(a, k);
				return (a[1][0]+a[1][1])%7;
				//printf("%d\n", (a[1][0]+a[1][1])%7);
			}
		}
	//}
}
void duipai(){
	int A, B, n;
	for(A=1;A<=1000;A++){
		for(B=1;B<=50;B++){
			f(A, B);
			printf("%d\n", 1000*(A-1)+B);
			for(n=1;n<=10000;n++){
				if(dp[n]!=sol(n, A, B)){
					printf("f: %d sol: %d A: %d B: %d n:%d\n", dp[n], sol(n, A, B), A, B, n);
					return;
				}
			}
			
		}
	}
}
int main(int argc, char *argv[]) {
	
	int A, B, n, k;
	int** a;
	a = (int**)malloc(sizeof(int*)*2);
	a[0] = (int*)malloc(sizeof(int)*2);
	a[1] = (int*)malloc(sizeof(int)*2);
	while(1){
		scanf("%d%d%d", &A, &B, &n);
		if(n==0)	break;
		a[0][0] = (A*A+B)%7;
		a[0][1] = (A*B)%7;
		a[1][0] = A%7;
		a[1][1] = B%7;
		if(n<=2){
			printf("%d\n", 1);
			continue;
		}
		else{
			if(n%2==0){
				k = (n-2)>>1;
				a = quickPow(a, k);
				printf("%d\n", (a[0][0]+a[0][1])%7);
			}
			else{
				k = (n-1)>>1;
				a = quickPow(a, k);
				printf("%d\n", (a[1][0]+a[1][1])%7);
			}
		}
	}
	//duipai();
	return 0;
}