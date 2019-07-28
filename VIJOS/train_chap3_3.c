#include <stdio.h>
#include <string.h>

#define DEBUG 0
#define reopen do{if (DEBUG) freopen("data.in", "r", stdin);}while(0)
#define showvar(...) do{if (DEBUG) {printf("##DEBUG## ");printf(__VA_ARGS__);printf("\n");}}while(0)
#define showarray(lo, hi, a) do{if (DEBUG) {printf("##DEBUG## ");for (int _i = lo; _i < hi; _i++) printf("%d ", a[_i]);printf("\n");}}while(0)
 //注意特殊情况 分母为1的处理  连分数和分数都有这个问题
long long gcd(long long a, long long b) {
    if (a < b) {
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
    }
    long long r = 1;
    while(r) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main() {
    reopen;
    char s[5000];
    long long nums[1000];
    while(scanf("%s", s)!=EOF) {
        int len = (int)strlen(s);
        if (s[0] == '[') {
            showvar("%s", s);
            int a = 0;
            int cnt = 0;
            for (int i = 1; i < len; i++) {
                if (s[i] >= '0' && s[i] <= '9') {
                    a *= 10;
                    a += (s[i] -'0');
                } else if (s[i] == ',' || s[i] == ';' || s[i] ==']') {
                    nums[cnt++] = a;
                    a = 0;
                }
            }
            showarray(0, cnt, nums);
            long long norm = 0, denorm = 1;
            for (int i = cnt - 1; i >= 0; i--) {
                norm = nums[i] * denorm + norm;
                if (i != 0) {
                    long long tmp = norm;
                    norm = denorm;
                    denorm = tmp;
                }
            }
            long long common = gcd(norm, denorm);
            norm /= common;
            denorm /= common;
            if (denorm == 1) {
                printf("%lld\n", norm);
            } else {
                printf("%lld/%lld\n", norm, denorm);
            }
        } else {
            long long a = 0, b = 0;
            int i = 0;
            for (; i < len; i++) {
                if (s[i] != '/') {
                    a *= 10;
                    a += (s[i] - '0');
                }
                if (s[i] == '/') {
                    i += 1;
                    break;
                }
            }
            for (; i < len; i++) {
                b *= 10;
                b += (s[i] - '0');
            }
            showvar("%lld %lld", a, b);
            long long m = gcd(a, b);
            a /= m;
            b /= m;
            printf("[");
            int first = 1;
            while(b) {
                printf("%lld", a / b);
                a %= b;
                long long tmp = a;
                a = b;
                b = tmp;
                if (first) {
                    if (b) {
                        printf(";");
                    } else {
                        printf("]\n");
                    }
                    first = 0;
                } else {
                    if (b) {
                        printf(",");
                    } else {
                        printf("]\n");
                    }
                }
            }
        }
    }
    return 0;
}