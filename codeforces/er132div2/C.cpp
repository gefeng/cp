#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

void run_case() {
    string s = "";
    cin >> s;

    int n = s.length();
    int cnt_o = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == '(') {
            cnt_o++;
        }
    } 

    if(cnt_o == n / 2) {
        cout << "YES" << '\n';
        return;
    }
    
    int rep_open = n / 2 - cnt_o;
    int cnt_q = 0;
    cnt_o = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == '?') {
            cnt_q++;
            if(cnt_q < rep_open || cnt_q == rep_open + 1) {
                cnt_o++;
            } else {
                cnt_o--;
            }
        } else if(s[i] == '(') {
            cnt_o++;
        } else {
            cnt_o--;
        }

        if(cnt_o < 0) {
            cout << "YES" << '\n';
            return;
        }
    }

    cout << (cnt_o == 0 ? "NO" : "YES") << '\n';
}

int main() {
    ios::sync_with_stdio(false);        // de-sync with c stream
    cin.tie(0);                         // disable flushing of std::cout
    
    int _t = 0;
    cin >> _t;
    while(_t-- > 0) {
        run_case();
    }
}
