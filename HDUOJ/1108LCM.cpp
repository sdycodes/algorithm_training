#include <iostream>
#include <cstdio>
#include <map>
#include <cmath>
using namespace std;

bool isPrime(int n){
	if(n==2)	return true;
	for(int i=2;i<=(int)sqrt(n)+1;i++)
		if(n%i==0)	return false;
	return true;
}

void get_facs(int a, map<int, int>& facs){
	facs.clear();
	for(int i=2;i<=a;i++){
		if(isPrime(i)&&a%i==0){
			int cnt = 0;
			while(a%i==0){
				a /= i;
				cnt++;
			}
			facs[i] = cnt;
		}
	}
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
			else
				facs1[it->first] = facs1[it->first]>=it->second?facs1[it->first]:it->second;
		}
		int res = 1;
		for(it=facs1.begin();it!=facs1.end();it++){
			for(int i=1;i<=it->second;i++)
				res *= it->first;
		}
		printf("%d\n", res);
	}
}