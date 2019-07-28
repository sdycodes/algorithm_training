#include <stdio.h>
#include <math.h>

#define PI 3.14159

double dist(double ax, double ay, double bx, double by) {
    return sqrt((ax - bx) * (ax - bx) + (by - ay) * (by - ay));
}

int main() {
    //freopen("data.in", "r", stdin);
    int N;
    double R;
    scanf("%d%lf", &N, &R);
    double curx, cury;
    double prex = -1, prey = -1, origx, origy;
    double res = 0;
    for (int i = 0; i < N; i++) {
        scanf("%lf%lf", &curx, &cury);
        if (i > 0) {
            res += dist(prex, prey, curx, cury);
        } else {
            origx = curx;
            origy = cury;
        }
        prex = curx;
        prey = cury;
    }
    res += dist(curx, cury, origx, origy);
    res += 2 * PI * R;
    printf("%.2f\n", res);
    return 0;
}