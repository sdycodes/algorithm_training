#include <iostream>

using namespace std;

void hanoi(char src, char mid, char dst, int num){
	if (num == 0){
		return;
	}
	hanoi(src, dst, mid, num-1);
	printf("%c to %c\n", src, dst);
	hanoi(mid, src, dst, num-1);
}

int main(int argc, char *argv[]) {
	int n;
	while(scanf("%d", &n)!=EOF) {
		hanoi('A', 'B', 'C', n);
		printf("\n");
	}
	return 0;
}