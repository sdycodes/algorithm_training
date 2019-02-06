#include <stdio.h>

int main(int argc, char *argv[]) {
	int n;
	while(scanf("%d", &n)!=EOF){
		int res = 1;
		int tmp;
		for(int i=0;i<n;i++){
			scanf("%d", &tmp);
			if(tmp%2==1)
				res *= tmp;
		}
		printf("%d\n", res);
	}
	return 0;
}