#include <stdio.h>

int main(int argc, char *argv[]) {
	int T;
	scanf("%d", &T);
	while(T--){
		int n;
		float maxh = 0, tmp;
		scanf("%d", &n);
		for(int i=0;i<n;i++){
			scanf("%f", &tmp);
			if(tmp-maxh>0.005)
				maxh = tmp;
		}
		printf("%.2f\n", maxh);
	}
}