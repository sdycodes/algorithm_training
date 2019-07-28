#include <stdio.h>
#include <string.h>

char dna[51][1005];
char res[1005];
char* s = "ACGT";
int resp;
int main() {
    #ifdef L
        freopen("./data.in", "r", stdin);
    #endif
    int T;
    scanf("%d", &T);
    while(T--) {
        int n, len;
        scanf("%d%d", &n, &len);
        getchar();
        for (int i = 0; i < n; i++) {
            fgets(dna[i], len + 4, stdin);
            //scanf("%s", dna[i]);
        }
        int ham = 0;
        resp = 0;
        for (int pos = 0; pos < len; pos++) {
            int ticket[4] = {0, 0, 0, 0};
            for (int i = 0; i < n; i++) {
                switch(dna[i][pos]) {
                    case 'A': ticket[0]++; break;
                    case 'C': ticket[1]++; break;
                    case 'G': ticket[2]++; break;
                    case 'T': ticket[3]++; break;
                }
            }
            int max = ticket[0];
            int maxi = 0;
            for (int i = 1; i < 4; i++) {
                if (max < ticket[i]) {
                    max = ticket[i];
                    maxi = i;
                }
            }
            res[resp++] = s[maxi];
            for (int i = 0; i < 4; i++) {
                if (i != maxi) {
                    ham += ticket[i];
                }
            }
        }
        res[resp] = '\0';
        printf("%s\n", res);
        printf("%d\n", ham);
    }
    return 0;
}