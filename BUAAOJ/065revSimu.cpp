#include <cstdio>
#include <queue>
using namespace std;
int main(int argc, char *argv[]) {
	int n;
	while(scanf("%d", &n) != EOF) {		
		priority_queue<int> q;
		for (int i = 0; i < n; i++) {
			int tmp;
			scanf("%d", &tmp);
			q.push(tmp);
		}
		int k;
		scanf("%d", &k);
		int res = 0;
		while(q.top() > res) {
			int tmp = q.top();
			q.pop();
			q.push(tmp - k + 1);
			res++;
		}
		printf("%d\n", res);
	}
	return 0;
}