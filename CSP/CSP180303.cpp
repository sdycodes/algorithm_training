#include <iostream>
#include <stdio.h>
#include <vector>
#include <map>
#include <string>
using namespace std;
vector<string> split(string s, char c){
	    vector<string> sub;
    int i = s[0]==c?1:0;
    while(i<s.length()){
        int j = i+1;
        while(j<s.length()&&s[j]!=c)
            j++;
        string t = s.substr(i, j-i);
        sub.push_back(t);
        i = j+1;
    }
    return sub;
}
string noLeadingZero(string s){
	int i = 0;
	while(i<s.length()&&s[i]=='0')
		i++;
	return s.substr(i);
}
bool allNum(string s){
	for(int i=0;i<s.length();i++)
		if(!(s[i]>='0'&&s[i]<='9'))
			return false;
	return true;
}
bool legalURL(string s){
	for(int i=0;i<s.length();i++){
		if(!(
			(s[i]>='0'&&s[i]<='9')||
			(s[i]>='a'&&s[i]<='z')||
			(s[i]>='A'&&s[i]<='Z')||
			(s[i]=='/'||s[i]=='_'||s[i]=='.'||s[i]=='-')
		))
			return false;
	}
	return true;
}
int main(){
	int n, m;
	scanf("%d%d\n", &n, &m);
	vector<vector<string> > patterns;
	vector<string> names;
	for(int i=0;i<n;i++){
		string input;
		getline(cin, input);
		vector<string> tmp = split(input, ' ');
		names.push_back(tmp[1]);
		patterns.push_back(split(tmp[0], '/'));
	}
	for(int i=0;i<m;i++){
		string tar;
		getline(cin, tar);
		if(!legalURL(tar)){
			cout<<"404"<<'\n';
			continue;
		}
		vector<string> segs = split(tar, '/');
		int j;
		for(j=0;j<n;j++){
			int k;
			vector<string> attr;
			for(k=0;k<segs.size();k++){
				if(k<patterns[j].size()&&segs[k]==patterns[j][k])
					continue;
				if(allNum(segs[k])&&k<patterns[j].size()&&patterns[j][k]=="<int>"){
					attr.push_back(noLeadingZero(segs[k]));
					continue;
				}
				if(k<patterns[j].size()&&patterns[j][k]=="<str>"){
					attr.push_back(segs[k]);
					continue;
				}
				if(k<patterns[j].size()&&patterns[j][k]=="<path>"){
					string p;
					while(k<segs.size()-1){
						p += (segs[k]+'/');
						k++;
					}
					p += segs[k];
					attr.push_back(p);
					continue;
				}
				break;
			}
			if(k<segs.size())
				continue;
			else{
				cout<<names[j];
				for(int w=0;w<attr.size();w++)
					cout<<' '<<attr[w];
				cout<<'\n';
				break;
			}
		}
		if(j==n)
			cout<<"404"<<'\n';	
	}
	return 0;
}

