#include <iostream>

using namespace std;
int month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int main(int argc, char *argv[]) {
	int y, seq;
	scanf("%d%d", &y, &seq);
	if ((y % 100 != 0 && y % 4 == 0) || y % 400 == 0) {
		month[2] = 29;
	}
	int m = 1;
	while(seq > month[m]) {
		seq -= month[m];
		m++;
	}
	printf("%d\n%d", m, seq);
}