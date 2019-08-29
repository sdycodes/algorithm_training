#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

struct Node{
    int ord, pri;
};

int main() {
    #ifdef D
        freopen("data.in", "r", stdin);
    #endif
    int T;
    cin >> T;
    while(T--) {
        int N, my;
        cin >> N >> my;
        vector<Node> q;
        for (int i = 0; i < N; i++) {
            Node t;
            cin >> t.pri;
            t.ord = i;
            q.push_back(t);
        }
        int cur_no = -1;
        int t = 0;
        while(cur_no != my) {
            int orig = q.size();
            do {
                Node cur;
                cur.ord = q.begin()->ord;
                cur.pri = q.begin()->pri;
                q.erase(q.begin());
                int flag = 1;
                for (int i = 0; i < q.size(); i++) {
                    if (q[i].pri > cur.pri) {
                        flag = 0;
                        break;
                    }
                }
                if (flag == 0) {
                    q.push_back(cur);
                } else {
                    cur_no = cur.ord;
                }
            }while(q.size() == orig);
            t++;
        }
        printf("%d\n", t);
    }
    return 0;
}