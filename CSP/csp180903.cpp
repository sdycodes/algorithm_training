#include <iostream>
#include <vector>
#include <cstdio>
#include <sstream>

using namespace std;

struct Elem{
    int no, level, par;
    string tag, id;
    vector<int> children;
    Elem(int no, int level, string tag, string id): no(no), level(level), tag(tag), id(id) {}
};
vector<Elem> elems;

string lower(string s) {
    string t = s;
    for (int i = 0; i < t.length(); i++) {
        if (t[i] >= 'A' && t[i] <= 'Z') t[i] = t[i] - 'A' + 'a';
    }
    return t;
}

Elem get_one_elem(int no) {
    string s;
    getline(cin, s);
    int level = 0;
    while(s[level] == '.') {
        level++;
    }
    s = s.substr(level);
    level /= 2;
    int pos = 0;
    while(pos < s.length() && s[pos] != ' ') pos++;
    string tag, id;
    if (pos != s.length()) {
        tag = lower(s.substr(0, pos));
        id = s.substr(pos + 2);
    } else {
        tag = lower(s);
        id = "";
    }
    return Elem(no, level, tag, id);
}

void parse(string s, vector<int>& res) {
    res.clear();
    if (s[0] == '#') {
        s = s.substr(1);
        for (int i = 0; i < elems.size(); i++) {
            if (elems[i].id == s) res.push_back(elems[i].no);
        }
        return;
    }
    stringstream ss(s);
    string x;
    vector<string> sels;
    while(ss >> x) {
        sels.push_back(x);
    }
    string t_tag = lower(sels[0]);
    for (int i = 0; i < elems.size(); i++) {
        if (elems[i].tag == t_tag) {
            res.push_back(elems[i].no);
        }
    }
    for (int i = 1; i < sels.size(); i++) {
        vector<int> tmp;
        string t_tag = lower(sels[i]);
        for (int j = 0; j < res.size(); j++) {
            for (int k = 0; k < elems[res[j] - 1].children.size(); k++) {
                Elem child = elems[elems[res[j] - 1].children[k] - 1];
                if (child.tag == t_tag) {
                    tmp.push_back(child.no);
                }
            }
        }
        res = tmp;
    }
    return;
}

int main() {
    #ifdef D
        freopen("data.in", "r", stdin);
    #endif
    int n, m;
    scanf("%d%d", &n, &m);
    getchar();
    int pre = -1;
    for (int i = 0; i < n; i++) {
        elems.push_back(get_one_elem(i + 1));
        if (pre == -1) pre = elems[0].no;
        else {
            Elem& e = elems.back();
            Elem& ep = elems[pre - 1];
            if (e.level > ep.level) {
                e.par = pre;
                ep.children.push_back(e.no);
            } else if (e.level == ep.level) {
                e.par = ep.par;
                elems[e.par - 1].children.push_back(e.no);
            } else {
                Elem tmp = ep;
                while (tmp.level != e.level) {
                    tmp = elems[tmp.par - 1];
                }
                e.par = tmp.par;
                elems[e.par - 1].children.push_back(e.no);
            }
            pre = elems.back().no;
        }
    }
    for (int i = 0; i < m; i++) {
        string s;
        getline(cin, s);
        vector<int> res;
        parse(s, res);
        printf("%lu", res.size());
        for (int i = 0; i < res.size(); i++) {
            printf(" %d", res[i]);
        }
        printf("\n");
    }
    return 0;
}
