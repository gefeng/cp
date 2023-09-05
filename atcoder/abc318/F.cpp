#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

constexpr int64_t INF = (int64_t)2e18;

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int64_t> A(N);
    std::vector<int64_t> B(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < N; i++) {
        std::cin >> B[i];
    }

    std::vector<std::pair<int64_t, int64_t>> ans;
    for(int i = 1; i <= N; i++) {
        std::vector<std::pair<int64_t, int64_t>> a;

        for(int j = 0; j <= N - i; j++) {
            int64_t l = -INF;
            int64_t r = INF;
            bool ok = true;
            for(int k = 0; k < i; k++) {
                int64_t x = A[j + k] - B[i - 1];
                int64_t y = A[j + k] + B[i - 1];
                if(x > r) {
                    ok = false;
                    break;
                }
                l = std::max(l, x);
                r = std::min(r, y);
            }

            if(!ok) {
                continue;
            }

            while(!a.empty() && a.back().second + 1 >= l) {
                auto [pl, pr] = a.back();
                a.pop_back();
                l = std::min(pl, l);
                r = std::max(pr, r);
            }
            a.emplace_back(l, r);
        }

        if(ans.empty()) {
            for(auto [l, r] : a) {
                ans.emplace_back(l, r);
            }
        } else {
            std::vector<std::pair<int64_t, int64_t>> nxt_ans;
            std::map<int64_t, int64_t> m;
            
            if(a.empty()) {
                std::cout << 0 << '\n';
                return;
            }

            for(auto [l, r] : a) {
                m[l] += 1;
                m[r + 1] -= 1;
            }

            for(auto [l, r] : ans) {
                m[l] += 1;
                m[r + 1] -= 1;
            }

            int64_t cur = 0;
            int64_t max_v = -1;
            int64_t pre = -1;
            for(auto [k, v] : m) {
                cur += v;
                max_v = std::max(max_v, cur);
            }

            if(max_v < 2) {
                std::cout << 0 << '\n';
                return;
            }

            cur = 0;
            for(auto [k, v] : m) {
                cur += v;
                if(cur == max_v && pre == -1) {
                    pre = k;
                } 

                if(cur < max_v && pre != -1) {
                    nxt_ans.emplace_back(pre, k - 1);
                    pre = -1;
                }
            }
            
            std::swap(ans, nxt_ans);
        }
    }

    int64_t sum = 0;
    for(auto [l, r] : ans) {
        sum += r - l + 1; 
    }

    std::cout << sum << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
