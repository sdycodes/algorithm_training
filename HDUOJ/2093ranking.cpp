#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
using namespace std;
struct person{
	string name;
	int acnum;
	int time;
};

bool comp(const person a, const person b){
	if(a.acnum!=b.acnum)
		return a.acnum>b.acnum;
	else if(a.time!=b.time)
		return a.time < b.time;
	return a.name < b.name;
}
int main(int argc, char *argv[]) {
	vector<person> people;
	int n, m;
	scanf("%d%d", &n, &m);
	getchar();
	person tmp;
	while(cin>>tmp.name){
		tmp.acnum = 0;
		tmp.time = 0;
		//get n problems
		for(int cnt=0;cnt<n;cnt++){
			int i = 0;
			string s;
			cin>>s;
			if(s[i]=='0'||s[i]=='-'){
				continue;
			}
			else{
				tmp.acnum++;
				int consume = 0;
				while(i<s.size()&&s[i]!='('&&s[i]!=' '&&s[i]!='\t'){
					consume = consume*10 + (s[i]-'0');
					i++;
				}
				tmp.time += consume;
				if(i<s.size()&&s[i]=='('){
					int penal = 0;
					i++;
					while(s[i]!=')'){
						penal = penal*10 + s[i]-'0';
						i++;
					}
					tmp.time += penal*m;
				}
				i++;
			}
		}
		people.push_back(tmp);
	}
	sort(people.begin(), people.end(), comp);
	for(int i=0;i<people.size();i++){
		printf("%-10s %2d %4d\n", people[i].name.c_str(), people[i].acnum, people[i].time);
	}
}