#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
struct Ipcode{
	unsigned int ip;
	int prelen;
};
bool comp(const Ipcode &a, const Ipcode &b) {
	if (a.ip < b.ip) {
		return true;
	} else if (a.ip == b.ip) {
		return a.prelen < b.prelen;
	}
	return false;
}

Ipcode ips[2000];

void preprocess(string s, unsigned int &ip, int &prelen) {
	int dot = 0;
	int a[4] = {0, 0, 0, 0};
	int pre = 0;
	int slashidx = s.length() - 1;
	int slash = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '/') {
			slash++;
			slashidx = i;
		} else if (s[i] == '.') {
			a[dot++] = stoi(s.substr(pre, i - pre));
			pre = i + 1;
		}
	}
	a[dot] = stoi(s.substr(pre, slashidx - pre + 1));
	ip = a[0] * 256 * 256 * 256 + a[1] * 256 * 256 + a[2] * 256 + a[3];
	if (slashidx == s.length() - 1) {
		prelen = (dot + 1) * 8;
	} else {
		prelen = stoi(s.substr(slashidx + 1));
	}
	return;
}

string stdip(Ipcode a) {
	unsigned int ipnum = a.ip;
	int seg[4] = {0, 0, 0, 0};
	int i = 0;
	while(ipnum) {
		seg[3 - i] = ipnum % 256;
		ipnum /= 256;
		i++;
	}
	return to_string(seg[0]) + "." + to_string(seg[1]) + "." + to_string(seg[2]) + "." + to_string(seg[3]) + "/" + to_string(a.prelen);
}
int main(int argc, char *argv[]) {
	//freopen("./data.in", "r", stdin);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	//getchar();
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		preprocess(s, ips[i].ip, ips[i].prelen);
	}
	sort(ips, ips + n, comp);
	for (int i = 0; i < n; i++) {
		cout << stdip(ips[i]) << endl;
	}
}