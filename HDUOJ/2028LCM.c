#include <stdio.h>

int main(int argc, char *argv[]) {
	int n;
	int a[505];
	while (scanf("%d", &n)!=EOF) {
		int maxVal = -1;
		for(int i=0;i<n;i++){
			scanf("%d", &a[i]);
			if(maxVal<a[i])	maxVal = a[i];
		}
		for(int i=0;i<n;i++){
			if(maxVal%a[i]!=0){
				i = -1;
				maxVal++;
			}
		}
		printf("%d\n", maxVal);
	}
}