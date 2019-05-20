#include <cstdio>
#include <cmath>
using namespace std;

bool isPrime(int n) {
	if (n <= 3) {
		return (n-1) > 0;
	}
	if (n % 6 != 1 &&n % 6 != 5) {
		return false;
	}
	for (int i = 5; i < (int)sqrt(n) + 1; i+=6) {
		if (n % i == 0 || n % (i + 2) == 0) {
			return false;
		}
	}
	return true;
}

//质数模版 稳得一批
int main(int argc, char *argv[]) {
	int N;
	scanf("%d", &N);
	while(N--) {
		int n;
		scanf("%d", &n);
		if (isPrime(n)) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
