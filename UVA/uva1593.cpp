#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <sstream>
#include <cstring>

using namespace std;

vector<string> split(const string& str, const string& delim) {  
	vector<string> res;  
	if("" == str) return res;  
	//先将要切割的字符串从string类型转换为char*类型  
	char * strs = new char[str.length() + 1] ; //不要忘了  
	strcpy(strs, str.c_str());   
 
	char * d = new char[delim.length() + 1];  
	strcpy(d, delim.c_str());  
 
	char *p = strtok(strs, d);  
	while(p) {  
		string s = p; //分割得到的字符串转换为string类型  
		res.push_back(s); //存入结果数组  
		p = strtok(NULL, d);  
	}  
	return res;  
} 
vector<string> split2(const string& str, const string& delim) {
    int i = 0;
    vector<string> res;
    while(i < str.length()) {
        while(i < str.length() && str[i] == ' ') {
            i++;
        }
        int j = i + 1;
        while(j < str.length() && str[j] != ' ') {
            j++;
        }
        if (i < str.length()) {
            res.push_back(str.substr(i, j - i));
        }
        i = j + 1;
    }
    return res;
}

int main() {
    #ifdef D
        cout << "DEBUG mode" << endl;
        freopen("data.in", "r", stdin);
    #endif
    //ios::sync_with_sdtio(false);
    vector<vector<string> > codes;
    string s;
    int maxlen[200];
    memset(maxlen, 0, sizeof(maxlen));
    while(getline(cin, s)) {
        vector<string> words = split2(s, " ");
        for (int i = 0; i < words.size(); i++) {
            if (words[i].length() > maxlen[i]) {
                maxlen[i] = words[i].length();
            }
        }
        codes.push_back(words);
    }
    for (int i = 0; i < codes.size(); i++) {
        for (int j = 0; j < codes[i].size(); j++) {
            if (j == codes[i].size() - 1) {
                printf("%s\n", codes[i][j].c_str());
            } else {
                printf("%s", codes[i][j].c_str());
                int pad = codes[i][j].length();
                while(pad < maxlen[j] + 1) {
                    putchar(' ');
                    pad++;
                }
            }
        }
    }
    return 0;
}