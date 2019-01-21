#include <stdio.h>

//scanf 的返回值  如果遇到了文件结束会返回-1 EOF 否则返回成功读取的参数个数
//右对齐方法%nd n为对齐的位数 %-nd为左对齐 %0nd使用0补齐 否则是空格
//看清楚题意中要求的中间空行到底是两个之间还是每个之后

int main(int argc, char *argv[]) {
	int S, M;	
	while(scanf("%d%d", &S, &M)!=EOF){
		int cnt = 0;
		int tmp = 0;
		do{
			cnt++;
			tmp = (tmp+S)%M;
		}while(tmp!=0);
		if(cnt==M)	printf("%10d%10d    Good Choice\n\n", S, M);
		else	printf("%10d%10d    Bad Choice\n\n", S, M);
	}
	return 0;
}