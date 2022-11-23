#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

int dfs(int N, vector<string> S, int last, int state, vector<vector<int>>& dp) {
    if(state == (1 << N) - 1) {
        return 0;
    } 

    if(last == -1) {
        last = N;
    }

    if(dp[last][state] != -1) {
        return dp[last][state]; 
    }

    int res = 0;
    for(int i = 0; i < N; i++) {
        if(state & (1 << i)) {
            continue;
        }

        if(last != N && S[last][S[last].size() - 1] != S[i][0]) {
            continue;
        }

        int x = dfs(N, S, i, state ^ (1 << i), dp);
        if(x == 0) {
            res = 1;
        }
    }

    return dp[last][state] = res;
}

void run_case() {
    int N;
    cin >> N;

    vector<string> S(N);
    for(int i = 0; i < N; i++) {
        cin >> S[i];
    }

    vector<vector<int>> dp(N + 1, vector<int>(1 << N, -1));

    int res = dfs(N, S, -1, 0, dp);
    cout << (res ? "First" : "Second") << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
