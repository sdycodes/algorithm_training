#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	string s;
	while(cin>>s) {
		int dashi[3], cnt = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '-') {
				dashi[cnt++] = i;
			}
		}
		string code = s.substr(dashi[2] + 1);
		int tar = 0;
		if (code == "X") {
			tar = 10;
		} else {
			tar = code[0] - '0';
		}
		int base = 1;
		int sum = 0;
		for (int i = 0; i < dashi[2]; i++) {
			if (s[i] != '-') {
				sum = (sum + ((s[i] - '0') * (base++))%11)%11;
			}
		}
		if (sum == tar) {
			cout<<"Right"<< endl;
		} else {
			if (sum  < 10) {
				cout<<s.substr(0, dashi[2] + 1) << to_string(sum)<<endl;
			} else {
				cout<<s.substr(0, dashi[2] + 1) <<"X"<<endl;
			}
		}
	}
	return 0;
}