#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;
using LL = long long;

const double eps = 1e-6;

double find_average(vector<int>& A, int N) {
    double lo = 0.0;
    double hi = 1e9;
    double ans_avg = 0.0;
    while(hi - lo >= eps) {
        double mid = lo + (hi - lo) / 2.0; 

        vector<vector<double>> dp(N + 1, vector<double>(2, 0.0)); 
        dp[1][1] = (double)A[0] - mid;
        
        for(int i = 2; i <= N; i++) {
            dp[i][0] = dp[i - 1][1];
            dp[i][1] = max(dp[i - 1][1], max(dp[i - 1][0], dp[i - 2][1])) + (double)A[i - 1] - mid;
        }

        if(max(dp[N][0], dp[N][1]) >= eps) {
            ans_avg = mid;
            lo = mid;
        } else {
            hi = mid;
        }
    }

    return ans_avg;
}

int find_median(vector<int>& A, int N) {
    int lo = 0;
    int hi = (int)1e9;
    int ans_med = 0;
    while(lo <= hi) {
        int mid = lo + (hi - lo) / 2;
    
        vector<vector<int>> dp(N + 1, vector<int>(2, 0));
        dp[1][1] = A[0] < mid ? -1 : 1;
        dp[1][0] = 0;

        for(int i = 2; i <= N; i++) {
            dp[i][0] = dp[i - 1][1];
            dp[i][1] = max(dp[i - 1][1], max(dp[i - 1][0], dp[i - 2][1])) + (A[i - 1] < mid ? -1 : 1);
        }

        if(dp[N][0] > 0 || dp[N][1] > 0) {
            ans_med = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    return ans_med;
}

void run_case() {
    int N;
    cin >> N;

    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    cout << setprecision(20) << find_average(A, N) << '\n';
    cout << find_median(A, N) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
