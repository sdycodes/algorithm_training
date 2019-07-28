#include <stdio.h>
#include <stdlib.h>
#define DEBUG 0
#define reopen do{if(DEBUG){freopen("data.in", "r", stdin);}}while(0)
#define showvar(...) do{if(DEBUG){printf("##DEBUG## ");printf(__VA_ARGS__);printf("\n");}}while(0);

struct Person{
    int w, n, d, c;
};
typedef struct Person person;
person persons[50005];

int comp(const void *p1, const void *p2) {
    int a = (*(person*)p1).w;
    int b = (*(person*)p2).w;
    if (a > b) {
        return -1;
    } else if (a == b) {
        return (*(person*)p1).n - (*(person*)p2).n;
    }
    return 1;
}

int main() {
    reopen;
    int n, k;
    scanf("%d%d", &n, &k);
    int e[11];
    for (int i = 0; i < 10; i++) {
        scanf("%d", &e[i+1]);
    }    
    for (int i = 0; i < n; i++) {
        scanf("%d", &persons[i].w);
        persons[i].n = i + 1;
    }
    qsort(persons, n, sizeof(person), comp);
    for (int i = 0; i < n; i++) {
        persons[i].d = i + 1;
        persons[i].c = (persons[i].d - 1)% 10 + 1;
        persons[i].w += e[persons[i].c];
    }
    qsort(persons, n, sizeof(person), comp);
    for (int i = 0; i < k; i++) {
        printf("%d ", persons[i].n);
    }
    printf("\n");
    return 0;
}