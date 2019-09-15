#include <iostream>
#include <string>
#include <vector>

using namespace std;

void split(string s, vector<string>& res) {
    s += '/';
    int pre = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != '/') continue;
        while(pre < s.length() && s[pre] == '/') pre++;
        if (i - pre > 0) {
            res.push_back(s.substr(pre, i - pre));
        }
        int pos = i + 1;
        while(pos < s.length() && s[pos] == '/') pos++;
        pre = pos;
        i = pos - 1;
    }
    return;
}
int main() {
    #ifdef D
        freopen("data.in", "r", stdin);
    #endif
    int n;
    cin >> n;
    cin.get();
    string s;
    getline(cin, s);
    vector<string> cur;
    cur.push_back("..");
    split(s, cur);
    for (int i = 0; i < n; i++) {
        vector<string> res;
        res.push_back("..");
        getline(cin, s);
        vector<string> tar;
        split(s, tar);
        if (tar.size() == 0) { 
            cout << "/\n"; continue; 
        }
        if (tar[0] == "." || tar[0] == "..") {
            res = cur;
        }
        for (int j = 0; j < tar.size(); j++) {
            if (tar[j] == ".") continue;
            else if (tar[j] == "..") res.pop_back();
            else res.push_back(tar[j]);
        }
        string out = "/";
        for (int j = 0; j < res.size(); j++) {
            if (res[j] != "..") {
                out += res[j];
                out += "/";
            }
        }
        if (out.back() == '/' && out.length() > 1) out = out.substr(0, out.length() - 1);
        cout << out << endl;
    }
    return 0;
}