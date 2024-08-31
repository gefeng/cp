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
    std::vector<int64_t> p;
    std::set<int64_t> seen;
    int64_t dfs(int n, int k, std::vector<int>& a) {
        int size = a.size();
        if(size == n / 2) {
            int64_t res = 0;
            if(n % 2 == 1) {
                for(int d = 0; d < 10; d++) {
                    std::vector<int> v(a);
                    v.push_back(d);
                    
                    
                    for(int i = size - 1; i >= 0; i--) {
                        v.push_back(v[i]);
                    }
                    if(v.size() == 1 && v[0] == 0) {
                        continue;
                    }
                    
                    std::vector<int> h(v);
                    std::sort(h.begin(), h.end());
                    int64_t hash = 0;
                    for(int i = h.size() - 1; i >= 0; i--) {
                        hash = hash * 10 + h[i];
                    }
                    
                    
                    int64_t rem = 0;
                    int64_t base = 1;
                    std::array<int, 10> c = {};
                    for(int i = v.size() - 1; i >= 0; i--) {
                        rem += v[i] * base;
                        rem %= k;
                        base *= 10;
                        c[v[i]] += 1;
                    }
                        
                    if(rem == 0) {
                        if(seen.find(hash) != seen.end()) {
                            return 0;
                        }
                        seen.insert(hash);
                        int64_t cnt = p[n];
                        for(int i = 0; i < 10; i++) {
                            cnt /= p[c[i]];
                        }
                        if(c[0]) {
                            int64_t x = p[n - 1];
                            for(int i = 0; i < 10; i++) {
                                if(i == 0) {
                                    x /= p[c[0] - 1];
                                } else {
                                    x /= p[c[i]];
                                }
                            }
                            cnt -= x;
                        }
                    
                        res += cnt;
                    }
                }
            } else {
                std::vector<int> v(a);
                for(int i = size - 1; i >= 0; i--) {
                    v.push_back(v[i]);
                }
                std::vector<int> h(v);
                std::sort(h.begin(), h.end());
                int64_t hash = 0;
                for(int i = h.size() - 1; i >= 0; i--) {
                    hash = hash * 10 + h[i];
                }
                
                int64_t rem = 0;
                int64_t base = 1;
                std::array<int, 10> c = {};
                for(int i = v.size() - 1; i >= 0; i--) {
                    rem += v[i] * base;
                    rem %= k;
                    base *= 10;
                    c[v[i]] += 1;
                }
                if(rem == 0) {
                    if(seen.find(hash) != seen.end()) {
                            return 0;
                    }
                    seen.insert(hash);
                    int64_t cnt = p[n];
                    for(int i = 0; i < 10; i++) {
                        cnt /= p[c[i]];
                    }
                    if(c[0]) {
                        int64_t x = p[n - 1];
                        for(int i = 0; i < 10; i++) {
                            if(i == 0) {
                                x /= p[c[0] - 1];
                            } else {
                                x /= p[c[i]];
                            }
                        }
                        cnt -= x;
                    }

                    res += cnt;
                }
            }
            return res;
        }
        
        int st = a.empty() ? 1 : 0;
        int64_t res = 0;
        for(int d = st; d < 10; d++) {
            a.push_back(d);
            res += dfs(n, k, a);
            a.pop_back();
        }
        
        return res;
    }
    
    long long countGoodIntegers(int n, int k) {
        p.resize(n + 1, 1);
        for(int i = 1; i <= n; i++) {
            p[i] = p[i - 1] * i;
        }
        std::vector<int> a;
        return dfs(n, k, a);
    }
};
