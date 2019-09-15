#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <string>
#include <set>

using namespace std;

void split(string s, char c, vector<string> elems) {
    int pre = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != c) continue;
        elems.push_back(s.substr(pre, i - pre + 1));
        pre = i + 1;
    }
    elems.push_back(s.substr(pre));
}

struct Disc{
    string raw;
    set<int> mi, hour, day_of_month, day_of_week;
    Disc(string s) {
        this->raw = s;
        stringstream ss(s);
        string tmp;
        int set_no = 0;
        while(ss >> tmp) {
            set_no++;
            if (tmp == "*") {
                continue;
            } else {
                vector<string> ts;
                split(tmp, ',', ts);
                set<int>& obj = this->mi;
                if (set_no == 2) {
                    obj = this->hour;
                } else if (set_no == 3) {
                    obj = this->day_of_month;
                } else if (set_no == 4) {
                    obj = this->day_of_week;
                } 
                for (int i = 0; i < ts.size(); i++) {
                    int pos = 0;
                    while(pos < ts[i].length() && ts[i][pos] != '-') pos++;
                    if (pos != ts[i].length()) {
                        int l = stoi(ts[i].substr(pos)), r = stoi(ts[i].substr(pos+1));
                        for (int j = l; j <= r; j++) obj.insert(j);
                    } else {
                        obj.insert(stoi(ts[i]));
                    }
                }
            }
        }
    }
};

int main() {
    #ifdef D
        freopen("data.in", "r", stdin);
    #endif;

    return 0;
}