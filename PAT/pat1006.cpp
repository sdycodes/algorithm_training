#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct IO{
    int no, h, m, s;
    IO(int no, string s) {
        this->no = no;
        sscanf(s.c_str(), "%d:%d:%d", &(this->h), &(this->m), &(this->s));
    }
    bool operator<(const IO& rhs) const {
        if (rhs.h != h) return h < rhs.h;
        if (rhs.m != m) return m < rhs.m;
        return s < rhs.s;
    }
};

vector<IO> ins;
vector<IO> ous;
vector<string> names;
int main() {
    #ifdef D
        freopen("data.in", "r", stdin);
    #endif
    int n;
    //scanf("%d", &n);
    ios::sync_with_stdio(false);
    cin >> n;
    string id, in, out;
    while(n--) {
        cin >> id >> in >> out;
        names.push_back(id);
        ins.push_back(IO(names.size() - 1, in));
        ous.push_back(IO(names.size() - 1, out));
    }
    sort(ins.begin(), ins.end());
    sort(ous.begin(), ous.end());
    cout << names[ins[0].no] << " " << names[ous.back().no] << endl;
    return 0;
}