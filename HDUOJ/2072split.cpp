#include <iostream>
#include <string>
#include <set>
using namespace std;
int main(int argc, char *argv[]) {
	string s;
	while(getline(cin, s)&&s[0]!='#'){
		set<string> words;
		int i = 0;
		while(i<s.size()){
			while(i<s.size()&&s[i]==' ')
				i++;
			if(i==s.size())	break; //very important
			int j = i+1;
			while(j<s.size()&&s[j]!=' ')
				j++;
			words.insert(s.substr(i, j-i));
			i = j+1;
		}
		printf("%lu\n", words.size());
	}
}