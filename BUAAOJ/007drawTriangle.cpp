#include <iostream>

using namespace std;

void drawTri(int n) {
	for (int i = n; i>=1;i--) {
		int totalLen = 2*i - 1;
		int halfBlankLen = (n-i);
		for (int i = 0;i<halfBlankLen;i++)
			printf(" ");
		for (int i = 0;i<totalLen;i++)
			printf("#");
		for (int i = 0;i<halfBlankLen;i++)
			printf(" ");
		printf("\n");
	}
}
int main(int argc, char *argv[]) {
	int n;
	while(scanf("%d", &n)!=EOF){
		drawTri(n);
	}
	return 0;
}