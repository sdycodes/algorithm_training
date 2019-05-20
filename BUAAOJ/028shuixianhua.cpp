#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
	int T;
	int a[4] = {153, 370, 371, 407};
	scanf("%d", &T);
	while(T--) {
		int l, r;
		scanf("%d%d", &l, &r);
		bool hasout = false;
		for (int i = 0; i < 4; i++) {
			if (a[i]<=r && a[i] >= l) {
				hasout = true;
				printf("%d ", a[i]);
			}
		}
		if (!hasout) {
			printf("-1");
		} 
		printf("\n");
	}
	return 0;
}