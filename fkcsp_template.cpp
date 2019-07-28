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

//swap
void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
    return;
}

//最小优先队列
priority_queue<int, vector<int>, greater<int> > q;
#include <stdlib.h>
qsort(首地址指针, 个数, 每个单元的大小, comp);
int comp(const void *p1, const void *p2) {
    如果p1在前 返回小于0
    如果p2在前 返回大于0
    不确定 返回0
}

//组合数模版
long long comb(int n, int r) {
    if (r < n - r) {
        r = n - r;
    }
    long long res = 1;
    for (int i = 1; i <= r; i++) {
        res = res * (i + (n - r)) / i;
    }
    return res;
}

//debug 模版 重定向 调试信息输出
#define DEBUG 0

#define reopen do{if (DEBUG) freopen("data.in", "r", stdin);}while(0)
#define showvar(...) do{ if(DEBUG) {\
                            printf("DEBUG:"); \
                            printf(__VA_ARGS__); \
                            printf("\n");} \
                        }while(0)

// TODO 模板
// 日期计算问题
#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int quickNumPower(int a, int n, int mod) {
    //中间结果可能溢出 所以尽管返回值是int 中间还是用long long
    long long res = 1;
    while (n) {
        if (n & 1) {
            res = (res * a) % mod;
        }
        a = (a * a) % mod;
        n >>= 1;
    }
    return res;
}

struct Matrix{
    int a[100][100];
    int n;
};

typedef Matrix matrix;

matrix mul(matrix x, matrix y, int mod){
    int rc = x.n;
    matrix res;
    memset(res.a, 0, sizeof(res.a));
    for (int i = 0; i < rc; i++) {
        for (int j = 0; j < rc; j++) {
            for (int k = 0; k < rc; k++) {
                res.a[i][j] = (res.a[i][j] + (x.a[i][k] * y.a[k][j]) % mod) % mod;
            }
        }
    }
    return res;
}

matrix quickMatPower(matrix x, int n, int mod) {
    matrix res;
    memset(res.a, 0, sizeof(res.a));
    while(n) {
        if (n & 1) {
            res = mul(res, x, mod);
        }
        x = mul(x, x, mod);
        n >>= 1;
    }
    return res;
}


//各种类型的数据范围
char -128 ~ +127 (1 Byte)
short -32768 ~ + 32767 (2 Bytes)
unsigned short 0 ~ 65536 (2 Bytes)
int -2147483648 ~ +2147483647 (4 Bytes)
unsigned int 0 ~ 4294967295 (4 Bytes)
long == int
long long -9223372036854775808 ~ +9223372036854775807 (8 Bytes)
double 1.7 * 10^308 (8 Bytes)

//减法求余
((a-b)%n+n)%n;

//gcd
int gcd(int a, int b) {
    if (a > b) {
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
    }
    int r = 1;
    while(r) {
        r = b % a;
        b = a;
        a = r;
    }
    return b;
}

//组合数
long long comb(int n, int r) {
    if (r < n - r) {
        r = n - r;
    }
    long long res = 1;
    for (int i = 1; i <= r; i++) {
        res = res * (i + (n - r)) / i;
    }
    return res;
}

//check list
//1 数据规模
//2 数字范围
//3 debug开关关闭
//4 输出字符串是否一致

//脚下留心
//1 注意多重循环的break只打断了一层
//2 注意如果有桶问题（数字的值称为指标），要注意处理的范围
//3 高度注意循环变量到底是哪一个
//4 不要试图使用%d%d逐位获取数字