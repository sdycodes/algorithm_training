#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> lines;

bool read_blocks() {
    lines.clear();
    string s;
    while(getline(cin, s)) {
        if (s != "") break;
    };
    do {
        if (s == "") break;
        lines.push_back(s);
    } while(getline(cin, s));
    return lines.size() > 0;
}

string process(string src) {
    // 去除空格
    int pos = 0;
    while(src[pos] == ' ') pos++;
    src = src.substr(pos);
    int em_deep = 0, link_deep = 0;
    string res= "";
    // 处理行内
    for (int i = 0; i < src.length(); i++) {
        if (src[i] == '_') {
            em_deep++;
            if (em_deep % 2) res += "<em>";
            else res += "</em>";
        } else if (src[i] == '[') {
            res += "<a href=\"";
            int ri = i;
            while(src[i] != ']') i++;
            string text = src.substr(ri + 1, i - ri - 1);
            i++;
            int rc = i;
            while(src[i] != ')') i++;
            string link = src.substr(rc + 1, i - rc - 1);
            int td = 0;
            string rest = "";
            for (int j = 0; j < text.size(); j++) {
                if (text[j] == '_') {
                    td++;
                    if (td % 2) rest += "<em>";
                    else rest += "</em>";
                } else {
                    rest += text[j];
                }
            }
            string resl = "";
            for (int j = 0; j < link.size(); j++) {
                if (link[j] == '_') {
                    td++;
                    if (td % 2) resl += "<em>";
                    else resl += "</em>";
                } else {
                    resl += link[j];
                }
            }
            res += resl;
            res += "\">";
            res += rest;
            res += "</a>";
        } else {
            res += src[i];
        }
    }
    return res;
}

int main() {
    #ifdef D
        freopen("data.in", "r", stdin);
    #endif
    while(read_blocks()) {
        string &line = lines[0];
        if (line[0] == '#') {
            int cnt = 1, pos = 1;
            while(line[pos] == '#') { pos++; cnt++; }
            string s = process(line.substr(pos));
            printf("<h%d>%s</h%d>\n", cnt, s.c_str(), cnt);
        } else if (line[0] == '*') {
            printf("<ul>\n");
            for (int i = 0; i < lines.size(); i++) {
                string& tl = lines[i];
                int pos = 1;
                while(tl[pos] == ' ') pos++;
                tl = tl.substr(pos);
                string s = process(tl);
                printf("<li>%s</li>\n", s.c_str());
            }
            printf("</ul>\n");
        } else {
            for (int i = 0; i < lines.size(); i++) {
                string s = process(lines[i]);
                if (i == 0) {
                    printf("<p>");
                }
                printf("%s", s.c_str());
                if (i == lines.size() - 1) {
                    printf("</p>");
                }
                printf("\n");
            }
        }
    }
    return 0;
}