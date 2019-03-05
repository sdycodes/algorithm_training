#include <stdio.h>
#include <stdlib.h>
using namespace std;
int r, y, g, n;
long long cur = 0;
int k[100005], t[100005];
void cal_state(int ps, long long rem, long long duration, int &cs, long long &crem){
	int mod = duration % (r+y+g);
	if(ps==1){
		if(mod-rem<0){
			cs = 1;
			crem = rem-mod;
		}
		else if(mod-rem-g<0){
			cs = 3;
			crem = g-(mod-rem);
		}
		else if(mod-rem-g-y<0){
			cs = 2;
			crem = y-(mod-rem-g);
		}
		else{
			cs = 1;
			crem = r-(mod-rem-g-y);
		}
	}
	else if(ps==2){
		if(mod-rem<0){
			cs = 2;
			crem = rem-mod;
		}
		else if(mod-rem-r<0){
			cs = 1;
			crem = r-(mod-rem);
		}
		else if(mod-rem-r-g<0){
			cs = 3;
			crem = g - (mod-rem-r);
		}
		else{
			cs = 2;
			crem = y-(mod-rem-r-g); 
		}
	}
	else{
		if(mod-rem<0){
			cs = 3;
			crem = rem-mod;
		}
		else if(mod-rem-y<0){
			cs = 2;
			crem = y-(mod-rem);
		}
		else if(mod-rem-y-r<0){
			cs = 1;
			crem = r-(mod-rem-y);
		}
		else{
			cs = 3;
			crem = g-(mod-rem-y-r); 
		}
	}
}
int main(int argc, char *argv[]) {
	
	scanf("%d%d%d", &r, &y, &g);
	scanf("%d", &n);
	int i;
	for(i=0;i<n;i++){
		scanf("%d%d", &k[i], &t[i]);
	}
	long long duration = 0, crem;
	int cs;
	for(i=0;i<n;i++){
		if(k[i]==0)
			duration += t[i];
		else {
			cal_state(k[i], t[i], duration, cs, crem);
			if(cs == 1)
				duration += crem;
			else if(cs==2)
				duration += (crem+r);
		}
	}
	printf("%lld", duration);
}