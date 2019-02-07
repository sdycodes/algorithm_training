#include <iostream>
#include <algorithm>
bool comp(const int a, const int b){
	return abs(a)>abs(b);
}
using namespace std;
int a[105];
int main(int argc, char *argv[]) {
	int n;
	while(scanf("%d", &n)&&n!=0){
		for(int i=0;i<n;i++)
			scanf("%d", &a[i]);
		sort(a, a+n, comp);
		for(int i=0;i<n-1;i++)
			printf("%d ", a[i]);
		printf("%d\n", a[n-1]);
	}
}