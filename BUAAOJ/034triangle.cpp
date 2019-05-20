#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	int a, b, c;
	while(scanf("%d%d%d", &a, &b, &c) != EOF) {
		if (a + b > c && a + c > b && b + c > a) {
			if (a == b || a == c || b == c) {
				printf("perfect\n");
			} else if (a * a + b * b == c * c || a * a + c * c == b * b || b * b + c * c == a * a) {
				printf("good\n");
			} else {
				printf("just a triangle\n");
			}
		} else {
			printf("wrong\n");
		}
	}
}