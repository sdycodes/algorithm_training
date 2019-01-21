#include <stdio.h>
//没给范围 这个数字任意大  注意cnt==9的时候可能存在丢失 所以scanf放在else里面
//观察到特征 9个一循环
int main(int argc, char *argv[]) {
	int n;
	int cnt, res;
	char c;
	while(scanf("%c", &c)){
		if(c=='0')	break;
		n = 0;
		cnt = 0;
		res = 0;
		while(c!='\n'){
			if(cnt==9){
				cnt = 0;
				res += (n%9?n%9:9);
				res = (res%9?res%9:9);
				n = 0;
			}
			else{
				cnt++;
				n = (n*10)+(c-'0');
				scanf("%c", &c);
			}
		}
		res += (n%9?n%9:9);
		res = (res%9?res%9:9);
		printf("%d\n", res);
	}	
	return 0;
}