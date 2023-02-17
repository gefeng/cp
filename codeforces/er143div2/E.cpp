#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;
using LL = long long;

const LL INF = (LL)2e18;

void run_case() {
    int N;
    cin >> N;

    vector<int> A(N);
    vector<LL> psum(N + 1, 0LL);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
        psum[i + 1] = psum[i] + A[i];
    }

    auto arithmetic_sum = [](const LL a, const LL b) -> LL {
        return (a + b) * (b - a + 1LL) / 2LL;
    };

    // looking for the largest j where j < i and A[j] <= A[i] - (i - j)
    vector<LL> dp_l(N, 0LL);

    // looking for the smallest j where j > i and A[j] <= A[i] - (j - i)
    vector<LL> dp_r(N, 0LL);
    
    vector<int> s;
    for(int i = 0; i < N; i++) {
        while(!s.empty() && A[s.back()] > A[i] - i + s.back()) {
            s.pop_back(); 
        }
        
        int j = s.empty() ? 0 : s.back() + 1;

        LL cost = psum[i] - psum[j] - arithmetic_sum(max(0, A[i] - 1 - (i - 1 - j)), A[i] - 1); 

        dp_l[i] += cost;
        if(!s.empty()) {
            dp_l[i] += dp_l[s.back()];
        }

        s.push_back(i);
    }

    s = vector<int>(); 
    for(int i = N - 1; i >= 0; i--) {
        while(!s.empty() && A[s.back()] > A[i] - s.back() + i) {
            s.pop_back();
        }

        int j = s.empty() ? N - 1 : s.back() - 1;

        LL cost = psum[j + 1] - psum[i + 1] - arithmetic_sum(max(0, A[i] - 1 - (j - i - 1)), A[i] - 1);
        
        dp_r[i] += cost;
        if(!s.empty()) {
            dp_r[i] += dp_r[s.back()];
        }

        s.push_back(i);
    }

    LL ans = INF;
    for(int i = 0; i < N; i++) {
        LL x = dp_l[i] + dp_r[i] + A[i];

        ans = min(ans, x);
    }

    cout << ans << '\n';
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
