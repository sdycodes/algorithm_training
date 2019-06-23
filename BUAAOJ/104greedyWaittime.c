#include <stdio.h>
#include <time.h>
#include  <stdlib.h>
#define  MAXN 10005
void quick_sort(int a[], int begin, int end) {
	if (begin < end) {
		int x = rand()%(end - begin + 1);
		int r = a[begin + x];
		a[begin + x] = a[begin];
		a[begin] = r;
		int i = begin, j = end;
		while (i < j) {
			while(a[j] >= r && i < j) {
				j--;
			}
			while (a[i] <= r && i < j) {
				i++;
			}
			int tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
		}
		a[begin] = a[i];
		a[i] = r;
		quick_sort(a, begin, i - 1);
		quick_sort(a, i + 1, end);
	}
}
int main(int argc, char *argv[]) {
	int N;
	srand(time(NULL));
	int a[MAXN];
	while(scanf("%d", &N) != EOF) {
		for (int i = 0; i < N; i++)  {
			scanf("%d", &a[i]);
		}
		quick_sort(a, 0, N - 1);
		long long res = 0;
		for (int i = 0; i < N; i++) {
			res += (a[i] * (N-i-1));
		}
		printf("%lld\n", res);
	}
	return 0;
}