#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	int n;
	while(scanf("%d", &n) != EOF) {
		n += 2;
		while (n % 5 ==0) {
			n /= 5;
		}
		while (n % 3 == 0) {
			n /= 3;
		}
		if (n == 1) {
			printf("Yes\n");
		} else {
			printf("No\n");
		}
	}	
	return 0;
}