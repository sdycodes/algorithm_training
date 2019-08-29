#include <iostream>
#include <map>

using namespace std;

int main() {
    #ifdef D
        freopen("data.in", "r", stdin);
    #endif
    int n;
    while(scanf("%d", &n) == 1 && n) {
        map<pair<int, int>, int> cnt;
        for (int i = 0; i < n; i++) {
            int a, b;
            scanf("%d%d", &a, &b);
            if (a < b) {
                pair<int, int> tmp = make_pair(a, b);
                cnt[tmp]++;
            } else {
                pair<int, int> tmp = make_pair(b, a);
                cnt[tmp]--;
            }
        }
        int flag = 1;
        for (map<pair<int, int>, int>::iterator it = cnt.begin(); it != cnt.end(); it++) {
            if (it->second != 0) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}