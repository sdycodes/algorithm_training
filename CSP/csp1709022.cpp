#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 1005;
const int maxk = 1005;
struct Op{
    int time, isback, no;
    Op(int no=0, int isback=0, int time=0):time(time), isback(isback), no(no) {}
    bool operator<(const Op& b) const {
        if (time != b.time) return time < b.time;
        if (isback != b.isback) return isback > b.isback;
        return no < b.no;
    }
};
int locs[maxn];
vector<Op> ops;
int main() {
    #ifdef D
        freopen("data.in", "r", stdin);
    #endif
    int N, K;
    scanf("%d%d", &N, &K);
    for (int i = 1; i <= N; i++) {
        locs[i] = i;
    }
    for (int i = 0; i < K; i++) {
        int w, s, c;
        scanf("%d%d%d", &w, &s, &c);
        ops.push_back(Op(w, 0, s));
        ops.push_back(Op(w, 1, s + c));
    }
    sort(ops.begin(), ops.end());
    for (int i = 0; i < ops.size(); i++) {
        if (!ops[i].isback) {
            for (int j = 1; j <= N; j++) {
                if (locs[j] == ops[i].no) {
                    locs[j] = 0;
                    break;
                }
            }
        } else {
            for (int j = 1; j <= N; j++) {
                if (locs[j] == 0) {
                    locs[j] = ops[i].no;
                    break;
                }
            }
        }
    }
    for (int i = 1; i <= N; i++) printf("%d ", locs[i]);
    printf("\n");
    return 0;
}