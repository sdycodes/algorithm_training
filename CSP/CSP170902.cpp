#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
struct Node{
	int time, num;
};

bool comp(const Node &a, const Node &b) {
	if (a.time < b.time) {
		return true;
	} else if (a.time == b.time){
		if (a.num < 0 && b.num < 0) {
			return a.num > b.num;
		} else {
			return a.num < b.num;
		}
	}
	return false;
}

Node op[2005];
int box[1005];

int main(int argc, char *argv[]) {
	freopen("./data.in", "r", stdin);
	int N, K;
	scanf("%d%d", &N, &K);
	int w, s, c;
	for (int i = 1; i <= N; i++) {
		box[i] = i;
	}
	int cnt = 0;
	for (int i = 0; i < K; i++) {
		scanf("%d%d%d", &w, &s, &c);
		op[cnt].num = w;
		op[cnt++].time = s;
		op[cnt].num = -w;
		op[cnt++].time = s + c;
	}
	sort(op, op + cnt, comp);
	for (int i = 0; i < cnt; i++) {
		if (op[i].num < 0) {
			//还
			for (int j = 1; j <= N; j++) {
				if (box[j] == 0) {
					box[j] = -op[i].num;
					break;
				}
			}
		} else {
			//取
			for (int j = 1; j <= N; j++) {
				if (box[j] == op[i].num) {
					box[j] = 0;
					break;
				}
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		printf("%d ", box[i]);
	}
	return 0;
}