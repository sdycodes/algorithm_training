#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    #ifdef D
        freopen("data.in", "r", stdin);
    #endif 
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    int sumation = 0;
    for (int i = 0; i < s.length(); i++) {
        sumation += (s[i] - '0');
    }
    int digs[5];
    int dig = 0;
    do{ 
        digs[dig++] = sumation % 10;
        sumation /= 10;
    }while(sumation);
    map<int, string> mp;
    mp[1] = "one";
    mp[2] = "two";
    mp[3] = "three";
    mp[4] = "four";
    mp[5] = "five";
    mp[6] = "six";
    mp[7] = "seven";
    mp[8] = "eight";
    mp[9] = "nine";
    mp[0] = "zero";
    cout << mp[digs[--dig]];
    while(dig) {
        cout << " " << mp[digs[--dig]];
    }
    cout << "\n";
    return 0;
}