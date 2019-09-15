#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cstring>

using namespace std;

struct Assis{
    int no, at, hp;
    bool isalive;
    Assis(int no=0, int at =0, int hp=0,bool isalive=false): no(no), at(at), hp(hp), isalive(isalive) {}
};

Assis board[2][8];
int pl, opl, hero[2];
void parse(string s) {
    if (s == "end") {
        opl = pl;
        pl = (pl + 1) % 2;
        return;
    }
    stringstream ss(s);
    string command;
    ss >> command;
    if (command == "summon") {
        int pos, at, hp;
        ss >> pos >> at >> hp;
        for (int i = 7; i > pos; i--) {
            board[pl][i] = board[pl][i - 1];
        }
        board[pl][pos] = Assis(0, at, hp, true);
        int cnt = 1;
        for (int i = 1; i <= 7; i++) {
            if (board[pl][i].isalive) {
                board[pl][i].no = cnt++;
            }
        }
    } else {
        int attacker, defender;
        ss >> attacker >> defender;
        int posa = 0, posb = 0;
        for (int i = 1; i <= 7; i++) {
            if (!posa && board[pl][i].isalive && board[pl][i].no == attacker) {
                posa = i;
            }
            if (defender && !posb && board[opl][i].isalive && board[opl][i].no == defender) {
                posb = i;
            }
        }
        if (!posb) {
            hero[opl] -= board[pl][posa].at;
        } else {
            board[opl][posb].hp -= board[pl][posa].at;
            board[pl][posa].hp -= board[opl][posb].at;
        }
        if (board[opl][posb].hp <= 0) {
            board[opl][posb].isalive = false;
            for (int i = posb +  1; i <= 7; i++) {
                if (board[opl][i].isalive) {
                    board[opl][i].no -= 1;
                }
            }
        }
        if (board[pl][posa].hp <= 0) {
            board[pl][posa].isalive = false;
            for (int i = posa + 1; i <= 7; i++) {
                if (board[pl][i].isalive) {
                    board[pl][i].no -= 1;
                }
            } 
        }
    }
    return;
}
int main() {
    #ifdef D
        freopen("data.in", "r", stdin);
    #endif
    pl = 0;
    hero[0] = 30;
    hero[1] = 30;
    memset(board, 0, sizeof(board));
    int n;
    cin >> n;
    cin.get();
    while(n--) {
        string s;
        getline(cin, s);
        parse(s);
    }
    if (hero[0] > 0 && hero[1] <= 0) {
        cout << "1\n";
    } else if (hero[0] <= 0 && hero[1] > 0) {
        cout << "-1\n";
    } else {
        cout << "0\n";
    }
    cout << hero[0] << endl;
    int cnt = 0;
    for (int i = 1; i <= 7; i++) {
        if (board[0][i].isalive) cnt++;
    }
    cout << cnt << " ";
    for (int i = 1; i <= 7; i++) {
        if (board[0][i].isalive) cout << board[0][i].hp << " ";
    }
    cout << "\n";

    cout << hero[1] << endl;
    cnt = 0;
    for (int i = 1; i <= 7; i++) {
        if (board[1][i].isalive) cnt++;
    }
    cout << cnt << " ";
    for (int i = 1; i <= 7; i++) {
        if (board[1][i].isalive) cout << board[1][i].hp << " ";
    }
    cout << "\n";
    return 0;
}