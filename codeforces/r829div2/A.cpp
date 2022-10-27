#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    int N;
    string S;
    cin >> N >> S;

    int tot_a = 0;
    int tot_b = 0;
    for(char c : S) {
        if(c == 'A') {
            tot_a++;
        } else {
            tot_b++;
        }
    }
    
    int cnt_a = 0;
    int cnt_b = 0;
    for(char c : S) {
        if(c == 'A') {
            cnt_a++;
        } else {
            if(tot_a - cnt_a < tot_b - cnt_b) {
                cout << "NO" << '\n';
                return;
            }
            cnt_b++;
        }
    }

    cout << "YES" << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    while(T--) {
        run_case();
    }
}
