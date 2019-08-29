#include <cstdio>
#include <iostream>
#include <set>

using namespace std;
int main() {
    #ifdef D
        freopen("data.in", "r", stdin);
    #endif
    set<string> tab;
    set<string> res;
    string s;
    while(cin >> s) {
        tab.insert(s);
    }
    for (set<string>::iterator it = tab.begin(); it != tab.end(); it++) {
        if ((*it).length() > 1) {
            int flag = 0;
            for (int i = 1; i < (*it).length(); i++) {
                string l = (*it).substr(0, i);
                string r = (*it).substr(i);
                if (tab.count(l) && tab.count(r)) {
                    res.insert(*it);
                }
            }
        }
    }
    for (set<string>::iterator it = res.begin(); it != res.end(); it++) {
        printf("%s\n", (*it).c_str());
    }
    return 0;
}