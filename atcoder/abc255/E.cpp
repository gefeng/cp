#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;
using LL = long long;

void run_case() {
    int N, M;
    cin >> N >> M;

    vector<int> S(N - 1, 0);
    for(int i = 0; i < N - 1; i++) {
        cin >> S[i];
    }

    vector<int> X(M, 0);
    for(int i = 0; i < M; i++) {
        cin >> X[i];
    }
    
    unordered_map<LL, int> m;
    for(int x : X) {
        LL a = 0LL; 
        LL sign = 1;
        for(int i = 0; i < N; i++) {
            LL y = (1LL * x - a) * sign;
            m[y] += 1;
            sign *= -1LL;
            a = S[i] - a;
        }
    }

    int ans = 0;
    for(auto& [_, v] : m) {
        ans = max(ans, v);
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
