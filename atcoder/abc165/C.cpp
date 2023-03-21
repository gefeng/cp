#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void dfs(int N, int M, int i, int pre, vector<int>& seq, vector<vector<int>>& all) {
    if(i == N) {
        all.push_back(seq);
        return;
    }

    for(int x = pre; x <= M; x++) {
        seq.push_back(x);
        dfs(N, M, i + 1, x, seq, all);
        seq.pop_back();
    }
}

void run_case() {
    int N, M, Q;
    cin >> N >> M >> Q;

    vector<array<int, 4>> A(Q);
    for(int i = 0; i < Q; i++) {
        for(int j = 0; j < 4; j++) {
            cin >> A[i][j];
        }
    }

    vector<vector<int>> all;
    vector<int> seq;
    dfs(N, M, 0, 1, seq, all);

    int ans = 0;
    for(vector<int>& s : all) {
        int score = 0;
        for(auto& q : A) {
            if(s[q[1] - 1] - s[q[0] - 1] == q[2]) {
                score += q[3]; 
            }
        }
        ans = max(ans, score);
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
