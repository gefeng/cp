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
    std::string smallestNumber(std::string num, long long t) {
        int n = num.size();
        
        std::vector<int> zero;
        for(int i = 0; i < n; i++) {
            if(num[i] == '0') {
                zero.push_back(i);
            }
        }
        
        int64_t rem = 1;
        for(int i = 0; i < n; i++) {
            rem *= num[i] - '0';
            rem %= t;
        }
        
        if(rem == 0 && zero.empty()) {
            return num;
        }
        
        std::map<int64_t, int> prime_factors;
        std::map<int64_t, int> tmp;
        for(int64_t f = 2; f * f <= t; f++) {
            if(t % f == 0) {
                int cnt = 0;
                while(t % f == 0) {
                    t /= f;
                    cnt += 1;
                }
                prime_factors[f] = cnt;
            }
        }
        
        if(t > 1) {
            prime_factors[t] += 1;
        }
        
        tmp = prime_factors;
        
        for(auto [f, _] : prime_factors) {
            if(f > 7) {
                return "-1";
            }
        }
        
        auto get_min_len = [](std::map<int64_t, int>& m) {
            int res = 0;
            for(auto [f, cnt] : m) {
                if(f == 5 || f == 7) {
                    res += cnt;
                } else if(f == 2) {
                    res += cnt / 3;
                    if(m.find(3) == m.end()) {
                        res += cnt % 3 == 0 ? 0 : 1;
                    }
                } else {
                    res += cnt / 2;
                    int r = cnt % 2;
                    if(m.find(2) == m.end()) {
                        res += r;
                    } else {
                        int cnt_2 = m[2] % 3;
                        if(cnt_2 == 0) {
                            res += r;
                        } else if(cnt_2 == 1) {
                            res += 1;
                        } else {
                            res += r ? 2 : 1;
                        }
                    }
                }
            }
            return res;
        };
        
        auto construct = [](std::map<int64_t, int>& m) {
            std::string res = "";
            for(auto& [f, cnt] : m) {
                if(f == 5 || f == 7) {
                    while(cnt--) {
                        res.push_back(char(f + '0'));
                    }
                } else if(f == 2) {
                    int d = cnt / 3;
                    while(d--) {
                        res.push_back('8');
                    }
                    cnt %= 3;
                    if(m.find(3) == m.end()) {
                        if(cnt == 1) {
                            res.push_back('2');
                        } else if(cnt == 2) {
                            res.push_back('4');
                        }
                    }
                } else {
                    int cnt_2 = m[2];
                    int d = cnt / 2;
                    int r = cnt % 2;
                    if(cnt_2 == 0) {
                        if(r) {
                            res.push_back('3');
                        }
                        while(d--) {
                            res.push_back('9');
                        }
                    } else if(cnt_2 == 1) {
                        if(r) {
                            res.push_back('6');
                        } else {
                            res.push_back('2');
                        }
                        while(d--) {
                            res.push_back('9');
                        }
                    } else if(cnt_2 == 2) {
                        if(r) {
                            res.push_back('2');
                            res.push_back('6');
                            while(d--) {
                                res.push_back('9');
                            }
                        } else {
                            res.push_back('4');
                            while(d--) {
                                res.push_back('9');
                            }
                        }
                    }
                }
            }
            
            std::sort(res.begin(), res.end());
            
            return res;
        };

        int p = -1;
        char which = -1;
        for(int i = 0; i < n; i++) {
            for(char c = char(num[i] + 1); c <= '9'; c++) {
                int x = c - '0';
                std::vector<std::pair<int, int>> pf;
                for(int f = 2; f * f <= x; f++) {
                    if(x % f == 0) {
                        int cnt = 0;
                        while(x % f == 0) {
                            cnt += 1;
                            x /= f;
                        }
                        pf.emplace_back(f, cnt);
                    }
                }
                if(x > 1) {
                    pf.emplace_back(x, 1);
                }
                
                std::map<int64_t, int> cm(prime_factors);
                for(auto& [f, cnt] : pf) {
                    if(cm.find(f) != cm.end()) {
                        int d = std::min(cm[f], cnt);
                        cm[f] -= d;
                    }
                }
                
                int min_len = get_min_len(cm);
                if(min_len <= n - 1 - i) {
                    p = i;
                    which = c;
                    break;
                }
            }
            
            int x = num[i] - '0';
            for(int f = 2; f * f <= x; f++) {
                if(x % f == 0) {
                    int cnt = 0;
                    while(x % f == 0) {
                        cnt += 1;
                        x /= f;
                    }
                    if(prime_factors.find(f) != prime_factors.end()) {
                        int d = std::min(cnt, prime_factors[f]);
                        prime_factors[f] -= d;
                        if(prime_factors[f] == 0) {
                            prime_factors.erase(f);
                        }
                    }
                }
            }
            if(x > 1) {
                if(prime_factors.find(x) != prime_factors.end()) {
                    if(--prime_factors[x] == 0) {
                        prime_factors.erase(x);
                    }
                }
            }
            
            if(num[i] == '0') {
                break;
            }
        }
        
        std::string ans = "";

        if(p == -1) {
            std::swap(tmp, prime_factors);
            ans = construct(prime_factors);
            if(ans.size() < num.size()) {
                std::string prefix(num.size() - ans.size(), '1');
                ans = prefix + ans;
            }
            if(ans.size() == num.size() && ans < num) {
                ans = "1" + ans;
            }
            return ans;
        }
        
        std::swap(tmp, prime_factors);
        for(int i = 0; i <= p; i++) {
            ans.push_back(i < p ? num[i] : which);
            int x = i < p ? num[i] - '0' : which - '0';
            for(int f = 2; f * f <= x; f++) {
                if(x % f == 0) {
                    int cnt = 0;
                    while(x % f == 0) {
                        cnt += 1;
                        x /= f;
                    }
                    if(prime_factors.find(f) != prime_factors.end()) {
                        int d = std::min(cnt, prime_factors[f]);
                        prime_factors[f] -= d;
                        if(prime_factors[f] == 0) {
                            prime_factors.erase(f);
                        }
                    }
                }
            }
            if(x > 1) {
                if(prime_factors.find(x) != prime_factors.end()) {
                    if(--prime_factors[x] == 0) {
                        prime_factors.erase(x);
                    }
                }
            }
        }
    
        std::string suffix = construct(prime_factors);
        
        
        int left = n - ans.size() - suffix.size();
        while(left--) {
            ans.push_back('1');
        }
        ans.append(suffix);
        
        return ans;
    }
};
