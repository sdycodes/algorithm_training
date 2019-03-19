#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
	int cakes[1005];
	int n, k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>cakes[i];
	int j = 1;
	int res = 0;
	while(j<=n){
		if(cakes[j]>=k){
			res++;
			j++;
			continue;
		}
		else{
			int sum = 0;
			while(j<=n&&sum<k){
				sum += cakes[j];
				j++;
			}
			res++;
		}
	}
	cout<<res;
}