#include <stdio.h>
//状态压缩
//本质是组合数
//小状态数枚举
int board;
int change[16] = {0xc800, 0xe400, 0x7200, 0x3100, \
				  0x8c80, 0x4e40, 0x2720, 0x1310, \
				  0x08c8, 0x04e4, 0x0272, 0x0131, \
				  0x008c, 0x004e, 0x0027, 0x0013};

int flip(int times, int pos){
	if(times==0){					//没有翻转次数 检查是否完成
		if(board==0||board==0xffff)
			return 1;
		return 0;
	}
	for(;pos<16;pos++){				//可以翻  检查当前位置翻还是不翻
		board ^= change[pos];
		if(flip(times-1, pos+1))
			return 1;
		board ^= change[pos];
	}
	return 0;
}

int main(int argc, char *argv[]) {
	char tmp;
	board = 0;
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			board <<= 1;
			scanf("%c", &tmp);
			if(tmp=='w')
				board |= 1;
		}
		getchar();
	}
	int flag = 1;
	for(int i=0;i<=16;i++){	//最多翻16次 从小到大尝试
		if(flip(i, 0)){
			flag = 0;
			printf("%d\n", i);
			break;
		}
	}
	if(flag)	printf("Impossible\n");
	return 0;
}