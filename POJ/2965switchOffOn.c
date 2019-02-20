#include <stdio.h>
int board;
int mod[16] = {0xf888, 0xf444, 0xf222, 0xf111, \
				0x8f88, 0x4f44, 0x2f22, 0x1f11, \
				0x88f8, 0x44f4, 0x22f2, 0x11f1, \
				0x888f, 0x444f, 0x222f, 0x111f};
				
int turn(int times, int pos){
	if(times==0){
		if((board&0x0000ffff)==0xffff)
			return 1;
		return 0;
	}
	for(;pos<16;pos++){
		board ^= mod[pos];
		board |= (0x80000000>>pos);
		if(turn(times-1, pos+1))
			return 1;
		board ^= mod[pos];
		board ^= (0x80000000>>pos);
	}
	return 0;
}
int main(int argc, char *argv[]) {
	char tmp;
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			scanf("%c", &tmp);
			board <<= 1;
			if(tmp=='-')
				board |= 1;
		}
		getchar();
	}
	for(int i=0;i<=16;i++){
		if(turn(i, 0)){
			printf("%d\n", i);
			for(int j=0;j<16;j++)
				if( ( (0x80000000>>j) & board) != 0)
					printf("%d %d\n", (j/4)+1, (j%4)+1);
			break;
		}
	}
	return 0;
}