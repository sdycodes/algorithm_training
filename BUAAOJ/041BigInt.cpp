#include <cstdio>
#include <string>
#include <iostream>
#include <cstring>
#define L 100005
using namespace std;

string mult(string a, string b) {
	int signa = 1, signb = 1;
	if (a[0] == '-') {
		signa = -1;
	}
	if (a[0] == '+' || a[0] == '-') {
		a = a.substr(1);
	}
	if (b[0] == '-') {
		signb = -1;
	}
	if (b[0] == '+' || b[0] == '-') {
		b = b.substr(1);
	}
	int signres = signa * signb;
	int diga[L];
	int digb[L];
	int res[2*L + 5];
	memset(res, 0, sizeof(res));
	//反向存储
	for (int i = a.length() - 1; i >= 0; i--) {
		diga[a.length() - i - 1] = a[i] - '0';
	}
	for (int i = b.length() - 1; i >= 0; i--) {
		digb[b.length() - i - 1] = b[i] - '0';
	}
	for (int i = 0; i < a.length(); i++) {
		if (diga[i] == 0) {
			continue;
		}
		for (int j = 0; j < b.length(); j++) {
			res[i + j] += diga[i] * digb[j];
		}
	}
	for (int i = 0; i < a.length() + b.length(); i++) {
		res[i + 1] += res[i] / 10;
		res[i] %= 10;
	}
	int i = a.length() + b.length() - 1;	
	while(i >= 0 && res[i] == 0) {
		i--;
	}
	string s = "";
	if (signres == -1) {
		s += '-';
	}
	while(i >= 0) {
		s += res[i] + '0';
		i--;
	}
	if (s == "-" || s == "") {
		s = "0";
	}
	return s;
}

int main(){
	int n;
	scanf("%d", &n);
	getchar();
	string a, b;
	while(cin >> a >> b) {
		cout << mult(a, b) << endl;
	}
}
