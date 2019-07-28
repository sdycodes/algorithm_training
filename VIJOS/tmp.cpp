#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>

using namespace std;

struct BigInteger{
    const static int BASE = 100000000;
    const static int WIDTH = 8;
    vector<int> s;
    
    BigInteger(long long num = 0) {
        *this = num;
    }

    BigInteger operator= (long long num) {
        s.clear();
        do{
            s.push_back(num % BASE);
            num /= BASE;
        }while(num);
        return *this;
    }

    BigInteger operator= (const string& str) {
        s.clear();
        int x;
        int len = (str.length() - 1) / WIDTH + 1;
        for (int i = 0; i < len; i++) {
            int end = str.length() - i * WIDTH;
            int start = max(0, end - WIDTH);
            sscanf(str.substr(start, end - start).c_str(), "%d", &x);
            s.push_back(x);
        }
        return *this;
    }

    bool operator< (const BigInteger& b) const {
        if (s.size() < b.s.size()) {
            return true;
        } else if (s.size() >b.s.size()) {
            return false;
        } 
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] < b.s[i]) {
                return true;
            } else if (s[i] > b.s[i]) {
                return false;
            }
        }
        return false;
    }

    bool operator== (const BigInteger& b) const {
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

    bool operator<= (const BigInteger& b) const {
        return *this < b || *this == b;
    }

    bool operator> (const BigInteger& b) const {
        return !(*this <= b);
    }

    bool operator>= (const BigInteger& b) const {
        return !(*this < b);
    }

    bool operator!= (const BigInteger& b) const {
        return !(*this == b);
    }

    BigInteger operator+ (const BigInteger& b) const {
        BigInteger c;
        c.s.clear();
        for (int i = 0, g = 0;; i++) {
            if (g == 0 && i >= s.size() && i >= b.s.size()) {
                break;
            }
            int x = g;
            if (i < s.size()) {
                x += s[i];
            }
            if (i < b.s.size()) {
                x += b.s[i];
            }
            c.s.push_back(x % BASE);
            g = x % BASE;
        }
        return c;
    }

    BigInteger operator- (const BigInteger& b) const {
        BigInteger c;
        c.s.clear();
        for (int i = 0, g = 0;; i++) {
            if (g == 0 && i >= s.size() && i >= b.s.size()) {
                break;
            }
            long long x = g;
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
                x += BASE;
                c.s.push_back(x);
            }
        }
        return c;
    }

    BigInteger operator* (const BigInteger &b) const {
        BigInteger c;
        c.s.clear;
        int lena = s.size(), lenb = b.s.size(), lenc = lena + lenb;
        long long *buf = new long long[lenc];
        for (int i = 0; i < lenc; i++) {
            buf[i] = 0;
        }
        for (int i = 0; i < lena; i++) {
            for (int j = 0; j < lenb; j++) {
                buf[i + j] += s[i] * (long long)b.s[j];
                buf[i + j +1] += buf[i + j] / BASE;
                buf[i + j] %= BASE;
            }
        }
        for (int i = 0; i < lenc; i++) {
            c.s.push_back(buf[i]);
        }
        while(c.s.size() > 1 && c.s.back() == 0) {
            c.s.pop_back();
        }
        return c;
    }

    BigInteger operator/ (int b) const {
        BigInteger c;
        c.s.clear();
        long long down = 0;
        long long *buf = new long long[s.size()];
        for (int i = s.size() - 1; i >= 0; i--) {
            buf[i] = (down * BASE + s[i]) / b;
            down = (down * BASE + s[i]) % b;
        }
        for (int i = 0; i < s.size(); i++) {
            c.s.push_back(s[i]);
        }
         while(c.s.size() > 1 && c.s.back() == 0) {
            c.s.pop_back();
        }
        return c;
    }
    friend ostream& operator<< (ostream& out, const BigInteger& x) {
        out << x.s.back();
        for (int i = s.size() - 2; i >= 0; i--) {
            char buf[20];
            sprintf(buf, "%08d", s[i]);
            for (int j = 0; j < strlen(buf); j++) {
                out << buf[j];
            }
        }
        return out;
    }
    friend istream& operator>> (istream& in, BigInteger& x) {
        string s;
        if (!(in >> s)) {
            return in;
        }
        x = s;
        return in;
    }
};
