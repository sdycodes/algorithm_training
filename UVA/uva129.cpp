#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
string s;
char cands[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int tot;
int n, k;

int islegal(int cur) {
    for (int i = cur - 1; i >= 0; i -= 2) {
        int mid = (s.length() - i) / 2 + i;
        if (s.substr(i, mid - i) == s.substr(mid))
            return 0;
    }
    return 1;
}

void search(int cur) {
    if (tot == n) {
        int group = 0;
        for (int i = 0; i < s.length(); i++) {
            printf("%c", s[i]);
            if (i != 0 && i < s.length() - 1 && i % 4 == 3) {
                group++;
                if (group == 16) printf("\n");
                else printf(" ");
            }
        }
        printf("\n");
        printf("%lu\n", s.length());
        return;
    }
    if (tot > n) return;
    s += "-";
    for (int i = 0; i < k; i++) {
        s[cur] = cands[i];
        if (islegal(cur)) {
            tot++;
            search(cur + 1);
        }
    }
    s = s.substr(0, s.length() - 1);
}
int main() {
    #ifdef D
        freopen("data.in", "r", stdin);
    #endif
    
    while(scanf("%d%d", &n, &k) != EOF) {
        if (!n && !k) break;
        s.clear();
        tot = 0;
        search(0);
    }
    
    return 0;
}