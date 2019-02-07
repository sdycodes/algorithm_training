#include <stdio.h>

int main(int argc, char *argv[]) {
	int n;
	int a[105];
	while(scanf("%d", &n)&&n!=0){
		int minVal = 0x7FFFFFFF;
		int minIdx = -1;
		int tmp, i;
		for(i=0;i<n;i++){
			scanf("%d", &(a[i]));
			if(a[i]<minVal){
				minVal = a[i];
				minIdx = i;
			}
		}
		tmp = a[0];
		a[0] = a[minIdx];
		a[minIdx] = tmp;
		
		for(i=0;i<n-1;i++){
			printf("%d ", a[i]);
		}
		printf("%d\n", a[n-1]);
	}
}