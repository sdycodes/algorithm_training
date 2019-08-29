#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    #ifdef D
    freopen("data.in", "r", stdin);
    #endif
    int N;
    int T;
    scanf("%d", &T);
    while(scanf("%d", &N) != EOF) {
        map<int, vector<int> > mp;
        for (int i = 0; i < N; i++) {
            int x, y;
            scanf("%d%d", &x, &y);
            mp[y].push_back(x); 
        }
        int axis = -200000;
        int flag = 1;
        for (map<int, vector<int> >::iterator it = mp.begin(); it != mp.end(); it++) {
            vector<int> px = it->second;
            sort(px.begin(), px.end());
            int axis_cur = (px[0] + px[px.size() - 0 - 1]);
            for (int i = 1; i <= px.size() / 2; i++) {
                if (axis_cur != px[i] + px[px.size() - i - 1]) {
                    flag = 0;
                    break;
                }
            }
            if (flag == 1) {
                if (axis == -200000) {
                    axis = axis_cur;
                } else {
                    if (axis_cur != axis) {
                        flag = 0;
                    }
                }
            }
            if (flag == 0) {
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