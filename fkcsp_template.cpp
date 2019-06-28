// 重定向
freopen("data.in","r",stdin);
//加速cin
ios::sync_with_stdio(false);
//用了这句话 不要再用scanf和printf 而且，最好放在重定向之后

//八位十六进制 字符串整数互转
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

