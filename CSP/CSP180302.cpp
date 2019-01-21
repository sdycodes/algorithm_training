#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
int main(int argc, char *argv[]) {
	int n, L, t;
	map<int, int> mp; 
	cin>>n>>L>>t;
	vector<int> locs(n);
	for(int i=0;i<n;i++){
		cin>>locs[i];
		mp[locs[i]] = i;
	}
	sort(locs.begin(), locs.end());
	vector<int> locsmp(n);
	for(int i=0;i<n;i++){
		locsmp[i] = mp[locs[i]];
	}
	for(int i=0;i<n;i++){
		locs[i] = (locs[i]+t)%(L<<1);
		if(locs[i]>L)
			locs[i] = (L<<1) - locs[i];
	}
	sort(locs.begin(), locs.end());
	vector<int> buffer(n);
	for(int i=0;i<n;i++)
		buffer[locsmp[i]] = locs[i];
	for(int i=0;i<n;i++)
		cout<<buffer[i]<<' '; 
	return 0;
}
