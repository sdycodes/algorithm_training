#include <cstdio>
#include <cmath>
#include <algorithm>
#define INF 1e50
using namespace std;
struct node {
	double x, y;
	int cls;
};
node a[200005], tmp[200005];

bool compareX(const node &a, const node &b) {
	return a.x < b.x;
}

double distance(node a, node b) {
	if (a.cls == b.cls) {
		return INF;
	} 
	return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

double closePair(int left, int right) {
	if (left >= right) {
		return INF;
	}
	int mid = (left + right) >> 1;
	double cut = a[mid].x;  //注意这里必须要提前记录  因为后面排序这个值可能变
	double dist = fmin(closePair(left, mid), closePair(mid + 1, right));
	//要实现nlogn，在这里merge
	//在这里merge可以直接修改a，因为两侧按x分治已经做过了，cut已经记录，没有必要再维护x的顺序  
	int l = left, r = mid + 1, cnt = 0;
	while(l <= mid && r <= right) {
		if (a[l].y <= a[r].y) {
			tmp[cnt++] = a[l++];
		} else {
			tmp[cnt++] = a[r++];
		}
	}
	while(l <= mid) {
		tmp[cnt++] = a[l++];
	}
	while(r <= right) {
		tmp[cnt++] = a[r++];
	}
	for (int i = 0; i < cnt; i++) {
		a[left + i] = tmp[i];
	}
	// merge完成
	cnt = 0;
	for (int i = left; i <= right; i++) {
		if (fabs(a[i].x - cut) <= dist) {
			tmp[cnt++] = a[i];
		}
	}
	for (int i = 0; i < cnt; i++) {
		for (int j = i + 1; j < cnt; j++) {
			if (tmp[i].y - tmp[j].y > dist) {
				break;
			}
			dist = fmin(dist, distance(tmp[i], tmp[j]));
		}
	}
	return dist;
}

int main(int argc, char *argv[]) {
	int T;
	scanf("%d", &T);
	while(T--) {
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%lf%lf", &a[i].x, &a[i].y);
			a[i].cls = 0;
		}
		for (int i = n; i < 2*n; i++) {
			scanf("%lf%lf", &a[i].x, &a[i].y);
			a[i].cls = 1;
		}
		sort(a, a + 2 * n, compareX);
		printf("%.3f\n", closePair(0, 2*n - 1));
	}
}