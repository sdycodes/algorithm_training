#include <cstdio>
#include <cstring>

int main() {
    #ifdef D
        freopen("data.in", "r", stdin);
    #endif 
    char s[20];
    scanf("%s", s);
    int res = 0;
    for (int i = 0; i < strlen(s); i++) {
        res += s[i] - '0';
    }
    printf("%d\n", res);
    return 0;
}