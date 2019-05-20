#include <iostream>
#define MAX 100
#define MOD 100007
using namespace std;
//step1 一开始以为是动态规划 找了一下规律发现是fibnacci
//常规求法不能应对INT_MAX 所以使用矩阵快速幂

//2*2矩阵相乘
void two_dim_mult_mod(long long A[][2], long long B[][2], long long C[][2]) {
	//C = A * B
	long long tmp[2][2] = {0, 0, 0, 0};
	tmp[0][0] = ((A[0][0]*B[0][0])%MOD + (A[1][0]*B[0][1])%MOD) % MOD;
	tmp[0][1] = ((A[0][0]*B[0][1])%MOD + (A[0][1]*B[1][1])%MOD) % MOD;
	tmp[1][0] = ((A[1][0]*B[0][0])%MOD + (A[1][1]*B[0][1])%MOD) % MOD;
	tmp[1][1] = ((A[1][0]*B[0][1])%MOD + (A[1][1]*B[1][1])%MOD) % MOD;
	C[0][0] = tmp[0][0];
	C[0][1] = tmp[0][1];
	C[1][0] = tmp[1][0];
	C[1][1] = tmp[1][1];
}

//矩阵快速米
int fast_fib(int n){
	if (n==1)	return 2;
	else if (n==2)	return 3;
	long long mat[2][2] = {1, 1, 1, 0};
	long long res[2][2] = {1, 0, 0, 1};
	int power = n - 2;
	while (power) {
		// 当前矩阵值需要乘到结果上
		if (power%2 == 1) {  
			two_dim_mult_mod(res, mat, res);
		}
		// 矩阵幂次翻倍
		two_dim_mult_mod(mat, mat, mat);
		power = power >> 1;
	}
	return (res[0][0]*3 + res[0][1]*2)%MOD;
}

int main(int argc, char *argv[]) {
	int n;
	while(scanf("%d", &n)!=EOF){
		printf("%d\n", fast_fib(n)%MOD);
	}
}