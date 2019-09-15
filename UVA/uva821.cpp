#include <string>
#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 105;
const int INF = 10000000;
int g[maxn][maxn];
int n, show_up[maxn];
string s;
int read_case() {
    memset(show_up, 0, sizeof(show_up));
    for (int i = 0; i < maxn; i++) {
        g[i][i] = 0;
        for (int j = i + 1; j < maxn; j++) {g[i][j]  = g[j][i] = INF; }
    }
    n = 0;
    getline(cin, s);
    stringstream ss(s);
    int a, b;
    while(ss >> a >> b) {
        if (a == 0 &&  b== 0) return n > 0;
        g[a][b] = 1;
        if (!show_up[a]) {
            show_up[a] = 1;
            n++;
        }
        if (!show_up[b]) {
            show_up[b] = 1;
            n++;
        }
    }
    return 1;
}

void floyd() {
    for (int k = 0; k < maxn; k++) {
        for (int i = 0; i < maxn; i++) {
            for (int j = 0; j < maxn; j++) {
                if (g[i][k] < INF && g[k][j] < INF) {
                    g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
                }
            }
        }
    }
}

int main() {
    #ifdef D
        freopen("data.in", "r", stdin);
    #endif
    int kase = 0;
    while(read_case()) {
        kase++;
        floyd();
        long long sum = 0;
        for (int i = 0; i < maxn; i++) {
            if (show_up[i]) {
                for (int j = 0; j < maxn; j++) {
                    if (show_up[j]) {
                        sum += g[i][j];
                    }
                }
            }
        }
        double res = (double)sum / (n * (n - 1));
        printf("Case %d: average length between pages = %.3f clicks\n", kase, res);
    }
    return 0;
}