#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;

int dfs(int a,int b) {
	int smaller = a, larger = b;
	if (smaller > larger) {
		int tmp = smaller;
		smaller = larger;
		larger = tmp;
	}
	if (smaller == 0) {
		return 0;
	}
	//这个循环顺序一定是倒序的，因为正常情况下就不会走这个循环，一定是尽可能减去较大的值
	for (int k = larger / smaller; k > 0; k--) {
		if (dfs(larger - k * smaller, smaller) == 0) {
			return 1;
		}
	}
	return 0;
}

int main() {
	int a, b;
	// 本质是辗转相除过程的记录
	while (scanf("%d %d", &a, &b) != EOF) {
		if (dfs(a,b) == 1) {
			printf("Nova\n");
		} else {
			printf("LaoWang\n");
		}
	}
	return 0;
}