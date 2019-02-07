#include <stdio.h>
int dig16[5], dig12[5], dig10[5];
int pos16, pos12, pos10;
int sumArr(int a[], int len){
	int sum = 0;
	for(int i=0;i<len;i++)
		sum += a[i];
	return sum;
}
void converse(int n){
	pos16 = 0;
	pos12 = 0;
	pos10 = 0;
	int rec = n;
	while(n){
		dig16[pos16++] = n%16;
		n /= 16;
	}
	n = rec;
	while(n){
		dig12[pos12++] = n%12;
		n /= 12;
	}
	n = rec;
	while(n){
		dig10[pos10++] = n%10;
		n /= 10;
	}
}

int main(int argc, char *argv[]) {
	/*
	for(int i=1000;i<=9999;i++){
		converse(i);
		int a = sumArr(dig10, pos10);
		int b = sumArr(dig12, pos12);
		int c = sumArr(dig16, pos16);
		if(a==b&&b==c)	printf("%d\n", i);
	}*/
	printf("2992\n2993\n2994\n2995\n2996\n2997\n2998\n2999\n4470\n4471\n4472\n4473\n4474\n4475\n4970\n4971\n4972\n4973\n4974\n4975\n5460\n5461\n5462\n5463\n5464\n5465\n5466\n5467\n5468\n5469\n5960\n5961\n5962\n5963\n6456\n6457\n6458\n6459\n7440\n7441\n7442\n7443\n7444\n7445\n7446\n7447\n7448\n7449\n7940\n7941\n7942\n7943\n8436\n8437\n8438\n8439\n9424\n9425\n9426\n9427\n9428\n9429\n9924\n9925\n9926\n9927\n9928\n9929\n");
}