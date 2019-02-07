#include <stdio.h>

int main(int argc, char *argv[]) {
	int T;
	scanf("%d", &T);
	while (T--) {
		int n;
		scanf("%d", &n);
		int all = 3;
		for(int i=0;i<n;i++){
			all = (all-1)*2;
		}
		printf("%d\n", all);
	}
}