#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
//排列和组合的全面训练
using namespace std;
char cand[15];
vector<string> c5;
vector<string> fc5;
char temp[5];

void comb(int n, int k, int cur, int deep){
	if(deep>=k){
		c5.push_back(temp);
	}
	else{
		for(int i=cur;i<n;i++){
			temp[deep] = cand[i];	//对当前deep位置尝试cur之后的所有可能性
			comb(n, k, i+1, deep+1);	//因为取的顺序是从前向后  所以取了cur之后的某一个 deep之后的只能从cur后面取
		}
	}
}

void permutation(int k, int m)
{
	int i,j;
	if(k == m)
		fc5.push_back(temp);
	else{
		for(j=k;j<=m;j++){
			char t = temp[j];
			temp[j] = temp[k];
			temp[k] = t;
			permutation(k+1, m);	//排列有顺序 所以还要多一个交换
			t = temp[j];
			temp[j] = temp[k];
			temp[k] = t;
		}
	}
}
int main(int argc, char *argv[]) {
	int tar;
	int v, w, x, y, z;
	while(scanf("%d%s", &tar, cand)){
		if(tar==0&&cand[0]=='E'&&cand[1]=='N'&&cand[2]=='D'&&cand[3]=='\0')	break;
		c5.clear();
		fc5.clear();
		comb(strlen(cand), 5, 0, 0);
		for(int i=0;i<(int)c5.size();i++){
			strcpy(temp, c5[i].c_str());
			permutation(0, 4);
		}
		sort(fc5.begin(), fc5.end());
		int i;
		for(i=(int)fc5.size()-1;i>=0;i--){
			v = fc5[i][0]-'A'+1;
			w = fc5[i][1]-'A'+1;
			x = fc5[i][2]-'A'+1;
			y = fc5[i][3]-'A'+1;
			z = fc5[i][4]-'A'+1;
			if(tar==v - w*w + x*x*x - y*y*y*y + z*z*z*z*z){
				printf("%s\n", fc5[i].c_str());
				break;
			}
		}
		if(i==-1)
			printf("no solution\n");
	}
}