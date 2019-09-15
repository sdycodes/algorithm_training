#include <cstdio>
int r, y, g;

long long get_time(long long cur, int type, int duration) {
	int T = r + y + g;
	int cur_s;
	if (type == 1) cur_s = r - duration;
	else if (type == 3) cur_s = r + g - duration;
	else cur_s = T - duration;
	int fu_s = (cur_s + cur % T) % T;
	if (fu_s < r) return r - fu_s;
	else if (fu_s >= r && fu_s < r + g) return 0;
	else return T - fu_s + r;
}

int main() {
	#ifdef D
		freopen("data.in", "r", stdin);
	#endif
	int k;
	scanf("%d%d%d%d", &r, &y, &g, &k);
	long long res = 0;
	for (int i = 0; i < k; i++) {
		int t, d;
		scanf("%d%d", &t, &d);
		if (t == 0) res += d;
		else res += get_time(res, t, d);
	}
	printf("%lld\n", res);
	return 0;
}