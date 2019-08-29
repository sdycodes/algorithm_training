#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>

using namespace std;

struct Row{
    int m;
    int no;
    string cols[15];
    friend bool operator < (const Row& a, const Row& b) {
        for (int i = 0; i < a.m; i++) {
            if (a.cols[i] != b.cols[i]) {
                return a.cols[i] < b.cols[i];
            }
        }
        return a.no < b.no;
    }
};

Row rows[10005];

Row build(string s, int m, int no) {
    Row r;
    r.m = m;
    r.no = no;
    int i = 0, pre = 0, cur = 0;
    while(i < s.length()) {
        if (s[i] == ',') {
            r.cols[cur++] = s.substr(pre, i - pre);
            pre = i + 1;
        }
        i++;
    }
    r.cols[cur++] = s.substr(pre, i - pre);
    return r;
}

bool judge(int &r1, int &r2, int &c1, int& c2, int n) {
    int m = rows[0].m;
    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            for (int k = 1; k < n; k++) {
                if (rows[k - 1].cols[i] == rows[k].cols[j]) {
                    r1 = rows[k - 1].no;
                    r2 = rows[k].no;
                    c1 = i;
                    c2 = j;
                    return false;
                }
            }
        }
    }
    return true;
}

int main() {
    #ifdef D
        freopen("data.in", "r", stdin);
    #endif
    int n, m;
    while(scanf("%d%d", &n, &m) == 2) {
        getchar();
        string s;
        for (int i = 0; i < n; i++) {
            getline(cin, s);
            //cout << s << endl;
            rows[i] = build(s, m, i);
        }
        sort(rows, rows + n);
        for (int i = 0; i < n; i++) {
            cout << rows[i].cols[0] << rows[i].cols[1] << rows[i].cols[2] << endl;
        }
        int r1, r2, c1, c2;
        if (judge(r1, r2, c1, c2, n)) {
            printf("YES\n");
        } else {
            printf("NO\n%d %d\n%d %d\n", r1, r2, c1, c2);
        }
    }
    return 0;
}