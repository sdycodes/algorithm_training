#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    #ifdef D
        freopen("data.in", "r", stdin);
    #endif
    string s;
    int T;
    cin >> T;
    cin.get();
    while(T--) {
        getline(cin, s);
        bool islegal = true;
        stack<char> q;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(' || s[i] == '[') {
                q.push(s[i]);
            } else if (s[i] == ')') {
                if (q.size() > 0 && q.top() == '(') {
                    q.pop();
                } else {
                    islegal = false;
                    break;
                }
            } else {
                if (q.size() > 0 && q.top() == '[') {
                    q.pop();
                } else {
                    islegal = false;
                    break;
                }
            }
        }
        if (q.size() > 0) islegal = false;
        if (islegal) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}