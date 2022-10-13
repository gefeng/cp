#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;
using LL = long long;

void run_case() {
    int Q;
    cin >> Q;

    vector<bool> ans(Q, false);
    array<LL, 26> cnt_a{0LL};
    array<LL, 26> cnt_b{0LL};
    cnt_a[0]++;
    cnt_b[0]++;
    LL tot_a = 0LL;
    LL tot_b = 0LL;
    for(int i = 0; i < Q; i++) {
        int D, K;
        string X;
        cin >> D >> K >> X;

        if(D == 1) {
            for(char c : X) {
                cnt_a[c - 'a'] += K;
                tot_a += K;
            }
        } else {
            for(char c : X) {
                cnt_b[c - 'a'] += K;
                tot_b += K;
            }
        }

        int max_t = 0;
        for(int j = 25; j >= 0; j--) {
            if(cnt_b[j]) {
                max_t = j;
                break;
            } 
        }

        if(max_t > 0) {
            ans[i] = true;
        } else {
            bool has = false;
            for(int j = 1; j < 26; j++) {
                if(cnt_a[j]) {
                    has = true;
                    break;
                } 
            } 

            if(has) {
                ans[i] = false;
            } else {
                ans[i] = tot_a < tot_b; 
            }
        }
    }

    for(int i = 0; i < Q; i++) {
        cout << (ans[i] ? "YES" : "NO") << '\n';
    }
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
