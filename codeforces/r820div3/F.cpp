#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    string S;
    int W, M;
    cin >> S >> W >> M;
    
    vector<array<int, 3>> Q(M);
    for(int i = 0; i < M; i++) {
        int L, R, K;
        cin >> L >> R >> K;
        
        Q[i] = {L - 1, R - 1, K};
    }

    int n = S.length();
    vector<int> psum(n + 1, 0);
    for(int i = 1; i <= n; i++) {
        psum[i] += psum[i - 1] + S[i - 1] - '0';
    }

    vector<vector<int>> dp(9);
    int sum = 0;
    for(int l = 0, r = 0; r < n; r++) {
        sum += S[r] - '0'; 

        if(r - l + 1 > W) {
            sum -= S[l++] - '0';
        }

        if(r - l + 1 == W) {
            int rem = sum % 9;
            dp[rem].push_back(l);
        }
    }

    for(int i = 0; i < M; i++) {
        int l = Q[i][0];
        int r = Q[i][1];
        int t = Q[i][2];
        int rem = (psum[r + 1] - psum[l]) % 9;
        
        int l1 = -1;
        int l2 = -1;
        for(int j = 0; j < 9; j++) {
            for(int k = 0; k < 9; k++) {
                if(((j * rem % 9) + (k % 9)) % 9 == t) {
                    if(j == k) {
                        if(dp[j].size() < 2) {
                            continue;
                        }
                        if(l1 == -1) {
                            l1 = dp[j][0];
                            l2 = dp[j][1];
                        } else {
                            if(dp[j][0] < l1) {
                                l1 = dp[j][0];
                                l2 = dp[j][1];
                            } else if(dp[j][0] == l1 && dp[j][1] < l2) {
                                l2 = dp[j][1]; 
                            }
                        }
                    } else {
                        if(dp[j].empty() || dp[k].empty()) {
                            continue; 
                        } 

                        if(l1 == -1) {
                            l1 = dp[j][0];
                            l2 = dp[k][0];
                        } else {
                            if(dp[j][0] < l1) {
                                l1 = dp[j][0];
                                l2 = dp[k][0];
                            } else if(dp[j][0] == l1) {
                                l2 = min(l2, dp[k][0]);
                            }
                        }
                    }
                }
            }
        }

        if(l1 != -1) {
            l1++;
            l2++;
        }
        cout << l1 << ' ' << l2 << '\n';
    }
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
