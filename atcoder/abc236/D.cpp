#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

int ans = 0;

void dfs(vector<vector<int>>& A, int N, int cur, int state, int res) {
    if(state == (1 << 2 * N) - 1) {
        ans = max(ans, res);
        return;
    } 

    if(state & (1 << cur)) {
        dfs(A, N, cur + 1, state, res);
        return;
    }

    for(int i = cur + 1; i < 2 * N; i++) {
        if(state & (1 << i)) {
            continue;
        }

        dfs(A, N, cur + 1, state | (1 << cur) | (1 << i), res ^ A[cur][i]);
    }
}

void run_case() {
    int N;
    cin >> N;
    
    vector<vector<int>> A(2 * N, vector<int>(2 * N, -1));
    for(int i = 0; i < 2 * N - 1; i += 1) {
        for(int k = i + 1; k < N * 2; k++) {
            cin >> A[i][k];
        }
    }

    dfs(A, N, 0, 0, 0);

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
