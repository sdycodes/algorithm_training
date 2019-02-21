#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
	char s[105], sym[105];
	int vars[105];
	int spos, vpos;
	while(scanf("%s", s)!=EOF&&s[0]!='0'){
		int var[5];
		int can = 1;
		for(int i=0;i<=0x1f;i++){
			spos = 0;
			vpos = 0;
			var[0] = i&1;
			var[1] = i&(1<<1);
			var[2] = i&(1<<2);
			var[3] = i&(1<<3);
			var[4] = i&(1<<4);
			for(int j=strlen(s)-1;j>=0;j--){
				if(s[j]>='p'&&s[j]<='z')	vars[vpos++] = (var[s[j]-'p']>0?1:0);
				else{
					if(s[j]=='K'){
						vars[vpos-2] = vars[vpos-1]&&vars[vpos-2];
						vpos--;
					}
					else if(s[j]=='A'){
						vars[vpos-2] = vars[vpos-1]||vars[vpos-2];
						vpos--;
					}
					else if(s[j]=='N'){
						vars[vpos-1] = !vars[vpos-1];
					}
					else if(s[j]=='C'){
						vars[vpos-2] = vars[vpos-1]||!vars[vpos-2];
						vpos--;
					}
					else{
						vars[vpos-2] = (vars[vpos-1]==vars[vpos-2]);
						vpos--;
					}
				}
			}
			if(vars[0]==0){
				can = 0;
				break;
			}
		}
		if(can)	printf("tautology\n");
		else 	printf("not\n");
	}
}
