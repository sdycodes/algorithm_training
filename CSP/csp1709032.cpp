#include <iostream>
#include <string>
#include <vector>

using namespace std;
string s;
int pos;

void split(string s, char t, vector<string>& res) {
    res.clear();
    int pre = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != '.') continue;
        res.push_back(s.substr(pre, i - pre));
        pre = i + 1;
    }
    res.push_back(s.substr(pre));
}

struct Elem{
    string key;
    string value;
    int isvalueobj;
    int objid;
    Elem(string key, string value, int isvalueobj, int objid){
        this->isvalueobj = isvalueobj;
        this->objid = objid;
        for (int i = 0; i < key.length(); i++) {
            if (key[i] != '\\') this->key += key[i];
            else {
                this->key += key[i + 1]; 
                i++;
            }
        }
        for (int i = 0; i < value.length(); i++) {
            if (value[i] != '\\') this->value += value[i];
            else {
                this->value += value[i + 1]; 
                i++;
            }
        }
    }
};

struct Obj{
    vector<Elem> elems;
    Obj() {
        elems.clear();
    }
};

vector<Obj> objs;

int parse() {
    while(pos < s.length() && s[pos] != '{') pos++;
    Obj ob;
    while(1) {
        if (pos >= s.length() || s[pos] == '}') {
            pos++;
            break;
        }
        int kl = pos + 1;
        while(kl < s.length() && s[kl] != '"') kl++;
        int kr = kl + 1;
        while(kr < s.length() && !(s[kr] == '"' && s[kr - 1] != '\\')) kr++;
        string key = s.substr(kl + 1, kr - kl - 1);
        int colon = kr + 1;
        while(colon < s.length() && s[colon] != ':') colon++;
        int nch = colon+1;
        while(nch < s.length() && s[nch] == ' ') nch++;
        if (s[nch] == '{') {
            int isvalueobj = 1;
            pos = nch;
            int a = parse();
            ob.elems.push_back(Elem(key, "", 1, a));
        } else {
            int vl = nch;
            int vr = vl+ 1;
            while(vr < s.length() && !(s[vr] == '"' && s[vr - 1] != '\\')) vr++;
            string value = s.substr(vl + 1, vr - vl - 1);
            ob.elems.push_back(Elem(key, value, 0, 0));
            pos = vr + 1;
        }
        while(pos < s.length() && s[pos] == ' ') pos++;
    }
    objs.push_back(ob);
    return objs.size() - 1;
}

int main() {
    #ifdef D
        freopen("data.in", "r", stdin);
    #endif
    int n, m;
    cin >> n >> m;
    cin.get();
    s = "";
    for (int i = 0; i < n; i++) {
        string t;
        getline(cin, t);
        s += t;
    }
    pos = 0;
    parse();
    for (int i = 0; i < m; i++) {
        string t;
        getline(cin, t);
        vector<string> instrs;
        split(t, '.', instrs);
        Obj cur = objs.back();
        int ridx = -1;
        int notexist = 0;
        for (int k = 0; k < instrs.size(); k++) {
            ridx = -1;
            for (int j = 0; j < cur.elems.size(); j++) {
                if (cur.elems[j].key ==  instrs[k]) {
                    ridx = j;
                    break;
                }
            }
            if (ridx == -1 || (!cur.elems[ridx].isvalueobj && k != instrs.size() - 1)) {
                notexist = 1;
                break;
            }
            if (cur.elems[ridx].isvalueobj && k != instrs.size() - 1) cur = objs[cur.elems[ridx].objid];
        }
        if (notexist) cout << "NOTEXIST" << endl;
        else if (cur.elems[ridx].isvalueobj) cout << "OBJECT" << endl;
        else cout << "STRING " << cur.elems[ridx].value << endl;
    }
    return 0;
}