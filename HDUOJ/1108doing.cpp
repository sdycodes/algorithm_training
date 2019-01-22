#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

void get_facs(int a, map<int, int>& facs){
	
}
int main(int argc, char *argv[]) {
	int a, b;
	map<int, int> facs1, facs2;
	while(scanf("%d%d", &a, &b)!=EOF){
		get_facs(a, facs1);
		get_facs(b, facs2);
		map<int, int>::iterator it;
		for(it=facs2.begin();it!=facs2.end();it++){
			if(facs1.find(it->first)==facs1.end())
				facs1[it->first] = it->second;
			else{
				facs1[it->first] = facs1[it->first]>=it->second?facs1[it->first]:it->second;
			}
		}
		int res = 1;
		for(it=facs1.begin();it!=facs1.end();it++)
			res *= (it->first*it->second);
		printf("%d\n", res);
	}
}