#include <iostream>
#include <stack>
using namespace std;
int main(int argc, char *argv[]) {
	int a[4];
	char op[3];
	int T;
	scanf("%d", &T);
	while(T--) {
		scanf("%d%c%d%c%d%c%d", &a[0], &op[0], &a[1], &op[1], &a[2], &op[2], &a[3]);
		stack<int> q;
		stack<char> p;
		for (int i = 0; i < 7; i++) {
			if (i % 2 == 0) {
				int idx = i / 2;
				if (p.empty() || (!p.empty() && (p.top() == '+' || p.top() == '-'))) {
					q.push(a[idx]);
				} else {
					char o = p.top();
					p.pop();
					int x = q.top();
					q.pop();
					int y = a[idx];
					if (o == 'x') {
						q.push(x * y);
					} else {
						q.push(x / y);
					}
				}
			} else {
				int idx = (i - 1) / 2;
				p.push(op[idx]);
			}
		}
		stack<int>  iq;
		stack<char> ip;
		while(!q.empty()) {
			iq.push(q.top());
			q.pop();
		}
		while(!p.empty()) {
			ip.push(p.top());
			p.pop();
		}
		while(!ip.empty()) {
			char o = ip.top();
			ip.pop();
			int x = iq.top();
			iq.pop();
			int y = iq.top();
			iq.pop();
			if (o == '+') {
				iq.push(x + y);
			} else {
				iq.push(x - y);
			}
		}
		//printf("%d\n", iq.top());
		if (iq.top() == 24) {
			printf("Yes\n");
		} else {
			printf("No\n");
		}
	}
	return 0;
}