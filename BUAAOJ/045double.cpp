#include <cstdio>
#define eps 1e-6
using namespace std;
//一般float准确的数位是6位 范围 -3.40E+38 ～ +3.40E+38
//double准确的数位是15位 范围 -1.79E+308 ～ +1.79E+308

bool judge_ph(double a) {
	a += eps;   //这句话不可少  考虑到计算机存储误差1.5可能存成1.499999的情况 因为类型转化的时候直接截断
	for (int base = 1; base <= 10000; base *= 10) {
		if (((long long) a / base) % 10 != (long long)(a * base * 10) % 10) {
			return false;
		}
	}
	return true;
}
int main(int argc, char *argv[]) {
	double a;
	while(scanf("%lf", &a) != EOF) {
		if (judge_ph(a)) {
			printf("Yes\n");
		} else {
			printf("No\n");
		}
	}
	return 0;
}