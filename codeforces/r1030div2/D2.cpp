#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <ranges>
#include <map>
#include <set>

void run_case() {
    int N;
    int64_t K;
    std::cin >> N >> K;

    std::vector<int64_t> A(N);
    std::vector<int64_t> B(N);
    std::map<int64_t, int64_t> tl;
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < N; i++) {
        std::cin >> B[i];
        tl[A[i]] = B[i];
    }

    std::map<int64_t, std::vector<int64_t>> m_pos;
    std::map<int64_t, std::vector<int64_t>> m_neg;
    for(int i = 0; i < N; i++) {
        m_pos[(((A[i] - B[i]) % K) + K) % K].push_back(A[i]);
        m_neg[(A[i] + B[i]) % K].push_back(A[i]);
    }

    int Q;
    std::cin >> Q;
    std::map<std::pair<int64_t, int>, int> dp;
    for(int i = 0; i < Q; i++) {
        int64_t P;
        std::cin >> P;
        
        int leave = 0;
        int64_t p = P;
        int64_t t = 0;
        int red = tl.find(p) != tl.end() && tl[p] == 0;
        int d = red ? 0 : 1;
        std::set<std::pair<int64_t, int>> s;
        while(true) {
            std::pair<int64_t, int> state = {p, d};
            if(s.find(state) != s.end()) {
                break;
            }
            if(red) {
                s.insert(state);
                if(dp.find(state) != dp.end()) {
                    leave = dp[state];
                    break;
                }
            }
            if(d == 1) {
                int64_t k = ((p - t) % K + K) % K;
                if(m_pos.find(k) == m_pos.end()) {
                    leave = 1;
                    break;
                }
                auto it = std::ranges::upper_bound(m_pos[k], p);
                if(it == m_pos[k].end()) {
                    leave = 1;
                    break;
                }
                t += *it - p;
                p = *it;
                d ^= 1;
                red = 1;
            } else {
                int64_t k = (p + t) % K;
                if(m_neg.find(k) == m_neg.end()) {
                    leave = 1;
                    break;
                }
                auto it = std::ranges::lower_bound(m_neg[k], p);
                if(it == m_neg[k].begin()) {
                    leave = 1;
                    break;
                }
                int64_t n_p = *std::prev(it);
                t += p - n_p;
                p = n_p;
                d ^= 1;
                red = 1;
            }
        }

        for(auto x : s) {
            dp[x] = leave;
        }

        std::cout << (leave ? "Yes" : "No") << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
