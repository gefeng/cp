#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

using namespace std;
using LL = long long;

map<pair<LL, int>, LL> memo;

LL dfs(LL X, vector<LL>& A, int cur) {
    if(cur == 0) {
        return X;
    }
    if(memo.find({X, cur}) != memo.end()) {
        return memo[{X, cur}];
    }
    
    LL x = X / A[cur];
    LL y = (X + A[cur] - 1LL) / A[cur];

    LL res = min(dfs(X % A[cur], A, cur - 1) + x, dfs(y * A[cur] - X, A, cur - 1) + y);
    memo[{X, cur}] = res;

    return res;
}

void run_case() {
    int N;
    cin >> N;
    
    LL X;
    cin >> X;

    vector<LL> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    cout << dfs(X, A, N - 1) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
