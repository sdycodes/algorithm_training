#include <cstdio>

using namespace std;
void nextday(int y, int m, int d) {
	d++;
	if (d == 32) {
		m++;
		d = 1;	
	} else if (d == 31) {
		if ((m % 2 == 1 && m != 9 && m != 11) || (m % 2 == 0 && (m == 8 || m == 10 ||m == 12))) {
			printf("%d %d %d\n", y, m, d);
			return;
		} else {
			m++;
			d = 1;
		}
	} else if (d == 30) {
		if (m == 2) {
			m++;
			d = 1;
		} else {
			printf("%d %d %d\n", y, m, d);
			return;
		}
	} else if (d == 29) {
		if (m ==2) {
			if (y%400 == 0 || (y % 100 != 0 && y % 4 == 0)) {
				printf("%d %d %d\n", y, m, d);
				return;
			} else {
				m++;
				d = 1;
			}
		} else {
			printf("%d %d %d\n", y, m, d);
			return;
		}
	}
	if (m == 13) {
		m = 1;
		y++;
	} 
	printf("%d %d %d\n", y, m, d);
}
int main(int argc, char *argv[]) {
	int n;
	scanf("%d", &n);
	while(n--) {
		int y, m, d;
		scanf("%d%d%d", &y, &m, &d);
		if (d > 31 || d <= 0 || m > 12 || m <= 0){
			printf("QWQ\n");
		}
		else {
			if (d == 31) {
				if ((m % 2 == 1 && m != 9 && m != 11) || (m % 2 == 0 && (m == 8 || m == 10 || m == 12))) {
					nextday(y, m, d);
				} else {
					printf("QWQ\n");
				}
			} else if (d == 30) {
				if (m == 2) {
					printf("QWQ\n");
				} else {
					nextday(y, m, d);
				}
			} else if (d == 29) {
				if (m == 2) {
					if (y%400 == 0 || (y % 100 != 0 && y % 4 == 0)) {
						nextday(y, m, d);
					} else {
						printf("QWQ\n");
					}	
				} else {
					nextday(y, m, d);
				}
			} else {
				nextday(y, m, d);
			}
		}
	}
}