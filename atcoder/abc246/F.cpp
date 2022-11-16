#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;
using LL = long long;

const LL MOD = 998244353LL;

LL q_pow(LL x, LL y) {
    LL res = 1LL;
    while(y) {
        if(y & 1LL) {
            res *= x;
            res %= MOD;
        }
        x *= x;
        x %= MOD;
        y >>= 1LL;
    }
    return res;
}

void run_case() {
    int N, L;
    cin >> N >> L;
    
    vector<int> A(N, 0);
    for(int i = 0; i < N; i++) {
        string S;
        cin >> S;

        for(char c : S) {
            A[i] |= 1 << (c - 'a');
        }
    }

    LL ans = 0LL;
    for(int i = 1; i < (1 << N); i++) {
        int cnt_set = 0;
        int x = -1;
        for(int j = 0; j < N; j++) {
            if(i & (1 << j)) {
                if(x == -1) {
                    x = A[j];
                } else {
                    x &= A[j];
                }
                cnt_set += 1;
            }
        }

        int cnt_intersection = 0;
        for(int j = 0; j < 26; j++) {
            if(x & (1 << j)) {
                cnt_intersection += 1; 
            }
        }

        LL tot = q_pow(cnt_intersection, L);
        
        if(cnt_set & 1) {
            ans += tot; 
            ans %= MOD;
        } else {
            ans -= tot;
            ans += MOD;
            ans %= MOD;
        }
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
