#include <stdio.h>
int days[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int main(int argc, char *argv[]) {
	int T;
	scanf("%d", &T);
	while(T--) {
		int y, mon, d, h, mi, s;
		scanf("%d%d%d%d%d%d", &y, &mon, &d, &h, &mi, &s);
		int isLegal = 1;
		//judge mon
		if (mon > 12 || mon < 1) {
			isLegal = 0;
		} else {
			//judge day
			if (d > days[mon] || d <= 0) {
				isLegal = 0;
			}
			if (mon == 2 && d == 29 && !(y%400==0||(y%100!=0&&y%4==0))) {
				isLegal = 0;
			}
			//judge h mi s
			if (h >= 24 || h < 0 || mi >= 60 || mi < 0 || s >= 60 || s < 0) {
				isLegal = 0;
			}
		}
		if (isLegal) {
			printf("Good bye!\n");
		} else {
			printf("Please wait for a moment!\n");
		}
	}
}