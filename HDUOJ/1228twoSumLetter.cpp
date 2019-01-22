#include <iostream>

#include <string>
using namespace std;
int mp(string s){
	if(s=="zero")	return 0;
	if(s=="one")	return 1;
	if(s=="two")	return 2;
	if(s=="three")	return 3;
	if(s=="four")	return 4;
	if(s=="five")	return 5;
	if(s=="six")	return 6;
	if(s=="seven")	return 7;
	if(s=="eight")	return 8;
	if(s=="nine")	return 9;
	return -1;
}
int main(int argc, char *argv[]) {
	string s;

	int a = 0, b = 0;
	bool bflag;
	while(1){
		cin>>s;
		if(s=="+")	bflag = true;
		else if(s=="="){
			if(a==0&&b==0)	break;
			printf("%d\n", a+b);
			a = 0, b = 0;
			bflag = false;
		}
		else{
			if(bflag){
				b = b*10 + mp(s);
			}
			else{
				a = a*10 + mp(s);
			}
		}
	}
}