#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;
using LL = long long;

const LL MOD = (LL)1e9 + 7;
const int INF = (int)1e9;

void run_case() {
    string S, T;
    cin >> S >> T;

    int n = S.length();
    int m = T.length();
    vector<bool> is_t(n, false);
    for(int i = 0; i < n; i++) {
        if(i - m + 1 >= 0 && S.substr(i - m + 1, m) == T) {
            is_t[i] = true;
        }
    }
    
    vector<int> dp_1(n + 1, INF);
    vector<LL> dp_2(n + 1, 0LL);

    dp_1[0] = 0;
    dp_2[0] = 1LL;
    for(int i = 1; i <= n; i++) {
        if(is_t[i - 1]) {
            for(int j = i - m + 1; j <= i; j++) {
                if(is_t[j - 1]) {
                    if(dp_1[i] > dp_1[j - m] + 1) {
                        dp_1[i] = dp_1[j - m] + 1;
                        dp_2[i] = dp_2[j - m];
                    } else if(dp_1[i] == dp_1[j - m] + 1) {
                        dp_2[i] += dp_2[j - m];
                        dp_2[i] %= MOD;
                    }
                }
            }
        } else {
            dp_1[i] = dp_1[i - 1];
            dp_2[i] = dp_2[i - 1];
        }
    }
    cout << dp_1[n] << ' ' << dp_2[n] << '\n';
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
