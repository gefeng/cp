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

    LL ans = 0LL;
    int n = N / 2;
    for(int i = 0, j = 1; i < n; i++, j++) {
        ans += 1LL * j * (N - 2 * i - 1); 
    }

    ans *= 2LL;
    ans -= 1LL * (n + 1) * n / 2;

    map<int, vector<int>> m;
    for(int i = 0; i < N; i++) {
        m[A[i]].push_back(min(i + 1, N - i)); 
    }

    for(auto& [k, v] : m) {
        sort(v.begin(), v.end());
        
        int sz = v.size();
        if(sz == 1) {
            continue;
        }
        for(int i = 0; i < sz; i++) {
            ans -= 1LL * v[i] * (sz - i - 1);
        }
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
