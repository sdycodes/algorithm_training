#include <iostream>
#include <stack>
#include <string>
#include <map>
using namespace std;
int main(int argc, char *argv[]) {
	//int m, n;
	//cin>>n>>m;
	char s[200];
	map<string, string> mp;
	memset(s, 0, sizeof(s));
	string total = "";
	while(cin.getline(s, 180)){
		total += s;
	}
	while(!total.empty()){
		total = total.substr(1, total.length()-2);
		int pos = total.find_first_of(',');
		string cur_pair;
		if(pos!=-1)
			cur_pair = total.substr(0, pos);
		pos = cur_pair.find(':');
		string key = cur_pair.substr(0, pos);
		string value = cur_pair.substr(pos + 1);
		mp[key] = value;
		total = total.substr(pos + 1);
	}
	
}