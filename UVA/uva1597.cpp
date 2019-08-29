#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>
using namespace std;

bool find_a_line(string s, string w) {
    for (int i = 0; i < s.length() - w.length() + 1; i++) {
        int flag = 1;
        for (int j = 0; j < w.length(); j++) {
            if (s[i + j] != w[j]) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            if (i + w.length() < s.length()) {
                if (isalpha(s[i + w.length()])) {
                    return false;
                }
            }
            if (i > 0) {
                if (isalpha(s[i - 1])) {
                    return false;
                }
            }
            return true;
        }
    }
    return false;
}
struct doc{
    vector<string> lines;
    vector<string> orig;
    vector<int> find(string word) {
        vector<int> res;
        for (int i = 0; i < lines.size(); i++) {
            if (find_a_line(lines[i], word)) {
                res.push_back(i);
            }
        }
        return res;
    }
};

doc docs[1505];
int N;

vector<int> cup(vector<int> a, vector<int> b) {
    vector<int> res;
    bool *tmp = new bool[1505];
    for (int i = 0; i < 1505; i++) {
        tmp[i] = false;
    }
    for (int i = 0; i < a.size(); i++) {
        tmp[a[i]] = true;
    }
    for (int i = 0; i < b.size(); i++) {
        tmp[b[i]] = true;
    }
    for (int i = 0; i < 1505; i++) {
        if (tmp[i]) {
            res.push_back(i);
        }
    }
    return res;
}

vector<vector<int> > parse(string ins) {
    vector<vector<int> > res;
    int loc;
    if ((loc = ins.find("AND")) < ins.length()) {
        string word1 = ins.substr(0, loc - 1);
        string word2 = ins.substr(loc + 4);
        for (int i = 0; i < N; i++) {
            vector<int> a1 = docs[i].find(word1);
            vector<int> a2 = docs[i].find(word2);
            if (a1.size() != 0 && a2.size() != 0) {
                res.push_back(cup(a1, a2));
            } else {
                vector<int> tmp;
                res.push_back(tmp);
            }
        }
    } else if ((loc = ins.find("OR")) < ins.length()) {
        string word1 = ins.substr(0, loc - 1);
        string word2 = ins.substr(loc + 3);
        for (int i = 0; i < N; i++) {
            vector<int> a1 = docs[i].find(word1);
            vector<int> a2 = docs[i].find(word2);
            if (a1.size() != 0 || a2.size() != 0) {
                res.push_back(cup(a1, a2));
            } else {
                vector<int> tmp;
                res.push_back(tmp);
            }
        }
    } else if ((loc = ins.find("NOT")) < ins.length()) {
        string word1 = ins.substr(4);
        for (int i = 0; i < N; i++) {
            vector<int> tmp;
            if (docs[i].find(word1).size() == 0) {
                tmp.push_back(-1);
            } 
            res.push_back(tmp);
        }
    } else {
        for (int i = 0; i < N; i++) {
            res.push_back(docs[i].find(ins));
        }
    }
    return res;
}

void output(vector<vector<int> > res) {
    bool out = false;
    bool ok = false;
    for (int i = 0; i < res.size(); i++) {
        if (res[i].size() > 0) {
            if (ok) {
                cout << "----------" << endl;
            } 
            ok = true;
        }
        for (int j = 0; j < res[i].size(); j++) {
            out = true;
            if (res[i][j] < 0) {
                for (int k = 0; k < docs[i].lines.size(); k++) {
                    cout << docs[i].orig[k] << endl;
                }
            } else {
                cout << docs[i].orig[res[i][j]] << endl;
            }
        }
    }
    if (!out) {
        cout << "Sorry, I found nothing." << endl;
    }
    cout << "==========" << endl;
    return;
}

int main() {
    #ifdef D
        freopen("data.in", "r", stdin);
        freopen("data.out", "w", stdout);
    #endif
    ios::sync_with_stdio(false);
    //test();
    char c;
    cin >> N;
    cin.get();
    for (int i = 0; i < N; i++) {
        string ts;
        while(1) {
            getline(cin, ts);
            if (ts == "**********") break;
            docs[i].orig.push_back(ts);
            transform(ts.begin(),ts.end(),ts.begin(),::tolower);
            docs[i].lines.push_back(ts);
        }
    }
    int n_ins;
    cin >> n_ins;
    cin.get();
    while(n_ins--) {
        string ts;
        getline(cin, ts);
        vector<vector<int> > res = parse(ts);
        output(res);
    }
}