#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	double a, b, c, d;
	char op;
	while(scanf("%lf%lf%lf%lf %c", &a, &b, &c, &d, &op) != EOF) {
		if (op == '+') {
			printf("%.2f %.2f\n", a + c, b + d);
		} else if (op == '-') {
			printf("%.2f %.2f\n", a - c, b - d);
		} else if (op == '*') {
			printf("%.2f %.2f\n", a*c - b*d, a*d + b*c);
		} else if (op == '/') {
			double mod = c * c + d * d;
			printf("%.2f %.2f\n", (a*c + b*d) / mod, (-a*d + b*c) / mod);
		} else {
			printf("ERROR:%c|", op);
		}
	}
}