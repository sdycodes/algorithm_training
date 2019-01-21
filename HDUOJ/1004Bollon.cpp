#include <iostream>
#include <map>
#include <string>
#include <cstring>

using namespace std;
int main(int argc, char *argv[]) {
	map<string, int> cnt;
	int N, i, max;
	char * tmp[20];
	string s;
	string rec;
	while(1){
		scanf("%d", &N);
		if(N==0)	break;
		max = 0;
		cnt.clear();
		for(i=0;i<N;i++){
			s.clear();	//can't missing
			s.resize(20);
			scanf("%s", &s[0]);
			getchar();
			if(cnt.find(s)!=cnt.end()){
				cnt[s]++;
			}
			else cnt[s] = 1;
			if(max<cnt[s]){
				max = cnt[s];
				rec = s;
			}
		}
		printf("%s\n", rec.c_str());
	}
}