#include <cstdio>

int mon[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void get_date(int year, int d) {
    // already mod Feb.
    int m = 1;
    while (d - mon[m] > 0) {
        d -= mon[m];
        m++;
    }
    printf("%d/%02d/%02d\n", year, m, d);
}

int main() {
    #ifdef D
        freopen("data.in", "r", stdin);
    #endif
    int a, b, c, y1, y2;
    scanf("%d%d%d%d%d", &a, &b, &c, &y1, &y2);
    for (int y = y1; y <= y2; y++) {
        if (y % 400 == 0 || (y % 100 != 0 && y % 4 == 0)) {
            mon[2] = 29;
        } else {
            mon[2] = 28;
        }
        int d = 0;
        a--;
        while(a) {
            d += mon[a];
            a--;
        }
        d += (b - 1) * 7 + c;
        get_date(y, d);
    }

    return 0;
}