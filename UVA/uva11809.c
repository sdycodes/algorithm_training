#include <stdio.h>
#include <string.h>
#include <math.h>

char s[200];
const double eps = 1e-16;
int main() {
    #ifdef L
        freopen("data.in", "r", stdin);
    #endif
    while(fgets(s, 200, stdin)) {
        if (strcmp(s, "0e0") == 0) {
            break;
        }
        char buf[50];
        int i;
        for (i = 0;; i++) {
            if (s[i] == 'e') {
                buf[i] = '\0';
                break;
            }
            buf[i] = s[i];
        }
        //printf("$$%s\n", buf);
        double m;
        sscanf(buf, "%lf", &m);
        m = m / 10.0;
        int pos = i;
        for (i += 1; i < strlen(s); i++) {
            buf[i - pos - 1] = s[i];
        }
        buf[strlen(s) - pos - 1] = '\0';
        int e;
        sscanf(buf, "%d", &e);
        e++;
        int md = 0;  
        int ed = 1; //符号
        int re = e;
        while(e) {
            e >>= 1;
            ed++;
        }
        for (md = 0; md < 10; md++) {
            if (fabs((log10(1-pow(0.5,md+1))+ (pow(2,ed)-1)*log10(2))-re-log10(m))<1e-6) {
                break;
            }
        }
        printf("%d %d\n", md, ed);
    }
    return 0;
}