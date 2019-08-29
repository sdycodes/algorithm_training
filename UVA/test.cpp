#include <iostream>
#include <map>

using namespace std;
struct Node {
    int a, b;
    Node(int a=0, int b=0): a(a), b(b){}
    bool operator< (const Node& r) const {
        return b < r.b;
    }
};

int main() {
    Node a = Node(1, 2);
    Node b = Node(1, 2);
    Node& c = a;
    Node d = a;
    map<Node, int> mp;
    mp[a] = 1;
    bool bb = mp.find(b) != mp.end();
    bool cb = mp.find(c) != mp.end();
    bool db = mp.find(d) != mp.end();
    cout << bb << " " << cb << " " << db << endl;
    bool be = (a == b);
    bool ce = (a == c);
    bool de = (a == d);
    cout <<  de << ce << de;
    return 0;
}