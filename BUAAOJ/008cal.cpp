#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	int a, b, c, d, e, f, g, h;
	int T;
	long long res;
	scanf("%d", &T);
	while(T--){
		scanf("%d%d%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f, &g, &h);
		res = (a*c)/b+(d*g*h)/(e*f);
		printf("%d\n", (int)res);
	}
	return 0;
}