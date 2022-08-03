#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

void run_case() {
    string T;
    cin >> T;

    int N;
    cin >> N;
    
    vector<string> S(N);
    for(int i = 0; i < N; i++) {
        cin >> S[i];
    }

    int n = T.length();
    vector<int> dp(n + 1, -1);
    vector<int> pre_which(n + 1, -1);
    vector<int> pick_what(n + 1, -1);
    dp[0] = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < N; j++) {
            string& s = S[j];
            if(T.substr(0, i).ends_with(s)) {
                for(int k = i - s.length(); k <= i - 1; k++) {
                    if(dp[k] != -1 && (dp[i] == -1 || dp[i] > dp[k] + 1)) {
                        dp[i] = dp[k] + 1; 
                        pre_which[i] = k;
                        pick_what[i] = j;
                    }
                }
            }
        }
    }

    cout << dp[n] << '\n';
    if(dp[n] != -1) {
        for(int i = n; i > 0; ) {
            cout << pick_what[i] + 1 << ' ' << i - S[pick_what[i]].length() + 1 << '\n';
            i = pre_which[i];
        }
    } 
}

int main() {
    ios::sync_with_stdio(false);        // de-sync with c stream
    cin.tie(0);                         // disable flushing of std::cout
    
    int t = 0;
    cin >> t;
    while(t--) {
        run_case();
    }
}
