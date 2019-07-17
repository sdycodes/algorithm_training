#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
	int val, cnt;
};
Node a[1005];
bool comp(const Node &a, const Node &b) {
	if (a.cnt > b.cnt) {
		return true;
	} else if (a.cnt == b.cnt) {
		return a.val < b.val;
	}
	return false;
}
int main(int argc, char *argv[]) {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < 1005; i++) {
		a[i].val = i;
		a[i].cnt = 0;
	}
	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		a[tmp].cnt++;
	}
	sort(a, a + 1005, comp);
	for (int i = 0; i < 1005; i++) {
		if (a[i].cnt > 0) {
			printf("%d %d\n", a[i].val, a[i].cnt);
		}
	}
	return 0;
}