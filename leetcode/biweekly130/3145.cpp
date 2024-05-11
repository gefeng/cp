#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

class Solution {
public:
    int64_t countSetBits(int64_t n) {
        n++;
        int64_t powerOf2 = 2;
        int64_t cnt = n / 2;
        while (powerOf2 <= n) {
            int64_t totalPairs = n / powerOf2;
            int64_t x = (totalPairs / 2) * powerOf2 + ((totalPairs & 1) ? (n % powerOf2) : 0);
            cnt += x;
            powerOf2 <<= 1;
        }
        return cnt;
    }
    
    std::array<int64_t, 64> countSetBits2(int64_t n) {
        std::array<int64_t, 64> res{};

        n++;
        int64_t powerOf2 = 2;
        int64_t cnt = n / 2;
        int b = 0;
        res[b++] = cnt;
        
        while (powerOf2 <= n) {
            int64_t totalPairs = n / powerOf2;
            int64_t x = (totalPairs / 2) * powerOf2 + ((totalPairs & 1) ? (n % powerOf2) : 0);
            res[b++] = x;
            cnt += x;
            powerOf2 <<= 1;
        }
        return res;
    }

    int64_t q_pow(int64_t x, int64_t y, int64_t mod) {
        int64_t res = 1;
        while(y) {
            if(y & 1) {
                res *= x;
                res %= mod;
            }
            x *= x;
            x %= mod;
            y >>= 1;
        }
        return res;
    }

    std::vector<int> findProductsOfElements(std::vector<std::vector<long long>>& queries) {
        int n = queries.size();
        std::vector<int> ans(n);

        auto  which_number = [&](int64_t p) {
            int64_t lo = 1;
            int64_t hi = 1e14;
            int64_t res = 0;
            while(lo <= hi) {
                int64_t mid = (lo + hi) >> 1;
                int64_t cnt = countSetBits(mid);
                if(cnt >= p) {
                    res = mid;
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            }
            return res;
        };

        for(int i = 0; i < n; i++) {
            int64_t from = queries[i][0];
            int64_t to = queries[i][1];
            int64_t mod = queries[i][2];
            
            int64_t x = which_number(from + 1);
            int64_t y = which_number(to + 1);
            int64_t res = 1;
            
            if(x == y) {
                int64_t z = countSetBits(x - 1);
                int64_t d = 0;
                for(int j = 0; j <= 60; j++) {
                    if(x & ((int64_t)1 << j)) {
                        d += 1;
                        if(d >= from + 1 - z && d <= to + 1 - z) {
                            res *= (int64_t)1 << j;
                            res %= mod;
                        }
                    }
                }
            } else {
                if(x + 1 <= y - 1) {
                    std::array<int64_t, 64> cnt1 = countSetBits2(x);
                    std::array<int64_t, 64> cnt2 = countSetBits2(y - 1);

                    for(int j = 0; j < 64; j++) {
                        int64_t cnt = cnt2[j] - cnt1[j];
                        
                        if(cnt) {
                            res *= q_pow(((int64_t)1 << j) % mod, cnt, mod);
                            res %= mod;
                        }
                    }
                }

                int64_t d = countSetBits(x) - from;
                for(int j = 60; j >= 0 && d; j--) {
                    if(x & ((int64_t)1 << j)) {
                        res *= (int64_t)1 << j;
                        res %= mod;
                        d -= 1;
                    }
                }

                d = to + 1 - countSetBits(y - 1);
                for(int j = 0; j <= 60 && d; j++) {
                    if(y & ((int64_t)1 << j)) {
                        res *= (int64_t)1 << j;
                        res %= mod;
                        d -= 1;
                    }
                }
            }
            
            ans[i] = res;
        }

        return ans;
    }
};
