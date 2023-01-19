#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

using namespace std;
using LL = long long;

void run_case() {
    LL K;
    cin >> K;
    

    // 2  20 22  200 202 220 222  2000 2002 2020
    // 1   1 + 1     1 + 1 + 2      1 + 1 + 2 + 3

    int n = 60;
    vector<LL> dp(n + 1, 0LL);
    dp[1] = 1LL;
    for(int i = 2; i <= n; i++) {
        for(int j = 1; j < i; j++) {
            dp[i] += dp[j];
        }
        dp[i] += 1LL;
    }
    
    string ans = "";
    for(int i = n; i > 0; i--) {
        if(K >= dp[i]) {
            ans.push_back('2'); 
            K -= dp[i];
        } else {
            ans.push_back('0');
        }
    }

    for(int i = 0; i < ans.size(); i++) {
        if(ans[i] == '2') {
            cout << ans.substr(i, ans.size() - i) << '\n';
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
