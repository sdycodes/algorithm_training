// 重定向
freopen("data.in","r",stdin);

//字符串与数字相互转化
stoi
to_string
//加速cin
ios::sync_with_stdio(false);
//用了这句话 不要再用scanf和printf和getchar而且，最好放在重定向之后


//区间重叠部分的计算  不需要去计算各种交叠情况
if (!(b[i] < c[j] || a[i] > d[j])) {
	res += (min(b[i], d[j]) - max(a[i], c[j]));
}

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

//check list
//1 数据规模
//2 数字范围
//3 重定向

//脚下留心
//1 注意多重循环的break只打断了一层