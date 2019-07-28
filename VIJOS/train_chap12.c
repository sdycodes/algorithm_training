#include <stdio.h>
#include <string.h>
#define DEBUG 0

int main() {
    //freopen("data.in", "r", stdin);
    //p1001();
    
    return 0;
}

/* 
void p1001() {
    int n;
    scanf("%d", &n);
    char name[100];
    char max_name[100];
    int max_money = 0;
    char lead, west;
    int cnt = 0;
    int grades, classgrades, paper;
    for (int i = 0; i < n; i++) {
        getchar();
        scanf("%s %d %d %c %c %d", name, &grades, &classgrades, &lead, &west, &paper);
        int money = 0;
        if (grades > 80 && paper >= 1) {
            money += 8000;
        }
        if (grades > 85 && classgrades > 80) {
            money += 4000;
        }
        if (grades > 90) {
            money += 2000;
        }
        if (grades > 85 && west == 'Y') {
            money += 1000;
        }
        if (classgrades > 80 && lead == 'Y') {
            money += 850;
        }
        cnt += money;
        if (max_money < money) {
            max_money = money;
            strcpy(max_name, name);
        }
    }
    printf("%s\n", max_name);
    printf("%d\n", max_money);
    printf("%d\n", cnt);
}
void p1848() {
    int times[10];
    memset(times, 0, sizeof(times));
    int n, x;
    scanf("%d%d", &n, &x);
    for (int i = 1; i <= n; i++) {
        int rec = i;
        while(rec) {
            times[rec % 10]++;
            rec /= 10;
        }
    }
    printf("%d", times[x]);
}
void p1911() {
    int set[101];
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &set[i]);
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int flag = 0;
        for (int j = 0; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (j != i && k != i && set[j] + set[k] == set[i]) {
                    flag = 1;
                    break;
                }
            }
            if (flag) {
                break;
            }
        }
        if (flag) {
            cnt ++;
        }
    }
    printf("%d", cnt);
}
void p1217() {
    int a11 = 0, b11 = 0, a21 = 0, b21 = 0;
    char c;
    int g11[20000], g21[20000];
    int cnt11 = 0, cnt21 = 0;
    while((c = getchar()) != EOF) {
        if (c == 'E') {
            break;
        } else if (c == 'W') {
            a11++;
            a21++;
        } else if (c == 'L') {
            b11++;
            b21++;
        } 
        if ((a11 >= 11 && a11 - b11 >= 2) || (b11 >= 11 && b11 - a11 >= 2)) {
            g11[cnt11] = a11;
            g11[cnt11 + 1] = b11;
            cnt11 += 2;
            a11 = 0;
            b11 = 0;
        }
        if ((a21 >= 21 && a21 - b21>= 2) || (b21 >= 21 && b21 - a21 >= 2)) {
            g21[cnt21] = a21;
            g21[cnt21 + 1] = b21;
            cnt21 += 2;
            a21 = 0;
            b21 = 0;
        }
    }
    for (int i = 0; i < cnt11; i += 2) {
        printf("%d:%d\n", g11[i], g11[i + 1]);
    }
    printf("%d:%d\n", a11, b11);
    printf("\n");
    for (int i = 0; i < cnt21; i += 2) {
        printf("%d:%d\n", g21[i], g21[i + 1]);
    }
    printf("%d:%d\n", a21, b21);
}
void p1449() {
        int n;
    scanf("%d", &n);
    char s[3][10005];
    for (int i = 0; i < 3; i++) {
        scanf("%s", s[i]);
    }
    int rever = -1;
    for (int i = 0; i < 3; i++) {
        //逐一尝试
        for (int k = 0; k <= 6; k++) {
            int pass1 = 1, pass2 = 1;
            for (int w = 0; w < n; w++) {
                char shiftfowrd = ((s[i][n - w - 1] + k) - 'a') % 26 + 'a';
                char shiftback = (s[i][n - w - 1] - 'a' - k + 26) % 26 + 'a';
                if (!(shiftfowrd == s[(i + 1)%3][w] && shiftback == s[(i - 1 + 3)%3][w])) {
                        if (DEBUG) {
                            printf("DEBUG: i %d k %d w %d %c %c %c %c\n", i, k, w, shiftfowrd, s[(i + 1)%3][w], shiftback, s[(i - 1 + 3)%3][w]);
                        }
                        pass1 = 0;
                    }
                if (!(shiftback == s[(i + 1)%3][w] && shiftfowrd == s[(i - 1 + 3)%3][w])) {
                        pass2 = 0;
                } 
            }
            if (pass1 || pass2) {
                rever = i;
                if (DEBUG) {
                    printf("k: %d rever %d", k, rever);
                }
                break;
            }
        }
        if (rever != -1) {
            break;
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        printf("%c", s[rever][i]);
    }
    printf("\n");
}
*/