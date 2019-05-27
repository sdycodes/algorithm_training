#include <iostream>

using namespace std;
int month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string weekday[7] = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
int main(int argc, char *argv[]) {
	int days;
	while(scanf("%d", &days) != EOF) {
		int years = (days - 1)/365;
		int cur = 2000 + years;
		int rem = days - years * 365;
		int run = 0;
		for (int i = 2000; i < cur; i++) {
			if (i % 400 == 0 || (i % 4 == 0 && i % 100 != 0)) {
				run++;
			}
		}
		rem -= run;
		while (rem < 0) {
			int last = cur - 1;
			rem += (last % 400 == 0 || (last % 4 == 0 && last % 100 != 0)) ? 366 : 365;
			cur--;
		}
		if (cur % 400 == 0 || (cur % 4 == 0 && cur % 100 != 0)) {
			month[2]++;
		}
		int i;
		int rrem = rem;
		for (i = 1; i <= 12; i++) {
			rrem -= month[i];
			if (rrem < 0) {
				break;
			}
		}
		int cur_month = i;
		rem = rrem + month[cur_month];
		printf("%4d-%02d-%02d %s\n", cur, cur_month, rem + 1, weekday[days%7].c_str());
		month[2] = 28;
	}
}