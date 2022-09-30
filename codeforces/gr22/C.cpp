#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

const int ALICE = 0;
const int BOB = 1;

int dfs(int odd, int eve, int parity, int turn, vector<vector<vector<vector<int>>>>& dp) {
    if(odd == 0 && eve == 0) {
        if(turn == ALICE) {
            return parity == 0; 
        } else {
            return parity == 1;
        }
    }

    if(dp[odd][eve][parity][turn] != -1) {
        return dp[odd][eve][parity][turn];
    } 

    if(odd > 0) {
        if(turn == ALICE) {
            if(!dfs(odd - 1, eve, parity ^ 1, turn ^ 1, dp)) {
                return dp[odd][eve][parity][turn] = 1;
            }
        } else {
            if(!dfs(odd - 1, eve, parity, turn ^ 1, dp)) {
                return dp[odd][eve][parity][turn] = 1;
            }
        }
    }

    if(eve > 0) {
        if(turn == ALICE) {
            if(!dfs(odd, eve - 1, parity, turn ^ 1, dp)) {
                return dp[odd][eve][parity][turn] = 1;
            }
        } else {
            if(!dfs(odd, eve - 1, parity, turn ^ 1, dp)) {
                return dp[odd][eve][parity][turn] = 1;
            }
        }
    }

    return dp[odd][eve][parity][turn] = 0;
}
void run_case() {
    int N;
    cin >> N;

    vector<int> A(N, 0);
    int cnt_odd = 0;
    int cnt_eve = 0;
    for(int i = 0; i < N; i++) {
        cin >> A[i];
        if(A[i] & 1) {
            cnt_odd++;
        } else {
            cnt_eve++;
        }
    }
    
    vector<vector<vector<vector<int>>>> dp(101, vector<vector<vector<int>>>(101, vector<vector<int>>(2, vector<int>(2, -1))));
    int ans = dfs(cnt_odd, cnt_eve, 0, 0, dp);
    
    cout << (ans ? "Alice" : "Bob") << '\n';
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
