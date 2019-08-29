#include <iostream>
#include <cstdio>
#include <map>
#include <string>

using namespace std;

map<char, int> name2len;
map<char, map<int, int> > name2ele;

int decl(string s) {
    int x = stoi(s.substr(2, s.length() - 3));
    name2len[s[0]] = x;
    return 0;
}

int expression(string s) {
    if (s[0] >= '0' && s[0] <= '9') {
        return stoi(s);
    }
    int index = expression(s.substr(2, s.length() - 3));
    char name = s[0];
    if (index >= name2len[name]) {
        return -1;
    }
    if (name2ele[name].find(index) != name2ele[name].end()) {
        map<int, int> eles = name2ele[name];
        return eles[index];
    }
    return -1;
}

int assignment(string s, int equal) {
    int index = expression(s.substr(2, equal - 1));
    if (index == -1 || index >= name2len[s[0]]) {
        return -1;
    }
    int val = expression(s.substr(equal + 1));
    if (val == -1) {
        return -1;
    }
    name2ele[s[0]][index] = val;
    return 0;
}

int program(string s) {
    int equal = -1;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '=') {
            equal = i;
            break;
        }
    }
    int res;
    if (equal != -1) {
        res = assignment(s, equal);
    } else {
        res = decl(s);
    }
    return res;
}

int main() {
    #ifdef D
        freopen("data.in", "r", stdin);
    #endif
    string s;
    int line = 0;
    int rline = 0;
    while(cin >> s) {
        if (s[0] == '.') {
            if (line != 0) {
                printf("%d\n", rline);
            }
            rline = 0;
            line = 0;
            name2len.clear();
            name2ele.clear();
            continue;
        }
        line++;
        if (program(s) != 0 && rline == 0) {
            rline = line;
        }
    }
    return 0;
}