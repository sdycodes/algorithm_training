#include <stdio.h>
int a[2005], b[2005],c[2005], d[2005];
int max(int a, int b){
	return a>b?a:b;
}
int min(int a,  int b){
	return a<b?a:b;
}
int main(int argc, char *argv[]) {
	int n;
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		scanf("%d%d", &a[i], &b[i]);
	}
	for(int i=0;i<n;i++){
		scanf("%d%d", &c[i], &d[i]);
	}
	int res = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(b[i]<=c[j] || a[i]>=d[j])
				continue;
			else{
				res += (min(b[i], d[j])-max(a[i], c[j]));
			}
		}
	}
	printf("%d", res);
}