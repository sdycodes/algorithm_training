#include <iostream>

using namespace std;


int main(int argc, char *argv[]) {
	int T;
	scanf("%d", &T);
	while(T--){
		int n;
		scanf("%d", &n);
		int sum = 0;
		while(n){
			n /= 5;
			sum += n;
		}
		printf("%d\n", sum);
	}
}