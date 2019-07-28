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

int main() {
    return 0;
}