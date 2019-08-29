#include <stdio.h>

struct student{
    long long sid;
    int cid;
    char name[20];
    int score;
};

void add() {
    printf("Please enter the SID, CID, name and four scores. Enter 0 to finish.\n");

}

int main() {
    int op;
    int flag = 0;
    while(scanf("%d", &op) != EOF) {
        printf("Welcome to Student Performance Management System (SPMS).\n1 - Add\n2 - Remove\n3 - Query\n4 - Show ranking\n5 - Show Statistics\n0 - Exit\n");
        switch (op) {
            case 1: add(); break;
            case 2: remove(); break;
            case 3: query(); break;
            case 4: showRank(); break;
            case 5: showStat(); break;
            default: flag = 1; break;
        }
        if (flag) {
            break;
        }
    }
}