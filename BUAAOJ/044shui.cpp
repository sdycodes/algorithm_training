#include <cstdio>

using namespace std;
void swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
int main(int argc, char *argv[]) {
	int a, b;
	while(scanf("%d%d", &a, &b)!=EOF) {
		swap(&a, &b);
		printf("%d %d\n", a, b);
	}
}