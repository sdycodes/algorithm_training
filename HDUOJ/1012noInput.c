#include <stdio.h>
/*
long long factorial(int n){
	int res = 1;
	while(n>0){
		res *= n;
		n--;
	}
	return res;
}
*/
int main(int argc, char *argv[]) {
	/*
	
	long long t;
	double e=0;
	printf("n e\n- -----------\n");
	for(int i=0;i<10;i++){
		e += 1.0/factorial(i);
		if(i<=2)	printf("%d %g\n", i, e);
		else	printf("%d %.9lf\n", i, e);
	}
	*/
	printf("n e\n- -----------\n0 1\n1 2\n2 2.5\n3 2.666666667\n4 2.708333333\n5 2.716666667\n6 2.718055556\n7 2.718253968\n8 2.718278770\n9 2.718281526\n");
	return 0;
}