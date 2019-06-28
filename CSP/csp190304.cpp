#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	int a[10005][11];
	char s[5000];
	int T, n;
	scanf("%d", &T);
	scanf("%d", &n);
	getchar();
	while(T--) {
		char op;
		int no;
		for (int i = 0; i < n; i++) {
			int cnt = 0;
			do {
				scanf("%c%d", &op, &no);
				if (op == 'R') {
					a[i][cnt++] = -1 * no - 1;
				} else {
					a[i][cnt++] = no + 1;
				}
			} while (getchar() != '\n');
			a[cnt] = 0;
			a[i][10] = cnt;
			a[i][9] = 0;
		}
		int msg[10005][11];
		memset(msg, 0, sizof(msg));
		for (int i = 0; i < n; i++) {
			int j = 0;
			while(j < a[i][10] && a[i][j] > 0) {
				msg[a[i][j] - 1][msg[10]++] = i;
			}
		}
		for (int i = 0; i < n; i++) {
			bool step = true;
			while(step) {
				step = false;
				
			}
		}
		
	}
}