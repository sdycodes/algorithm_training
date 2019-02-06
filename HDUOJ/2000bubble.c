#include <stdio.h>

int main(int argc, char *argv[]) {
	char a[3];
	char t;
	while(scanf("%c%c%c", &a[0], &a[1], &a[2])!=EOF){
		for(int i=0;i<2;i++){
			for(int j=i+1;j<3;j++){
				if(a[i]>a[j]){
					t = a[i];
					a[i] = a[j];
					a[j] = t;
				}
			}
		}
		printf("%c %c %c\n", a[0], a[1], a[2]);
		getchar();
	}
	return 0;
}