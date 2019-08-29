#include <iostream>
#include <cstdio>
#include <string>

using namespace std;
string s, t;
int draw(int& h, int& p, int len) {
    int res = 0;
    if (s[h] != 'p' && t[p] != 'p') {
        if (s[h] == 'f' || t[p] == 'f') {
            res = len * len;
        } else {
            res = 0;
        }
        h++;
        p++;   
    } else if (s[h] == 'p' && t[p] != 'p') {
        h++;
        for (int i = 0; i < 4; i++) {
            res += draw(h, p, len / 2);
            p--;
        }
        p++;
    } else if (t[p] == 'p' && s[h] != 'p'){
        p++;
        for (int i = 0; i < 4; i++) {
            res += draw(h, p, len / 2);
            h--;
        }
        h++;
    } else {
        h++;
        p++;
        for (int i = 0; i < 4; i++) {
            res += draw(h, p, len / 2);
        }
    }
    return res;
}

int main() {
    #ifdef D
        freopen("data.in", "r", stdin);
    #endif
    int T;
    scanf("%d", &T);
    getchar();
    while(T--) {
        s.clear();
        t.clear();
        getline(cin, s);
        getline(cin, t);
        int a = 0, b = 0;
        printf("There are %d black pixels.\n", draw(a, b, 32));
    }
    return 0;
}