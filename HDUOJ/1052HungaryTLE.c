#include <stdio.h>
#include <string.h>

int a[1005], b[1005];
int match[1005];
int vis[1005];
int get[1005];
int n;

int hungary(int cur){
	for(int i=0;i<n;i++){
		if(a[cur]>b[i] && vis[i]==0){
			vis[i] = 1;
			if(match[i]==-1||hungary(match[i])){
				match[i] = cur;
				get[cur] = 1;
				return 1;
			}
		}
	}
	return 0;
}

int match2(){
	for(int i=0;i<n;i++){
		if(get[i]==0){
			for(int j=0;j<n;j++){
				if(match[j]==-1&&a[i]==b[j]){
					get[i] = 1;
					match[j] = i;
				}
			}
		}
	}
	return 0;
}


int main(int argc, char *argv[]) {
	while(scanf("%d", &n)&&n!=0){
		//读入数据
		for(int i=0;i<n;i++)
			scanf("%d", &a[i]);
		for(int i=0;i<n;i++)
			scanf("%d", &b[i]);
		//初始化
		for(int i=0;i<n;i++)
			match[i] = -1;

		//求解
		for(int i=0;i<n;i++){
			memset(vis, 0, sizeof(vis));
			memset(get, 0, sizeof(get));
			hungary(i);	//必须从所有人出发尝试一遍 因为可能出现第一个人匹配成功直接返回的情况
		}
		match2();
		
		//计算并输出收益
		int r = 0;
		for(int i=0;i<n;i++){
			if(match[i]>=0){
				if(a[match[i]]>b[i])
					r += 200;
			}
			else 
				r-=200;
		}
		printf("%d\n", r);
	}	
}