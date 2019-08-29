#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdio>
using namespace std;
string files[105];
int max(int a, int b) {
    return a > b? a : b;
}

void printfilename(string s, int maxl) {
    int len = s.length();
    printf("%s", s.c_str());
    while(len < maxl) {
        putchar(' ');
        len++;
    }
    return;
}

int main() {
    #ifdef D
        freopen("data.in", "r", stdin);
    #endif
    int N;
    while(scanf("%d", &N) == 1) {
        getchar();
        int maxlen = 0;
        for (int i = 0; i < N; i++) {
            cin >> files[i];
            maxlen = max(maxlen, files[i].length());
        }
        sort(files, files + N);
        int L = maxlen + 2;
        int C = (60 - maxlen) / L + 1;
        int R = (N - 1) / C + 1;
        //printf("%d %d %d\n", L, C, R);
        for (int i = 0; i < 60; i++) {
            putchar('-');
        }
        putchar('\n');
        // for (int i = 0; i < N;i++) {
        //     cout << files[i] << endl;
        // }
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (i + j * R < N) {
                    printfilename(files[i + j * R], L);
                }
            }
            putchar('\n');
        }
    }
    return 0;
}
