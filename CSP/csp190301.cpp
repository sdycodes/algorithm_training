#include <iostream>
using namespace std;
int main(int argc, char *argv[]) {
	int a[100005];
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	long long mid;
	if (n % 2 == 1) {
		mid = a[n / 2 + 1] * 2;
	} else {
		mid = (a[n / 2] + a[n / 2 + 1]);
	}
	if (mid % 2 == 0) {
		if (a[n] > a[1]) {
			printf("%d %d %d\n", a[n], mid / 2, a[1]);
		} else {
			printf("%d %d %d\n", a[1], mid / 2, a[n]);
		}
	} else {
		if (a[n] > a[1]) {
			printf("%d %.1f %d\n", a[n], mid / 2.0, a[1]);
		} else {
			printf("%d %.1f %d\n", a[1], mid / 2.0, a[n]);
		}
	}
}