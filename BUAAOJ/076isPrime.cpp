#include <cstdio>
#include <cmath>
using namespace std;
bool isPrime(long long n) {
	if (n <= 3) {
		return n - 1 > 0;
	}
	if ((n - 1)%6 != 0 && (n+1)%6 != 0) {
		return false;
	}
	for (int i = 5; i < sqrt(n) + 1; i += 6) {
		if (n % i == 0 || n % (i + 2) == 0) {
			return false;
		}
	}
	return true;
}
int main(int argc, char *argv[]) {
	long long n;
	while(scanf("%lld", &n) != EOF) {
		if (isPrime(n)) {
			printf("jhljx is good!\n");
		} else {
			printf("jhljx is sangxinbingkuang!\n");
		}
	}
}