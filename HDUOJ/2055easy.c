#include <stdio.h>

int main(int argc, char *argv[]){
	int T;
	scanf("%d", &T);
	while(T--){
		getchar();
		char tc;
		int t;
		scanf("%c", &tc);
		scanf("%d", &t);
		printf("%d\n", t+(tc<='Z'?tc+1-'A':'a'-tc-1));
	}
}