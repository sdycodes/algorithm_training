#include <cstdio>
using namespace std;
int main(int argc, char *argv[]) {
	char begin, end;
	while(scanf("%c%c", &begin, &end) != EOF) {
		getchar();
		if (begin <= end) {
			for (char c = begin; c <= end; c++) {
				printf("%c", c);
			}
			printf("\n");
		}
		else if (begin > end) {
			if (begin <= 'z' && begin >= 'a') {
				for (char c = begin; c <= 'z'; c++) {
					printf("%c", c);
				}
				for (char c = 'a'; c <= end; c++) {
					printf("%c", c);
				}
				printf("\n");
			} else{
				for (char c = begin; c <= 'Z'; c++) {
					printf("%c", c);
				}
				for (char c = 'A'; c <= end; c++) {
					printf("%c", c);
				}
				printf("\n");
			}
		} 
	}
}