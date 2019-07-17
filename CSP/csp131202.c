#include <stdio.h>

int main() {
    //freopen("data.in", "r", stdin);
    char a[10];
    char notes;
    scanf("%c-%c%c%c-%c%c%c%c%c-%c", &a[0], &a[1], &a[2], &a[3], &a[4], &a[5], &a[6], &a[7], &a[8], &notes);
    int check = 0;
    for (int i = 0; i < 9; i++) {
        check += ((a[i] - '0') * (i + 1));
    }
    check %= 11;
    char expnotes;
    if (check == 10) {
        expnotes = 'X';
    } else {
        expnotes = (char)check + '0';
    }
    if ((check == 10 && notes == 'X') || (check == notes - '0')) {
        printf("Right\n");
    } else {
        printf("%c-%c%c%c-%c%c%c%c%c-%c\n", a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8], expnotes);
    }
    return 0;
}