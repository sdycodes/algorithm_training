#include <stdio.h>

int main(int argc, char *argv[]) {
	//1089
	/*
	int a, b;
	while(scanf("%d%d", &a, &b)!=EOF)
		printf("%d\n", a+b);
	*/
	//1090
	/*
	int T,a ,b;
	scanf("%d", &T);
	while(T--){
		scanf("%d%d", &a, &b);
		printf("%d\n", a+b);
	}
	*/
	//1091
	/*
	int a, b;
	while(scanf("%d%d", &a, &b)&&!(!a&&!b))
		printf("%d\n", a+b);
	*/
	//1092
	/*
	int n;
	while(scanf("%d", &n)&&n){
		int res = 0, tmp;
		for(int i=0;i<n;i++){
			scanf("%d", &tmp);
			res += tmp;
		}
		printf("%d\n", res);
	}
	*/
	//1093
	/*
	int T;
	scanf("%d", &T);
	while(T--){
		int n;
		scanf("%d", &n);
		int res = 0, tmp;
		for(int i=0;i<n;i++){
			scanf("%d", &tmp);
			res += tmp;
		}
		printf("%d\n", res);
	}
	*/
	//1094
	/*
	int n;
	while(scanf("%d", &n)!=EOF){
		int res = 0, tmp;
		for(int i=0;i<n;i++){
			scanf("%d", &tmp);
			res += tmp;
		}
		printf("%d\n", res);
	}
	*/
	//1095
	/*
	int a, b;
	while(scanf("%d%d", &a, &b)!=EOF)
		printf("%d\n\n", a+b);
	*/
	//1096
	/*
	int T;
	scanf("%d", &T);
	while(T--){
		int n;
		scanf("%d", &n);
		int res = 0, tmp;
		for(int i=0;i<n;i++){
			scanf("%d", &tmp);
			res += tmp;
		}
		printf("%d\n", res);
		if(T!=0)	printf("\n");
	}
	*/
}