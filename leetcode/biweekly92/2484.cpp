#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

using namespace std;
using LL = long long;

const LL MOD = (LL)1e9 + 7LL;

class Solution {
public:
    int countPalindromes(string s) {
        int n = s.length();
        
        vector<vector<vector<LL>>> dp_1(n + 1, vector<vector<LL>>(10, vector<LL>(10, 0LL)));
        vector<vector<vector<LL>>> dp_2(n + 1, vector<vector<LL>>(10, vector<LL>(10, 0LL)));
        for(int x = 0; x < 10; x++) {
            for(int y = 0; y < 10; y++) {
                if(x == y) {
                    LL cnt = 0LL;
                    LL tot = 0LL;
                    for(int i = 1; i <= n; i++) {
                        if(s[i - 1] - '0' == x) {
                            cnt += 1LL;
                            tot += cnt - 1LL;
                        }
                        dp_1[i][x][y] = tot;
                    }
                } else {
                    LL cnt = 0LL;
                    LL tot = 0LL;
                    for(int i = 1; i <= n; i++) {
                        int d = s[i - 1] - '0';
                        if(d == x) {
                            cnt += 1LL;
                            cnt %= MOD;
                        }
                        if(d == y) {
                            tot += cnt;
                            tot %= MOD;
                        }

                        dp_1[i][x][y] = tot;
                    }
                }
            }
        }
        
        for(int x = 0; x < 10; x++) {
            for(int y = 0; y < 10; y++) {
                if(x == y) {
                    LL cnt = 0LL;
                    LL tot = 0LL;
                    for(int i = 1; i <= n; i++) {
                        if(s[n - i] - '0' == x) {
                            cnt += 1LL;
                            tot += cnt - 1LL;
                        }
                        dp_2[i][x][y] = tot;
                    }
                } else {
                    LL cnt = 0LL;
                    LL tot = 0LL;
                    for(int i = 1; i <= n; i++) {
                        int d = s[n - i] - '0';
                        if(d == x) {
                            cnt += 1LL;
                            cnt %= MOD;
                        }
                        if(d == y) {
                            tot += cnt;
                            tot %= MOD;
                        }

                        dp_2[i][x][y] = tot;
                    }
                }
            }
        }
        
        LL ans = 0LL;
        for(int i = 0; i < n; i++) {
            for(int x = 0; x < 10; x++) {
                for(int y = 0; y < 10; y++) {
                    LL l = dp_1[i][x][y];
                    LL r = dp_2[n - i - 1][x][y];
                    ans += l * r % MOD;
                    ans %= MOD;
                }
            }
        }
        
        return ans;
    }
};
