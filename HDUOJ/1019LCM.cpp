#include <iostream>
#include <map>
#include <cmath>

using namespace std;

bool isPrime(int n){
	if(n==2) return true;
	for(int i=2;i<=(int)sqrt(n)+1;i++)
		if(n%i==0)	return false;
	return true;
}

void primeFac(int n, map<int, int>& res){	
	int i = 2;
	while(n!=1){
		if(n%i==0){
			if(res.find(i)==res.end())	res[i] = 1;
			else	res[i]++;
			n/=i;
		}
		else{
			do{
				i++;
			}while(!isPrime(i));
		}
	}
}
int main(int argc, char *argv[]) {
	map<int, int> facs;
	map<int, int> res;
	/*
	primeFac(10296, res);
	for(map<int, int>::iterator it=res.begin();it!=res.end();it++){
		printf("!!!%d  %d&&", it->first, it->second);
		//ans *= (it->first*it->second);
	}*/

	
	
	int T, n, tmp;
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		res.clear();
		for(int i=0;i<n;i++){
			facs.clear();
			scanf("%d", &tmp);
			primeFac(tmp, facs);
			for(map<int, int>::iterator it=facs.begin();it!=facs.end();it++){
				if(res.find(it->first)==res.end())	res[it->first] = facs[it->first];
				else 	res[it->first] = res[it->first]>it->second?res[it->first]:it->second;
				//printf("!!!%d  %d&&", i, i);
			}
		}
		int ans = 1;
		for(map<int, int>::iterator it=res.begin();it!=res.end();it++){
			//printf("!!!%d  %d&&", it->first, it->second);
			ans *= ((int)pow(it->first, it->second));
		}
		printf("%d\n", ans);
	}
	return 0;
}