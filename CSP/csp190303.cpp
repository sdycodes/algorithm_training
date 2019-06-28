#include <iostream>
#include <cstdio>
#include <string>

using namespace std;
unsigned int hex2i(string a) {
	unsigned int res = 0;
	unsigned int base = 1;
	for (int i = 7; i >= 0; i--) {
		res += (a[i] <= '9'? (a[i] - '0'):(a[i] - 'A' + 10)) * base;
		base *= 16;
	}
	return res;
}

string i2hex(unsigned int a) {
	string res = "";
	while (a) {
		res = (char)(a % 16 <= 9? (a % 16 + '0'):(a % 16 - 10 + 'A')) + res;
		a /= 16;
	}
	string padding = "00000000";
	if (res.size() < 8) {
		res = padding.substr(0, 8 - res.size()) + res;
	}
	return res;
}

int main(int argc, char *argv[]) {
	//freopen("data.in","r",stdin);
	ios::sync_with_stdio(false);
	int n, s, l;
	cin >> n >> s >> l;
	int no;
	string sb[1005];
	long long len = 0;
	for (int i = 0; i < l; i++) {
		cin >> no;
		cin >> sb[no];
		len = sb[no].length();
	}
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int bno;
		cin >> bno;
		int strip_no = bno / s;
		int bseq = bno % s;
		int k = strip_no / (n - 1);
		int redundant = n - 1 - (k % n);
		int loc = (redundant + 1 + strip_no % (n - 1)) % n;
		long long base_off = (k * s + bseq) * 8;
		if (base_off + 8 > len) {
			cout << "-" << endl;
			continue;
		}
		if (sb[loc].length() != 0) {
			cout << sb[loc].substr(base_off, 8) << endl;
			continue;
		}
		if (n - l > 1) {
			cout << "-" << endl;
			continue;
		} 
		unsigned int ntar = 0;
		for (int j = 0; j < n; j++) {
			if (j != loc){
				ntar ^= hex2i(sb[j].substr(base_off, 8));
			}
		}
		cout << i2hex(ntar) << endl;
	}
}
