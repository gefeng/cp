#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

constexpr int N = 7;
constexpr int64_t INF = (int64_t)2e18;

std::vector<int64_t> seeds;
std::vector<std::map<int64_t, std::pair<int64_t, int64_t>>> m(N);

bool is_digit(char c) {
    return c >= '0' && c <= '9';
}

void run_case1() {
    int64_t ans = INF;
    for(int64_t s : seeds) {
        for(int i = 0; i < N; i++) {
            auto it = m[i].upper_bound(s);
            if(it == m[i].begin()) {
                continue;
            }
            it--;
            
            int64_t t = it->second.first;
            int64_t r = it->second.second;
            
            int64_t ns = s - it->first + t;
            if(ns <= t + r) {
                s = ns;
            }
        }

        ans = std::min(ans, s);
    }

    std::cout << ans << '\n';
}

void run_case2() {
    int64_t ans = INF;
    int n = seeds.size();
    
    for(int i = 0; i < n; i += 2) {
        std::vector<std::pair<int64_t, int64_t>> cur;
        cur.emplace_back(seeds[i], seeds[i] + seeds[i + 1] - 1);
        
        for(int j = 0; j < N; j++) {
            std::vector<std::pair<int64_t, int64_t>> nxt;
            int size = cur.size();
            
            for(int k = 0; k < size; k++) {
                int64_t l = cur[k].first;
                int64_t r = cur[k].second;

                auto it1 = m[j].upper_bound(l);
                auto it2 = m[j].lower_bound(r);
                if(it1 != m[j].begin()) {
                    it1--;
                }
                
                while(l <= r && it1 != m[j].end() && it1 != it2) {
                    int64_t sl = it1->first;
                    int64_t sr = sl + it1->second.second - 1;
                    if(r < sl || l > sr) {
                        it1++;
                        continue;
                    }

                    int64_t tl = it1->second.first;
                    int64_t cl = std::max(l, sl);
                    int64_t cr = std::min(r, sr);
                    if(cl - 1 >= l) {
                        nxt.emplace_back(l, cl - 1);
                    }
                    nxt.emplace_back(cl - sl + tl, cr - sl + tl);
                    l = cr + 1;
                }

                if(l <= r) {
                    nxt.emplace_back(l, r);
                }
            }

            std::swap(cur, nxt);
            std::sort(cur.begin(), cur.end());
        }

        int64_t min_p = INF;
        for(auto [l, r] : cur) {
            min_p = std::min(l, min_p);
        }

        ans = std::min(ans, min_p);
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    std::string S;
    std::getline(std::cin, S);
    int n = S.size();
    for(int i = 0; i < n; i++) {
        if(is_digit(S[i])) {
            int64_t x = 0;
            while(i < n && is_digit(S[i])) {
                x = x * 10 + S[i++] - '0';
            }
            seeds.push_back(x);
        }
    }

    std::getline(std::cin, S);

    for(int i = 0; i < N; i++) {
        std::getline(std::cin, S);

        while(std::getline(std::cin, S) && S.size() != 0) {
            int n = S.size();
            std::vector<int64_t> v;
            for(int i = 0; i < n; i++) {
                if(is_digit(S[i])) {
                    int64_t x = 0;
                    while(i < n && is_digit(S[i])) {
                        x = x * 10 + S[i++] - '0';
                    }
                    v.push_back(x);
                }
            }

            m[i][v[1]] = {v[0], v[2]};
        }
    }

    run_case1();
    run_case2();
}
