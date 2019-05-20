#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	double a, b;
	while(scanf("%lf%lf", &a, &b) != EOF) {
		if (a - b >= 0.0000001) {
			printf("woshibukezhanshengde\n");
		} else if (a - b <= -0.0000001) {
			printf("wohenbaoqian\n");
		} else {
			printf("nakezhenchun\n");
		}
	}
}