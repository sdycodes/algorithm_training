#include <stdio.h>
#include <stdlib.h>
struct Node {
	int num;
	struct Node *next;
};

typedef struct Node node;
int main(int argc, char *argv[]) {
	int n, k;
	scanf("%d%d", &n, &k);
	node *cur, *pre = NULL;
	node *tail;
	for (int i = n; i >= 1; i--) {
		cur = (node*)malloc(sizeof(node));
		cur->num = i;
		cur->next = pre;
		pre = cur;
		if (i == n) {
			tail = cur;
		}
	}
	tail->next = cur;
	pre = tail;
	int number = 0;
	while (cur->next != cur) {
		//报数
		number++;
		//检查
		if (number % 10 == k || number % k == 0) {
			pre->next = cur->next;
			free(cur);
			cur = pre->next;
		} else {
			pre = cur;
			cur = cur->next;
		}
	}
	printf("%d", cur->num);
	return 0;
}