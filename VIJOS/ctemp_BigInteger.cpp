#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
//不靠谱
struct BigInteger {
    static const int BASE = 100000000;
    static const int WIDTH = 8;
    vector<int> s;
    int sign;

    BigInteger(long long num = 0) { 
        *this = num; 
    } 

    // 构造函数 从数字构造
    BigInteger operator = (long long num) { // 赋值运算符
        s.clear();
        if (num > 0) {
            sign = 1;
        } else if (num < 0){
            sign = -1;
            num *= -1;
        } else {
            sign = 0;
        }
        do {
            s.push_back(num % BASE);
            num /= BASE;
        } while(num > 0);
        return *this;
    }
    
    //从字符串构造
    BigInteger operator = (const string& st) { // 赋值运算符
        s.clear();
        string str;
        if (st[0] == '-') {
            sign = -1;
            str = st.substr(1);
        } else {
            sign = 1;
            str= st;
        }
        int x;
        int len = (str.length() - 1) / WIDTH + 1;
        for(int i = 0; i < len; i++) {
            int end = str.length() - i * WIDTH;
            int start = max(0, end - WIDTH);
            //stoi只能是整形范围
            sscanf(str.substr(start, end - start).c_str(), "%d", &x);
            s.push_back(x);
        }
        if (s.size() == 1 && s[0] == 0) {
            sign = 0;
        }
        return *this;
    }

    //从大整数构造
    BigInteger operator = (const BigInteger& b) {
        s.clear();
        sign = b.sign;
        for (int i = 0; i < b.s.size(); i++) {
            s.push_back(b.s[i]);
        }
        return *this;
    }

    //绝对值函数
    BigInteger abs() const {
        BigInteger c;
        c = *this;
        c.sign = 1;
        if (s.size() == 1 && s[0] == 0) {
            c.sign = 0;
        }
        return c;
    }

    //比较大小 六个比较运算符 其实只需要写两个< ==
    bool operator < (const BigInteger& b) const {
        //异号 
        if (sign != b.sign) {
            return sign < b.sign;
        } 
        //同号
        //都是0
        if (sign == 0 && b.sign == 0) {
            return false;
        }
        //不一样长 
        if (s.size() != b.s.size()) {
            return sign * (s.size() - b.s.size()) < 0;
        } 
        //一样长
        int i = s.size() - 1;
        while(i >= 0 && s[i] == b.s[i]) {
            i--;
        }
        return (s[i] - b.s[i]) * sign < 0;
    }

    bool operator == (const BigInteger& b) const {
        if (sign != b.sign || s.size() != b.s.size()) {
            return false;
        } 
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != b.s[i]) {
                return false;
            }
        }
        return true;
    }

    bool operator <= (const BigInteger& b) const {
        return *this < b || *this == b;
    }

    bool operator > (const BigInteger& b) const {
        return !(*this <= b);
    }

    bool operator >= (const BigInteger& b) const {
        return !(*this < b);
    }
    
    bool operator != (const BigInteger& b) const {
        return !(*this == b);
    }

    //四则运算
    BigInteger operator + (const BigInteger& b) const {
        BigInteger c;
        c.s.clear();
        if (sign == 0) {
            c = b;
            return c;
        } else if (b.sign == 0) {
            c = (*this);
            return c;
        }
        //同号 符号不变 绝对值相加
        if (sign == b.sign) {
            c.sign = sign;
            //g是进位
            for(int i = 0, g = 0; ; i++) {
                if(g == 0 && i >= (int)s.size() && i >= (int)b.s.size()) {
                    break;
                }
                int x = g;
                if(i < (int)s.size()) {
                    x += s[i];
                }
                if(i < (int)b.s.size()) {
                    x += b.s[i];
                }
                c.s.push_back(x % BASE);
                g = x / BASE;
            }
        } else {
            //异号 取绝对值大的符号 绝对值大-绝对值小
            BigInteger absa = (*this).abs();
            BigInteger absb = b.abs();
            if (absa == absb) {
                return BigInteger(0);
            } else if (absa > absb) {
                c = absa - absb;
                c.sign = (*this).sign;
                return c;
            } else {
                c = absb - absa;
                c.sign = b.sign;
            }
        }
        return c;
    }

    BigInteger operator - (const BigInteger& b) const {
        BigInteger c;
        c.s.clear();
        if (b.sign == 0) {
            c = (*this);
            return c;
        } else if (sign == 0) {
            c = b;
            c.sign *= -1;
            return c;
        }
        BigInteger absa = (*this).abs();
        BigInteger absb = b.abs();
        if ((*this).sign != b.sign) {
            //异号 符号是被减数的符号 然后绝对值相加
            c = absa + absb;
            c.sign = (*this).sign;
        } else {
            vector<int> sa, sb;
            //同号 看绝对值定符号 大减小
            if (absa == absb) {
                return BigInteger(0);
            } else if (absa > absb) {
                c.sign = (*this).sign;
                sa = s;
                sb = b.s;
            } else {
                c.sign = -(*this).sign;
                sa = b.s;
                sb = s;
            }
            for (int i = 0, g = 0;;i++) {
                if (g == 0 && i >= sa.size() && i >= sb.size()) {
                    break;
                }
                int x = g;
                g = 0;
                if (i < sa.size()) {
                    x += sa[i]; 
                } else {
                    break;
                }
                if (i < sb.size()) {
                    x -= sb[i];
                }
                if (x < 0)  {
                    g = -1;
                    x += BASE;
                }
                c.s.push_back(x % BASE);
            }
        }
        return c;
    }

    BigInteger operator * (const BigInteger& b){
        BigInteger c;
        if (sign == 0 || b.sign == 0) {
            return BigInteger(0);
        }
        c.sign = (*this).sign * b.sign;
        c.s.clear();
        int lena=(int)this->s.size(),lenb=(int)b.s.size(),lenc=lena+lenb-1;
        long long *buf = new long long[lenc+1];
        for(int i=0;i<lenc+1;i++) {
            buf[i]=0;
        }
        for(int i=0;i<lena;i++) {
            for(int j=0;j<lenb;j++){
                buf[i+j]+=(this->s[i])*((long long)b.s[j]);
                buf[i+j+1]+=buf[i+j]/BASE;
                buf[i+j]=buf[i+j]%BASE;
            }
        }
        for(int i=0;i<lenc;i++) {
            c.s.push_back(buf[i]);
        }
        if(buf[lenc]) {
            c.s.push_back(buf[lenc]);
        }
        return c;
    }
 
    BigInteger operator * (const int& x) {
        BigInteger res(x);
        return *this * res;
    }

    BigInteger operator / (const int &b) const {
        BigInteger c;
        long long down = 0;
        for (int i = s.size() - 1; i >= 0; i --) {
            c.s[i] = (s[i] + down * BASE) / b;
            down = (s[i] + down * BASE) % b;
        }
        return c;
    }

    int operator % (const int &b) const {
        int down = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            down = (s[i] + down * BASE) % b;
        }
        return down;
    }
    friend ostream& operator << (ostream &out, const BigInteger& x) {
        if (x.sign == -1) {
            out << "-";
        }
        out << x.s.back();
        for(int i = (int)x.s.size()-2; i >= 0; i--) {
            char buf[20];
            sprintf(buf, "%08d", x.s[i]);
            for(int j = 0; j < strlen(buf); j++) out << buf[j];
        }
        return out;
    }

    friend istream& operator >> (istream &in, BigInteger& x) {
        string s;
        if(!(in >> s)) return in;
        x = s;
        return in;
    }

};

int main() {
    //freopen("data.in", "r", stdin);
    BigInteger a, b;
    while(cin >> a >> b) {
        cout << a + b << " " << a - b << " " << a * b << endl;
    }
    return 0;
}