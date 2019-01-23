#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
char s[1005];
void split(char* s, vector<int>& a){
	int i = 0;
	while(i<strlen(s)){
		while(i<strlen(s)&&s[i]=='5')	i++;
		if(i==strlen(s))	break;
		int tmp = 0;
		while(i<strlen(s)&&s[i]!='5'){
			tmp = tmp*10+s[i]-'0';
			i++;
		}
		a.push_back(tmp);
	}
}
int main(int argc, char *argv[]) {
	vector<int> a;
	char c;
	int tmp = 0;
	
	while(scanf("%s", s)!=EOF){
		a.clear();
		split(s, a);
		sort(a.begin(), a.end());
		for(int i=0;i<(int)a.size()-1;i++)
			printf("%d ", a[i]);
		printf("%d\n", a[a.size()-1]);
	}
	
}