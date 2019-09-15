#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

struct Priv{
    string name;
    int level;
    Priv(string s) {
        int pos = 0;
        while(pos <s.length() && s[pos] != ':') {
            pos++;
        }
        if (pos == s.length()) {
            name = s;
            level = -1;
        }
        else {
            name = s.substr(0, pos);
            level = stoi(s.substr(pos + 1));
        }
    }
};

map<string, int> name2role;

struct Role{
    string name;
    vector<Priv> privs;
    Role(string s) {
        stringstream ss(s);
        ss >> name;
        int a;
        ss >> a;
        while(a--) {
            string t;
            ss >> t;
            privs.push_back(Priv(t));
        }
    }
};

vector<Role> roles;

struct User{
    string name;
    map<string, int> pri2lev;
    User(string s) {
        stringstream ss(s);
        ss >> name;
        pri2lev.clear();
        int a;
        ss >> a;
        while(a--) {
            string role;
            ss >> role;
            Role tr = roles[name2role[role]];
            for (int i = 0; i < tr.privs.size(); i++) {
                if (pri2lev.find(tr.privs[i].name) == pri2lev.end()) {
                    pri2lev[tr.privs[i].name] = tr.privs[i].level;
                } else {
                    pri2lev[tr.privs[i].name] = max(pri2lev[tr.privs[i].name], tr.privs[i].level);
                }
            }
        }
    }
};

vector<User> users;
map<string, int> name2user;

int main() {
    #ifdef D
        freopen("data.in", "r", stdin);
    #endif
    int p;
    cin >> p;
    cin.get();
    for (int i = 0; i < p; i++) {
        string s;
        getline(cin, s);
    }
    int r;
    cin >> r;
    cin.get();
    for (int i= 0; i < r; i++) {
        string s;
        getline(cin, s);
        roles.push_back(Role(s));
        name2role[roles.back().name] = roles.size() - 1;
    }
    int u;
    cin >> u;
    cin.get();
    for (int i = 0; i < u; i++) {
        string s;
        getline(cin, s);
        users.push_back(User(s));
        name2user[users.back().name] = users.size() - 1;
    }
    int q;
    cin >> q;
    cin.get();
    for (int i = 0; i < q; i++) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        string name, priv;
        ss >> name >> priv;
        Priv p = Priv(priv);
        if (name2user.find(name) == name2user.end()) {
            cout << "false\n";
            continue;
        }
        User us = users[name2user[name]];
        if (us.pri2lev.find(p.name) == us.pri2lev.end()) {
                cout << "false\n";
        } else {
            if (p.level == -1) {
                if (us.pri2lev[p.name] == -1) cout << "true\n";
                else cout << us.pri2lev[p.name] <<"\n";
            } else {
                if (us.pri2lev[p.name] >= p.level) cout << "true\n";
                else cout << "false\n";
            }
        }
    }
    return 0;
}