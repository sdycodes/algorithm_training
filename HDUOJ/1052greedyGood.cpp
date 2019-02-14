#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
	int a[1005], b[1005], n;
	while(scanf("%d", &n)&&n!=0){
		//读入数据
		for(int i=0;i<n;i++)
			scanf("%d", &a[i]);
		for(int i=0;i<n;i++)
			scanf("%d", &b[i]);
		sort(a, a+n);
		sort(b, b+n);
		
		int ft = n-1, st = 0, fk = n-1, sk = 0;
		int tian = 0;
		while(ft!=st){
			if(a[ft]>b[fk]){	//比最快的 tian的更快 直接比
				tian++;
				ft--;
				fk--;
			}
			else if(a[st]>b[sk]){//比最慢的 tian的更快 直接比
				tian++;
				st++;
				sk++;
			}
			else if(a[st]<b[fk]){//king最快的更快 tian用最慢的消耗之
				tian--;
				st++;
				fk--;
			}
			else 
				break;
		}
		if(a[ft]>b[fk])
			tian++;
		else if(a[ft]<b[fk])
			tian--;
		printf("%d\n", 200*(tian));
	}
}