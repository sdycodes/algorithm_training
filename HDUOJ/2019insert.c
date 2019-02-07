#include <stdio.h>

int main(int argc, char *argv[]) {
	int n, m;
	while(scanf("%d%d", &n, &m)&&!(n==0&&m==0)){
		int insert = 0;
		int tmp;
		for(int i=0;i<n-1;i++){
			scanf("%d", &tmp);
			if(tmp<m||insert){
				printf("%d ", tmp);
			}
			else{
				printf("%d %d ", m, tmp);
				insert = 1;
			}
		}
		scanf("%d", &tmp);
		if(tmp<m||insert){
			printf("%d\n", tmp);
		}
		else{
			printf("%d %d\n", m, tmp);
			insert = 1;
		}
	}
}