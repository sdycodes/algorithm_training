#include <stdio.h>

int main(int argc, char *argv[]) {
	int T;
	char s[12];
	scanf("%d", &T);
	while(T--){
		getchar();
		scanf("%s", s);
		printf("6%c%c%c%c%c\n", s[6], s[7], s[8], s[9], s[10]);
	}
}