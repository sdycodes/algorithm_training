#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;
int n, m;

void split(string s, char t, vector<string>& res) {
    res.clear();
    if (s.back() == t) s = s.substr(0, s.length() - 1);
    int pre = 1;
    for (int i = 1; i < s.length(); i++) {
        if (s[i] != t) continue;
        res.push_back(s.substr(pre, i - pre));
        pre = i + 1;
    }
    res.push_back(s.substr(pre));
}

struct Elem{
    string raw, val;
    int no;
    vector<string> dirs;
    Elem(string s, int no) {
        this->no = no;
        int pos = 0;
        while(pos < s.length() && s[pos] != ' ') pos++;
        this->raw = s.substr(0, pos);
        this->val = s.substr(pos + 1);
        this->dirs.clear();
        split(raw, '/', dirs);
    }
};

vector<Elem> elems;

int match(string s, vector<string>& paras) {
    for (int i = 0; i < s.length(); i++) {
        if (!isalnum(s[i]) && s[i] != '-' && s[i] != '_' && s[i] != '.' && s[i] != '/') {
            return -1;
        }
    }
    vector<string> x;
    split(s, '/', x);
    for (int i = 0; i < elems.size(); i++) {
        Elem& te = elems[i];
        int ok = 1;
        paras.clear();
        int j;
        for (j = 0; j < min(te.dirs.size(), x.size()); j++) {
            if (te.dirs[j] == "<int>") {
                for (int k = 0; k < x[j].length(); k++) {
                    if (!isdigit(x[j][k])) {ok = 0; break;}
                }
                int pos = 0;
                while (pos < x[j].length() && x[j][pos] == '0') pos++;
                if (pos == x[j].length()) pos--;
                paras.push_back(x[j].substr(pos));
            } else if (te.dirs[j] == "<str>") {
                paras.push_back(x[j]);
            } else if (te.dirs[j] == "<path>") {
                string path = "";
                for (;j < x.size(); j++) {
                    path += x[j];
                    path += '/';
                }
                if (s.back() != '/') path = path.substr(0, path.length() - 1);
                paras.push_back(path);
            } else if (te.dirs[j] == x[j]) {
                ;
            } else {
                ok = 0;
                break;
            }
        }
        if (ok && j >= x.size()) {
            return i + 1;
        }
    }
    return -1;
}


int main() {
    #ifdef D
        freopen("data.in", "r", stdin);
    #endif
    cin >> n >> m;
    cin.get();
    for (int i = 0; i < n; i++) {
        string s;
        getline(cin, s);
        elems.push_back(Elem(s, i + 1));
    }
    for (int i = 0; i < m; i++) {
        string s;
        getline(cin, s);
        vector<string> paras;
        int no = match(s, paras);
        if (no == -1) cout << "404" << endl;
        else {
            cout << elems[no - 1].val;
            for (int j = 0; j < paras.size(); j++) {
                cout << " " << paras[j];
            }
            cout << endl;
        }
    }
    return 0;
}