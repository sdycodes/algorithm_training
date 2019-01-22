#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
int a[1005];

void quick_sort(int l, int r){
	if(l<r){
		int t;
		int choose = l + rand()%(r-l+1);
		t = a[l];
		a[l] = a[choose];
		a[choose] = t;
		int rec = a[l];
		int i = l, j = r;
		while(i<j){
			while(a[j]>=rec&&i<j)
				j--;
			while(a[i]<=rec&&i<j)
				i++;
			t = a[i];
			a[i] = a[j];
			a[j] = t;
		}
		a[l] = a[i];
		a[i] = rec;
		int pivot = i;
		quick_sort(l, pivot-1);
		quick_sort(pivot+1, r);
	}
}
int main(int argc, char *argv[]) {
	int T, n;
	srand(time(NULL));
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		for(int i=0;i<n;i++){
			scanf("%d", &(a[i]));
		}
		quick_sort(0, n-1);
		for(int i=0;i<n-1;i++)
			printf("%d ", a[i]);
		printf("%d\n", a[n-1]);
	}
}