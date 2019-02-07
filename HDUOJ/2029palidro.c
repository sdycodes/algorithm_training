#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[]) {
	char s[10000];
	int T;
	scanf("%d", &T);
	while(T--){
		scanf("%s", s);
		int n = strlen(s);
		int i;
		for(i=0;i<n/2;i++){
			if(s[i]!=s[n-i-1]){
				printf("no\n");
				break;
			}
		}
		if(i==n/2)	printf("yes\n");
	}
}