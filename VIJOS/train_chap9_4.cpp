#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>

using namespace std;

struct BigInteger{
    vector<int> s;
    static const int BASE = 100000000;
    static const int WIDTH = 8;
    //注意这里的参数默认值 否则系统找不到默认的构造方法
    BigInteger(long long num = 0) {
        *this = num;
    }
    
    BigInteger operator = (long long num) {
        //注意这里的细节 do while 防止0的时候没有
        //细节2 clear不能少 防止重复使用
        s.clear();
        do {
            s.push_back(num % BASE);
            num /= BASE;
        } while(num > 0);
        return *this;  //返回值不要忘了！！！
    }

    BigInteger operator= (const string& str) {
        s.clear(); 
        int x;
        //细节注意这里的宽度计算  上取整的方法 
        int len = (str.length() - 1) / WIDTH + 1;
        for (int i = 0; i < len; i++) {
            //注意end 是取不到的 start是能取到的
            int end = str.length() - i * WIDTH;
            int start = max(0, end - WIDTH);
            sscanf(str.substr(start, end - start).c_str(), "%d", &x);
            s.push_back(x);
        }
        return *this;
    } 

    BigInteger operator= (const BigInteger& b) {
        s.clear();
        for (int i = 0; i < b.s.size(); i++) {
            s.push_back(b.s[i]);
        }
        return *this;
    }

    BigInteger operator+ (const BigInteger& b) const {
        BigInteger c;
        //注意先clear 因为默认的里面有个0
        c.s.clear();
        for (int i = 0, g = 0 ;;i++) {
            if (g == 0 && i >= s.size() && i >= b.s.size()) {
                break;
            }
            int x = g;
            if (i < (int)s.size()) {
                x += s[i];
            }
            if (i < (int)b.s.size()) {
                x += b.s[i];
            }
            c.s.push_back(x % BASE);
            g = x / BASE;
        }
        return c;
    }

    BigInteger operator - (const BigInteger &b) const {
        BigInteger c;
        long long x;
        c.s.clear();
        for (int i = 0, g = 0;; i++) {
            if (g == 0 && i >= s.size() && i >= b.s.size()) {
                break;
            }
            x = g;
            g = 0;
            if (i < s.size()) {
                x += s[i];
            }
            if (i < b.s.size()) {
                x -= b.s[i];
            }
            if (x >= 0) {
                c.s.push_back(x);
            } else {
                g = -1;
                c.s.push_back(BASE + x);
            }
        }
        return c;
    }

    bool operator < (const BigInteger &b) const {
        if (s.size() < b.s.size()) {
            return true;
        } else if (s.size() > b.s.size()) {
            return false;
        } else {
            for (int i = s.size() - 1; i >= 0; i--) {
                if (s[i] > b.s[i]) {
                    return false;
                } else if (s[i] < b.s[i]) {
                    return true;
                }
            }
        }
        return false;
    }

    bool operator == (const BigInteger &b) const {
        if (s.size() != b.s.size()) {
            return false;
        }
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != b.s[i]) {
                return false;
            }
        }
        return true;
    }

    bool operator <= (const BigInteger &b) const {
        return *this < b || *this == b;
    }

    bool operator > (const BigInteger &b) const {
        return !(*this <= b);
    }

    bool operator >= (const BigInteger &b) const {
        return !(*this < b);
    }

    bool operator != (const BigInteger &b) const {
        return !(*this == b);
    }

    BigInteger operator * (const BigInteger& b) const {
        BigInteger c;
        //注意lenc的长度最大是lena + lenb
        int lena = (int)s.size(), lenb = (int)b.s.size(), lenc = lena + lenb;
        long long *buf = new long long[lenc];
        //细节 注意初始化 而且buf的类型是long long
        for(int i = 0; i < lenc; i++) {
            buf[i] = 0;
        }
        for (int i = 0; i < lena; i++) {
            for (int j = 0; j < lenb; j++) {
                //细节 注意类型转化!!!!!
                buf[i + j] += (s[i] * (long long)b.s[j]);
                buf[i + j + 1] += (buf[i + j] / BASE);
                buf[i + j] %= BASE;
            }
        }
        //注意构造的c默认是0 所以已经有一个0垫底了 先清除
        c.s.clear();
        for (int i = 0; i < lenc; i++) {
            c.s.push_back(buf[i]);
        }
        //很可能有前导零，所以必须要去除，但是还要注意保证size>1防止最后一个0被弹掉
        while(c.s.back() == 0 && c.s.size() > 1) {
            c.s.pop_back();
        }
        return c;
    }

    BigInteger operator/ (int b) const {
        BigInteger c;
        int* buf = new int[s.size()];
        c.s.clear();
        long long down = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            buf[i] = (down * BASE + s[i]) / b;
            down = (s[i] + down * BASE) % b;
        }
        for (int i = 0; i < s.size(); i++) {
            c.s.push_back(buf[i]);
        }
        while(c.s.back() == 0 && c.s.size() > 1) {
            c.s.pop_back();
        }
        return c;
    }

    friend ostream& operator << (ostream& out, const BigInteger& x) {
        //细节 现输出一个back因为这个不需要padding
        out << x.s.back();
        for (int i = x.s.size() - 2; i >= 0; i--) {
            //每个中间部分的输出 使用sprintf控制格式更方便
            char buf[20];
            sprintf(buf, "%08d", x.s[i]);
            //注意这里需要include cstring
            for (int j = 0; j < strlen(buf); j++) {
                out << buf[j];
            }
        }
        //注意返回值是ostream&
        return out;
    }

    friend istream& operator >> (istream& in, BigInteger& x) {
        string s;
        if (!(in >> s)) {
            return in;
        }
        x = s;
        //注意返回值类型是istream&
        return in;
    }
};

int main() {
    BigInteger n;
    BigInteger THREE = BigInteger(3);
    cin >> n;
    BigInteger l = BigInteger(0);
    BigInteger r = n;
    while(l < r) {
        BigInteger m = (l + r) / 2;
        if (m == l) {
            break;
        }
        if (m * m * m + m * m + THREE * m <= n){
            l = m;
        } else {
            r = m;
        }
    }
    cout << l << endl;
    return 0;
}