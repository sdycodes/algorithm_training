#include <stdio.h>

int s, d, res;
int a[12];
void enumer(int times, int pos){
	if(times==0){
		int sum1 = a[0]+a[1]+a[2]+a[3]+a[4];
		int sum2 = sum1-a[0]+a[5];
		int sum3 = sum2-a[1]+a[6];
		int sum4 = sum3-a[2]+a[7];
		int sum5 = sum4-a[3]+a[8];
		int sum6 = sum5-a[4]+a[9];
		int sum7 = sum6-a[5]+a[10];
		int sum8 = sum7-a[6]+a[11];
		int sum9 = sum1+a[5]+a[6]+sum8;
		if(sum1<0&&sum2<0&&sum3<0&&sum4<0&&sum5<0&&sum6<0&&sum7<0&&sum8<0){
			if(res<sum9)	res = sum9;
		}
		return;	
	}
	for(;pos<12;pos++){
		a[pos] = s;
		enumer(times-1, pos+1);
		a[pos] = -d;
	}
	return;
}
int main(int argc, char *argv[]) {
	while(scanf("%d%d", &s, &d)!=EOF){
		for(int i=0;i<12;i++)
			a[i] = -d;
		res = -1000;
		for(int i=1;i<=12;i++)
			enumer(i, 0);
		if(res>0)	printf("%d\n", res);
		else printf("Deficit\n");
	}	
}