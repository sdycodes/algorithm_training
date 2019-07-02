#include <stdio.h>
//2） A中不超过1500元的部分，税率3%；
//　　3） A中超过1500元未超过4500元的部分，税率10%；
//　　4） A中超过4500元未超过9000元的部分，税率20%；
//　　5） A中超过9000元未超过35000元的部分，税率25%；
//　　6） A中超过35000元未超过55000元的部分，税率30%；
//　　7） A中超过55000元未超过80000元的部分，税率35%；
//　　8） A中超过80000元的部分，税率45%；

int after_tax(int S) {
	if (S <= 3500) {
		return S;
	}
	int A = S - 3500;
	int tax = 0;
	int step[7] = {0, 1500, 4500, 9000, 35000, 55000, 80000};
	int ratio[7] = {3, 10, 20, 25, 30, 35, 45};
	for (int i = 1; i < 7; i++) {
		if (A <= step[i]) {
			tax += ((A - step[i - 1]) / 100 * ratio[i - 1]);
			break;
		} else {
			tax += ((step[i] - step[i - 1]) / 100 * ratio[i - 1]);
		}
	}
	if (A > step[6]) {
		tax += ((A - step[6]) / 100 * ratio[6]);
	}
	return S - tax;
}

int main(int argc, char *argv[]) {
	int S;
	scanf("%d", &S);
	after_tax(10000);
	for (int i = 100; i <= 100000; i += 100) {
		if (after_tax(i) == S) {
			printf("%d", i);
			return 0;
		}
	}
	return 0;
}