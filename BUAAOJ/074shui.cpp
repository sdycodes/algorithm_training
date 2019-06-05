#include <cstdio>
#include <cstring>
using namespace std;
int main(int argc, char *argv[]) {
	char s[200];
	while(scanf("%s", s) != EOF) {
		int colon[2];
		int coloncnt = 0;
		bool isLegal = true;
		if (strlen(s) > 8) {
			printf("No\n");
			continue;
		}
		for (int i = 0; i < strlen(s); i++) {
			if (s[i] == ':') {
				if (coloncnt == 2) {
					isLegal = false;
				} else {
					colon[coloncnt++] = i;
				}
			} else if (!(s[i] >= '0' && s[i] <= '9')) {
				isLegal = false;
			}
		}
		if (coloncnt != 2) {
			isLegal = false;
		}
		if (!isLegal) {
			printf("No\n");
			continue;
		}
		if (colon[0] > 2 || colon[1] - colon[0] - 1 != 2 || strlen(s) - colon[1] - 1 != 2) {
			printf("No\n");
			continue;
		}
		if (colon[0] == 2 && s[0] == '0') {
			printf("No\n");
			continue;
		}
		int h = -1, m = -1, sec = -1;
		if (colon[0] > 0) {
			h = 0;
			for (int i = 0; i < colon[0]; i++) {
				h = h * 10 + (s[i] - '0');
			}
		}
		if (colon[1] > colon[0] + 1) {
			m = 0;
			for (int i = colon[0] + 1; i < colon[1]; i++) {
				m = m * 10 + (s[i] - '0');
			}
		}
		if (colon[1] < strlen(s)) {
			sec = 0;
			for (int i = colon[1] + 1; i < strlen(s); i++) {
				sec = sec * 10 + (s[i] - '0');
			}
		}
		if (h >= 0 && h < 24 && m >= 0 && m < 60 && sec >= 0 && sec < 60) {
			printf("Yes\n");
		} else {
			printf("No\n");
		}
	}	
}