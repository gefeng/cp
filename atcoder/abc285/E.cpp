#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;
using LL = long long;

void run_case() {
    int N;
    cin >> N;

    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<LL> p(N + 1, 0LL);
    for(int i = 2; i <= N; i++) {
        for(int j = 0; j < (i - 1) / 2; j++) {
            p[i] += 2LL * A[j];
        }
        if(i % 2 == 0) {
            p[i] += A[i / 2 - 1]; 
        }
    }
    
    vector<LL> dp(N + 1, 0LL);  // infinite knapsack with total weight N
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            if(i - j >= 0) {
                dp[i] = max(dp[i], dp[i - j] + p[j]);
            }
        } 
    }

    cout << dp[N] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
