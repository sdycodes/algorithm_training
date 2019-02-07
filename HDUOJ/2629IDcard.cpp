#include <cstdio>
#include <string>
using namespace std;
int main(int argc, char *argv[]) {
	int T;
	string city;
	char s[30];
	scanf("%d", &T);
	while(T--){
		getchar();
		scanf("%s", s);
		if(s[0]=='3'&&s[1]=='3')	city = "Zhejiang";
		else if(s[0]=='1'&&s[1]=='1')	city = "Beijing";
		else if(s[0]=='7'&&s[1]=='1')	city = "Taiwan";
		else if(s[0]=='8'&&s[1]=='1')	city = "Hong Kong";
		else if(s[0]=='8'&&s[1]=='2')	city = "Macao";
		else if(s[0]=='5'&&s[1]=='4')	city = "Tibet";
		else if(s[0]=='2'&&s[1]=='1')	city = "Liaoning";
		else if(s[0]=='3'&&s[1]=='1')	city = "Shanghai";
		printf("He/She is from %s,and his/her birthday is on %c%c,%c%c,%c%c%c%c based on the table.\n", city.c_str(), s[10], s[11], s[12], s[13], s[6], s[7], s[8], s[9]);
	}
}