#include <stdio.h>

int main(int argc, char *argv[]) {
	int T;
	scanf("%d", &T);
	while (T--) {
		int len;
		scanf("%d", &len);
		getchar();
		char cur, pre = '\0';
		int cnt = 0;
		for (int i = 0; i < len; i++) {
			cur = getchar();
			if (cur != pre && pre != '\0') {
				printf("%d%c", cnt, pre);
				cnt = 1;
				pre = cur;
			} else {
				cnt++;
				pre = cur;
			}
		}
		printf("%d%c\n", cnt, cur);
	}
}