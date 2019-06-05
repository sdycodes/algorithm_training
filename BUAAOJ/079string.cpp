#include <cstdio>
#include <iostream>
const long long n1 = 106104108106120;
const long long n2 = 120105104097110103;
const long long filter1 = 1000000000000000,filter2 = 1000000000000000000;

int main(int argc, char* argv[]) {
	char ch;
	while(std::cin>>ch){
		getchar();
		if(ch=='A'){
			int base = 0;
			int sum = 0;
			while((ch = getchar()) != '\n') {
				sum = sum * 2 + (ch - '0');
				base++;
				if (base == 8) {
					base = 0;
					printf("%c",sum);
					sum = 0;
				}
			}
		}else if (ch == 'B') {
			long long wait1 = 0, wait2 = 0;
			long long tem = 0;
			long long x, y;
			char old = '1';
			int firstPersonCord = 0; 
			int secondPersonCord = 0;
			int flag = 1;
			int getnum = 0;  //表示现在是否是一个读取数字的状态
			while((ch=getchar()) != '\n') {
				//每个字符用三位数表示一个字符
				//wait2表示的后6位字符，wait1表示后5位字符，也就是用来判断是否有人
				wait2 = (wait1 * 1000 + ch) % filter2;
				wait1 = wait2 % filter1;
				//最后5位数是jhljx 开始等待判断1的坐标firstPersonCord set 1
				if(wait1 == n1) {
					firstPersonCord = 1;
					secondPersonCord = 0;
					x = -1;
					y = -1;
				}
				//最后6位数是xihang 开始等待判断2的坐标secondPersonCord set 1
				if(wait2 == n2) {
					firstPersonCord = 0;
					secondPersonCord = 1;
					x = -1;
					y = -1;
				}
				//当前的数字有意义
				if(getnum && (firstPersonCord || secondPersonCord)) {
					//遇到# 数字结束 按照xy的顺序放到坐标上
					if (ch == '#') {
						if (x == -1) {
							x = tem;
						} else {
							y = tem;
						}
						getnum = 0;
					}
					//没有遇到#判断数字时候合法 不合法getnum set0
					if('0'<=ch&&ch<='9')tem=tem*16+ch-'0';
					else if('a'<=ch&&ch<='f')tem=tem*16+ch-'a'+10;
					else tem=0,getnum=0;
				}
				//坐标有意义 输出坐标
				if(x != -1 && y != -1 && (firstPersonCord||secondPersonCord)) {
					if(firstPersonCord) {
						printf("jhljx(%lld,%lld)",x,y);
					} else {
						printf("xihang(%lld,%lld)",x,y);
					}
					if(flag) {
						printf(" ");
					}
					flag = 0;
					x = -1; 
					y = -1;
				}
				//上一次和这一次构成0x 下面开始计数 getnum set1
				if(old == '0' && ch == 'x') {
					getnum = 1;
				}
				old = ch;
			}
			if(flag) {
				printf("nothing found!");
			}
		}
		printf("\n");
	}
}