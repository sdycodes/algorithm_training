#include <cstdio>
#include <algorithm>
#include <random>

using namespace std;
int a[1000005];
bool comp(const int &a, const int &b) {
	return a > b;
}

int find_pivot(int r, int begin, int end) {
	int i = begin, j = end;
	while(i < j) {
		while(a[j] <= r && i < j) {
			j--;
		}
		while(a[i] >= r && i < j) {
			i++;
		}
		int tmp = a[i];
		a[i] = a[j];
		a[j] = tmp;
	}
	a[begin] = a[i];
	a[i] = r;
	return i;
}

//solution1
int findK_by_sort(int k, int n) {
	sort(a, a + n, comp);
	return a[k - 1];
}

//solution2
int findK_by_quick(int begin, int end, int k) {
	if (begin == end) return a[begin];
	int mid = (begin + end) >> 1;
	int choice = begin + random() % (end - begin + 1);
	int r = a[choice];
	a[choice] = a[begin];
	a[begin] = r;
	int i = find_pivot(r, begin, end);
	if (i == k) {
		return a[i];
	} else if (i > k){
		return findK_by_quick(begin, i - 1, k);
	} else {
		return findK_by_quick(i + 1, end, k);
	}
}

//solution3 find_by_mid
//冒泡排序 对不超过5个数排序
void normal_sort(int begin, int end) {
	for (int i = begin; i < end; i++) {
		for (int j = i + 1; j < end; j++) {
			if (a[i] < a[j]) {
				int tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}
	}
}
//寻找中位数算法
int find_mid(int begin, int end) {
	if (begin == end) return a[begin];
	int i;
	for (i = begin; i < end - 5; i += 5) {
		normal_sort(i, i + 5);
		//这里有个省内存的小技巧，直接把中位数已到begin的位置，因为a的顺序不重要
		int tmp = a[i + 2];
		a[i + 2] = a[begin + (i - begin) / 5];
		a[begin + (i - begin) / 5] = tmp;
	}
	int surplus = (end - i + 1);
	int n = 0;
	//不是5的倍数，剩下的也排序，注意这个n的作用是记录到底有多少个中位数需要在下一轮排序
	//如果surplus不是0，说明多一个 起到上取整的作用
	if (surplus) {
		normal_sort(i, i + surplus);
		int tmp = a[i + surplus / 2];
		a[i + surplus / 2] = a[begin + (i - begin) / 5];
		a[begin + (i - begin) / 5] = tmp;
		n += 1;
	}
	if (n + (i - begin)/ 5 <= 1) return a[begin];
	else return find_mid(begin, n + begin + (i - begin) / 5);
}
int findK_by_mid(int begin, int end, int k) {
	if (begin == end) return a[begin];
	//找到中位数
	int mid = find_mid(begin, end);
	//反向查找位置
	int i;
	for (i = begin; i <= end; i++) {
		if (a[i] == mid) {
			break;
		}
	}
	//和快排一样了。。。
	int r = a[i];
	a[i] = a[begin];
	a[begin] = r;
	int p = find_pivot(r, begin, end);
	if (p == k) return a[k];
	else if (p > k) return findK_by_mid(begin, p - 1, k);
	else return findK_by_mid(p + 1, end, k);
}

int main(int argc, char *argv[]) {
	int n, k;
	while(scanf("%d%d", &n, &k) != EOF) {
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		//printf("%d\n", findK_by_sort(k, n));
		//printf("%d\n", findK_by_quick(0, n - 1, k - 1));
		printf("%d\n", findK_by_mid(0, n - 1, k - 1));
	}
	return 0;
}