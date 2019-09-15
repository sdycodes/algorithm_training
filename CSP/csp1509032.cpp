#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <sstream>

using namespace std;

map<string, string> var2val;
vector<string> doc;

void insert_into_dic(string s) {
    int pos = 0;
    while(pos < s.length() && s[pos] != ' ') pos++;
    var2val[s.substr(0, pos)] = s.substr(pos + 2, s.length() - pos - 3);
    return;
}

void output(string s) {
    int i = 0;
    while (i < s.length()) {
        if (s[i] != '{') {
            cout << s[i];
            i++;
        } else if (s[i] == '{' && (s[i + 1] != '{' || i + 1 >= s.length())) {
            cout << s[i];
            i++;
        } else {
            int j = i + 1;
            while(s[j] != '}') j++;
            string varname = s.substr(i, j + 2 - i);
            stringstream ss(varname);
            string t, var;
            ss >> t >> var;
            cout << var2val[var];
            i = j + 2;
        }
    }
    cout << "\n";
    return;
}

int main() {
    #ifdef D
        freopen("data.in", "r", stdin);
    #endif
    var2val.clear();
    doc.clear();
    int n, m;
    cin >> n >> m;
    cin.get();
    for (int i = 0; i < n; i++) {
        string s;
        getline(cin, s);
        doc.push_back(s);
    }
    for (int i = 0; i < m; i++) {
        string s;
        getline(cin, s);
        insert_into_dic(s);
    }
    for (int i = 0; i < n; i++) {
        output(doc[i]);
    }
    return 0;
}