#include <cstdio>
#include <queue>
using namespace std;
int main(int argc, char *argv[]) {
	int n;
	while(scanf("%d", &n) != EOF) {
		priority_queue<int,vector<int>, greater<int> > q;
		for (int i = 0; i < n; i++) {
			int tmp;
			scanf("%d", &tmp);
			q.push(tmp);
		}
		int res = 0;
		while(q.size() > 1) {
			int merge = q.top();
			q.pop();
			merge += q.top();
			q.pop();
			res += merge;
			q.push(merge);
		}
		printf("%d\n", res);
	}
}