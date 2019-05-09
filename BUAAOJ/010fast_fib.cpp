#include <iostream>
#define MAX 100
using namespace std;
//step1 一开始以为是动态规划 找了一下规律发现是fibnacci
//常规求法不能应对INT_MAX 所以使用矩阵快速幂
int fast_fib(int n){
	if (n==1)	return 2;
	else if (n==2)	return 3;
	long long mat[2][2] = {1, 1, 1, 0};
	long long tmp[2][2] = {0, 0, 0, 0};
	long long res[2][2] = {1, 0, 0, 1};
	int power = n - 2;
	while (power) {
		if (power%2 == 1) {
			tmp[0][0] = ((res[0][0]*mat[0][0])%100007 + (res[1][0]*mat[0][1])%100007) % 100007;
			tmp[0][1] = ((res[0][0]*mat[0][1])%100007 + (res[0][1]*mat[1][1])%100007) % 100007;
			tmp[1][0] = ((res[1][0]*mat[0][0])%100007 + (res[1][1]*mat[0][1])%100007) % 100007;
			tmp[1][1] = ((res[1][0]*mat[0][1])%100007 + (res[1][1]*mat[1][1])%100007) % 100007;
			res[0][0] = tmp[0][0];
			res[0][1] = tmp[0][1];
			res[1][0] = tmp[1][0];
			res[1][1] = tmp[1][1];
		}
		tmp[0][0] = ((mat[0][0]*mat[0][0])%100007 + (mat[1][0]*mat[0][1])%100007) % 100007;
		tmp[0][1] = ((mat[0][0]*mat[0][1])%100007 + (mat[0][1]*mat[1][1])%100007) % 100007;
		tmp[1][0] = ((mat[1][0]*mat[0][0])%100007 + (mat[1][1]*mat[0][1])%100007) % 100007;
		tmp[1][1] = ((mat[1][0]*mat[0][1])%100007 + (mat[1][1]*mat[1][1])%100007) % 100007;
		mat[0][0] = tmp[0][0];
		mat[0][1] = tmp[0][1];
		mat[1][0] = tmp[1][0];
		mat[1][1] = tmp[1][1];
		power = power >> 1;
	}
	return (res[0][0]*3 + res[0][1]*2)%100007;
}

//1 2 3 5 8 13 21 34 55 89 144 233 377 610 987 1597 2584 4181 6765 
//1 1 2 3 5 8 13 21 34 55 89 144 233 377 610 987 1597 2584 4181 
int main(int argc, char *argv[]) {
	int n;
	while(scanf("%d", &n)!=EOF){
		printf("%d\n", fast_fib(n)%100007);
	}
}