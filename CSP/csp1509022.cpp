#include <cstdio>

int month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {
    #ifdef D
        freopen("data.in", "r", stdin);
    #endif
    int year, d;
    scanf("%d%d", &year, &d);
    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
        month[2] = 29;
    } else {
        month[2] = 28;
    }
    int mon = 1;
    while (d - month[mon] > 0) {
        d -= month[mon];
        mon++;
    }
    printf("%d\n%d\n", mon, d);
}