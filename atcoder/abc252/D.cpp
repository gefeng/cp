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

void run_case() {
    int N;
    cin >> N;

    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    map<int, int> m;
    for(int i = 0; i < N; i++) {
        m[A[i]] += 1;
    }

    LL ans = 1LL * N * (N - 1LL) * (N - 2LL) / 6LL;
    
    for(auto& [k, v] : m) {
        if(v > 1) {
            LL x = 1LL * v * (v - 1LL) / 2LL;
            LL y = x * (N - v);
            if(v > 2) {
                y += 1LL * v * (v - 1LL) * (v - 2LL) / 6LL; 
            }
            ans -= y;
        }
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
