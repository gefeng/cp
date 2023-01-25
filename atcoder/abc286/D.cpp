#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    int N, X;
    cin >> N >> X;

    vector<pair<int, int>> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i].first >> A[i].second;
    }

    vector<bool> dp(X + 1, false);
    dp[0] = true;
    
    for(int i = 1; i <= N; i++) {
        int a = A[i - 1].first;
        int b = A[i - 1].second;
        for(int j = X; j >= 0; j--) {
            for(int k = 0; k <= b; k++) {
                if(j - a * k >= 0 && dp[j - a * k]) {
                    dp[j] = true;
                }
            }
        }
    }

    cout << (dp[X] ? "Yes" : "No") << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
