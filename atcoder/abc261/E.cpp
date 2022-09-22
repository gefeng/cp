#include <iostream>
#include <array>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);        // de-sync with c stream
    cin.tie(nullptr);                   // disable flushing of std::cout

    int n, c;
    cin >> n >> c;

    vector<pair<int, int>> O(n);
    for(int i = 0; i < n; i++) {
        int t, a;
        cin >> t >> a;
        O[i] = {t, a};
    }

    vector<int> ans(n, 0);
    for(int i = 0; i < 30; i++) {
        array<int, 2> dp = {0, 1};  // dp[0] result to perform [1, cur] operations on 0
                                    // dp[1] result to perform [1, cur] operations on 1

        int xbit = c & (1 << i) ? 1 : 0; 
        for(int j = 0; j < n; j++) {
            int t = O[j].first;
            int a = O[j].second; 
            int abit = a & (1 << i) ? 1 : 0;
            
            if(t == 1) {
                xbit = dp[xbit] & abit;     
                dp[0] &= abit;
                dp[1] &= abit;
            } else if(t == 2) {
                xbit = dp[xbit] | abit;
                dp[0] |= abit;
                dp[1] |= abit;
            } else {
                xbit = dp[xbit] ^ abit;
                dp[0] ^= abit;
                dp[1] ^= abit;
            }

            ans[j] |= xbit << i;
        }
    }

    for(int i = 0; i < n; i++) {
        cout << ans[i] << '\n';
    }
}
