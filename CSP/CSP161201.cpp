#include <iostream>

using namespace std;
int a[1005];
int main(int argc, char *argv[]) {
	int n;
	cin>>n;
	int i;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(i=0;i<n;i++){
		int bigger = 0, smaller = 0;
		for(int j=0;j<n;j++){
			if(j!=i){
				if(a[i]>a[j])
					smaller ++;
				else if(a[i]<a[j])
					bigger ++;
			}
		}
		if(bigger==smaller){
			cout<<a[i];
			break;
		}
	}
	if(i==n)
		cout<<"-1";
	return 0;
}