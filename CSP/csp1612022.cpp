#include <cstdio>
#include <algorithm>
using namespace std;


// 1） 个人所得税起征点为3500元，若S不超过3500，则不交税，3500元以上的部分才计算个人所得税，令A=S-3500元；
// 2） A中不超过1500元的部分，税率3%；
// 3） A中超过1500元未超过4500元的部分，税率10%；
// 4） A中超过4500元未超过9000元的部分，税率20%；
// 5） A中超过9000元未超过35000元的部分，税率25%；
// 6） A中超过35000元未超过55000元的部分，税率30%；
// 7） A中超过55000元未超过80000元的部分，税率35%；
// 8） A中超过80000元的部分，税率45%；

int after_tax(int S) {
    int T;
    int tax = 0;
    if (S <= 3500) return S;
    int A = S - 3500;
    if (A > 0) tax += min(A, 1500) / 100 * 3;
    A -= 1500;
    if (A > 0) tax += min(A, 3000) / 100 * 10;
    A -= 3000;
    if (A > 0) tax += min(A, 4500) / 100 * 20;
    A -= 4500;
    if (A > 0) tax += min(A, 35000 - 9000) / 100 * 25;
    A -= (35000 - 9000);
    if (A > 0) tax += min(A, 55000 - 35000) / 100 * 30;
    A -= (55000 - 35000);
    if (A > 0) tax += min(A, 80000 - 55000) / 100 * 35;
    A -= (80000 - 55000);
    if (A > 0) tax += A / 100 * 45;
    return S - tax;
}
int main() {
    #ifdef D
        freopen("data.in", "r", stdin);
    #endif
    int T;
    scanf("%d", &T);
    int S = 0;
    while(1) {
        if (T == after_tax(S)) break;
        S += 100;
    }
    printf("%d\n", S);
    return 0;
}