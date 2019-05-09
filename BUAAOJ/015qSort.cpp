#include <iostream>

using namespace std;
#define MAXN 1000005
int a[MAXN];
void quickSort(int low, int high) {
	if (low < high) {
		int choice = rand()%(high - low + 1) + low;
		int tmp = a[low];
		a[low] = a[choice];
		a[choice] = tmp;
		int r = a[low];
		int j = high, i = low;
		while(i < j) {
			while(a[j] >= r && i < j)
				j --;
			while(a[i] <= r && i < j)
				i++;
			int tmp = a[j];
			a[j] = a[i];
			a[i] = tmp;
		}
		a[low] = a[i];
		a[i] = r;
		int pivot = i;
		quickSort(low, pivot - 1);
		quickSort(pivot + 1, high);
	}
	return;
}


int main(int argc, char *argv[]) {
	int n;
	while(scanf("%d", &n) != EOF) {
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		quickSort(0, n - 1);
		for (int i = 0; i < n; i++) {
			printf("%d ", a[i]);
		}
		printf("\n");
	}
}