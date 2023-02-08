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

    map<int, vector<int>> m;
    for(int i = 0; i < N; i++) {
        int X, C;
        cin >> X >> C;
        m[C].push_back(X);
    }

    vector<pair<int, int>> color;
    for(auto& [k, v] : m) {
        sort(v.begin(), v.end());

        color.emplace_back(v[0], v[v.size() - 1]);
    }

    int n = color.size();

    // dp[i][0] means minimum time to collect balls in first i colors ending at the left most ball in ith color
    // dp[i][1] means minimum time to collect balls in first i colors ending at the right most ball in ith color
    vector<LL> dp(2, 0LL);
    for(int i = 1; i <= n; i++) {
        vector<LL> ndp(2, 0LL);
        LL pre_l = i == 1 ? 0 : color[i - 2].first;
        LL pre_r = i == 1 ? 0 : color[i - 2].second;
        LL cur_l = color[i - 1].first;
        LL cur_r = color[i - 1].second;

        // go left -> go right  start at previous left
        if(pre_l <= cur_l) {
            ndp[1] = cur_r - pre_l + dp[0];
        } else {
            ndp[1] = pre_l - cur_l + cur_r - cur_l + dp[0];
        }

        // go left -> go right  start at previous right
        if(pre_r <= cur_l) {
            ndp[1] = min(ndp[1], cur_r - pre_r + dp[1]); 
        } else {
            ndp[1] = min(ndp[1], pre_r - cur_l + cur_r - cur_l + dp[1]);
        }
        
        // go right -> go left  start at previous left
        if(pre_l >= cur_r) {
            ndp[0] = pre_l - cur_l + dp[0];
        } else {
            ndp[0] = cur_r - pre_l + cur_r - cur_l + dp[0]; 
        }

        // go right -> go left  start at previous right
        if(pre_r >= cur_r) {
            ndp[0] = min(ndp[0], pre_r - cur_l + dp[1]);
        } else {
            ndp[0] = min(ndp[0], cur_r - pre_r + cur_r - cur_l + dp[1]);
        }

        swap(dp, ndp);
    }

    cout << min(dp[0] + abs(color[n - 1].first), dp[1] + abs(color[n - 1].second)) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
