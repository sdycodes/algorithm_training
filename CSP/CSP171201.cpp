#include <iostream>
#include <algorithm>
int min(int a, int b){
	return a<b?a:b;
}
using namespace std;
int a[1000];
int main(int argc, char *argv[]) {
	int n;
	cin>>n;
	int res = INT_MAX;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a, a+n);
	for(int i=1;i<n;i++){
			res = min(abs(a[i-1]-a[i]), res);
	}
	cout<<res;
	return 0;
}