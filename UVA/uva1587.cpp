#include <bits/stdc++.h>
using namespace std;
 
struct face{
    int x, y;
}a[6];
bool check()
{
    if(memcmp(a, a+1, sizeof(face)) || memcmp(a+2, a+3, sizeof(face)) || memcmp(a+4, a+5, sizeof(face))) return false;
    if(a[0].x!=a[2].x || a[0].y!= a[4].x || a[2].y!=a[4].y) return false;
    return true;
}
int main()
{
    while(cin >> a[0].x >> a[0].y >> a[1].x >> a[1].y >> a[2].x >> a[2].y >> a[3].x >> a[3].y >> a[4].x >> a[4].y >> a[5].x >> a[5].y){
        for(int i = 0; i < 6; ++i)
            if(a[i].x < a[i].y)
                swap(a[i].x, a[i].y);
        sort(a, a+6, [](const face a, const face b) {return a.x==b.x ? (a.y > b.y) : (a.x > b.x);});
        printf("%s\n", check() ? "POSSIBLE" : "IMPOSSIBLE");
    }
    return 0;
}

