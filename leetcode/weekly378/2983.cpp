#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

constexpr int64_t MOD = 998244353;
constexpr int64_t BASE = 31;

class Solution {
public:
    std::vector<bool> canMakePalindromeQueries(std::string s, std::vector<std::vector<int>>& queries) {
        int n = s.size();
        int m = n / 2;
        std::vector<int64_t> h1(m + 1, 0);
        std::vector<int64_t> h2(m + 1, 0);
        std::vector<int64_t> pow(m + 1, 1);
        
        for(int i = 0; i < m; i++) {
            h1[i + 1] = ((h1[i] * BASE % MOD) + s[i] - 'a' + 1) % MOD;
            h2[i + 1] = ((h2[i] * BASE % MOD) + s[n - i - 1] - 'a' + 1) % MOD;
            pow[i + 1] = pow[i] * BASE % MOD;
        }
        
        std::vector<std::vector<int>> v(n + 1, std::vector<int>(26, 0));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < 26; j++) {
                v[i + 1][j] = v[i][j] + (j == s[i] - 'a' ? 1 : 0);
            }
        }
        
        int size = queries.size();
        std::vector<bool> ans(size);
        for(int i = 0; i < size; i++) {
            int a = queries[i][0];
            int b = queries[i][1];
            int c = queries[i][2];
            int d = queries[i][3];
            int aa = n - b - 1;
            int bb = n - a - 1;
            int cc = n - d - 1;
            int dd = n - c - 1;
            
            int l = std::min(a, cc);
            int r = std::max(b, dd);
            int cnt_diff1 = 0;
            int cnt_diff2 = 0;
            
            for(int j = 0; j < 26; j++) {
                if(v[b + 1][j] - v[a][j] != v[n - a][j] - v[n - b - 1][j]) {
                    cnt_diff1 += 1;
                }
                if(v[d + 1][j] - v[c][j] != v[n - c][j] - v[n - d - 1][j]) {
                    cnt_diff2 += 1;
                }
            }

            if(cc > b || dd < a) {    
                if(cnt_diff1 || cnt_diff2) {
                    ans[i] = false;
                    continue;
                }
            } else {
                l = std::max(aa, c);
                r = std::min(bb, d);
                std::vector<int> cnt1(26);
                std::vector<int> cnt2(26);
                bool end = false;
                for(int j = 0; j < 26; j++) {
                    cnt1[j] = v[b + 1][j] - v[a][j];
                }
                
                if(r + 1 <= bb) {
                    for(int j = 0; j < 26; j++) {
                        int x = v[bb + 1][j] - v[r + 1][j];
                        if(cnt1[j] < x) {
                            ans[i] = false;
                            end = true;
                            break;
                        }
                        cnt1[j] -= x;
                    }
                }
                
                if(end) continue;
                
                if(l - 1 >= aa) {
                    for(int j = 0; j < 26; j++) {
                        int x = v[l][j] - v[aa][j];
                        if(cnt1[j] < x) {
                            ans[i] = false;
                            end = true;
                            break;
                        }
                        cnt1[j] -= x;
                    }
                }
                
                if(end) continue;

                
                l = std::max(a, cc);
                r = std::min(b, dd);
                for(int j = 0; j < 26; j++) {
                    cnt2[j] = v[d + 1][j] - v[c][j];
                }
                
                if(r + 1 <= dd) {
                    for(int j = 0; j < 26; j++) {
                        int x = v[dd + 1][j] - v[r + 1][j];
                        if(cnt2[j] < x) {
                            ans[i] = false;
                            end = true;
                            break;
                        }
                        cnt2[j] -= x;
                    }
                }
                
                if(end) continue;
                
                if(l - 1 >= cc) {
                    for(int j = 0; j < 26; j++) {
                        int x = v[l][j] - v[cc][j];
                        if(cnt2[j] < x) {
                            ans[i] = false;
                            end = true;
                            break;
                        }
                        cnt2[j] -= x;
                    }
                }
                
                if(end) continue;
        
                for(int j = 0; j < 26; j++) {
                    if(cnt1[j] != cnt2[j]) {
                        ans[i] = false;
                        end = true;
                        break;
                    }
                }

                if(end) continue;
            }
            
            l = std::min(a, cc);
            r = std::max(b, dd);
            int len = l;
            if(h1[len] != h2[len]) {
                ans[i] = false;
                continue;
            }

            len = m - r - 1;
            int64_t hl = (h1[m] - (h1[m - len] * pow[len] % MOD) + MOD) % MOD;
            int64_t hr = (h2[m] - (h2[m - len] * pow[len] % MOD) + MOD) % MOD;
            if(hl != hr) {
                ans[i] = false;
                continue;
            }
            
            if(cc > b || dd < a) {
                l = std::min(b, dd) + 1;
                r = std::max(a, cc) - 1;
                len = r - l + 1;
                hl = (h1[r + 1] - (h1[l] * pow[len] % MOD) + MOD) % MOD;
                hr = (h2[r + 1] - (h2[l] * pow[len] % MOD) + MOD) % MOD;
                
                if(hl != hr) {
                    ans[i] = false;
                    continue;
                }
            }
            
            ans[i] = true;
        }
        
        return ans;
    }
};
