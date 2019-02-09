#include <stdio.h>

int main(int argc, char *argv[]) {
	int T;
	scanf("%d", &T);
	while(T--){
		int AH, AM, AS, BH, BM, BS;
		scanf("%d%d%d%d%d%d", &AH, &AM, &AS, &BH, &BM, &BS);
		int RS = (AS + BS)%60;
		int RM = (AM + BM + (AS + BS)/60)%60;
		int RH = (AH + BH + (AM + BM + (AS + BS)/60)/60);
		printf("%d %d %d\n", RH, RM, RS);
	}
}