#include <iostream>
#include <array>
#include <queue>
#include <unordered_set>

using namespace std;
using LL = long long;

void dfs(int from, int to, int n, vector<pair<int, int>>& moves) {
    if(n == 1) {
        moves.emplace_back(from, to);
        return;
    }

    int mid = 3 ^ (from | to);

    dfs(from, mid, n - 1, moves);
    moves.emplace_back(from, to);
    dfs(mid, to, n - 1, moves);
}

void run_case() {
    int N;
    cin >> N;

    int x = 1;
    for(int i = 2; i <= N; i++) {
        x = x << 1 | 1;
    }

    cout << x << '\n';

    vector<pair<int, int>> moves;
    dfs(0, 2, N, moves);

    for(auto& m : moves) {
        cout << m.first + 1 << ' ' << m.second + 1 << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
