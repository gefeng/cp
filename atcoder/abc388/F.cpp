#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>
#include <map>

void run_case() {
    int64_t N;
    int M, A, B;
    std::cin >> N >> M >> A >> B;

    std::vector<std::pair<int64_t, int64_t>> S(M);
    std::vector<std::pair<int64_t, int64_t>> s;
    for(int i = 0; i < M; i++) {
        std::cin >> S[i].first >> S[i].second;
    }

    if(A == B) {
        for(auto [l, r] : S) {
            int64_t p = (r - 1) / A * A + 1;
            if(p >= l) {
                std::cout << "No" << '\n';
                return;
            }
        }
        
        std::cout << ((N - 1) % A == 0 ? "Yes" : "No") << '\n';
        return;
    }

    for(int i = 0; i < M; i++) {
        auto [l, r] = S[i];
        if(r - l + 1 >= B) {
            std::cout << "No" << '\n';
            return;
        }
        if(i == 0) {
            s.emplace_back(1, l - 1);
        } else {
            if(S[i - 1].second + 1 <= l - 1) {
                s.emplace_back(S[i - 1].second + 1, l - 1);
            }
        }
    }
    if(!S.empty()) {
        s.emplace_back(S.back().second + 1, N);
    } else {
        s.emplace_back(1, N);
    }

    int n = s.size(); 
    int m = A * A;
    std::vector<int> dp(B + 1, 0);
    dp[0] = 1;

    int64_t p = 2;
    for(int i = 0; i < n; i++) {
        auto [l, r] = s[i];
        
        int64_t t = std::min(r, l + m);
        while(p <= t) {
            int good = 0;
            if(p < l) {
                good = 0;
            } else {
                for(int k = A; k <= B; k++) {
                    good |= dp[k - 1];
                }
            }
            dp.insert(dp.begin(), good);
            dp.pop_back();
            p += 1;
        }

        bool reachable = false;
        for(int j = 0; j <= B; j++) {
            if(dp[j]) {
                reachable = true;
                break;
            }
        }

        if(!reachable) {
            std::cout << "No" << '\n';
            return;
        }

        if(p > r) {
            continue;
        }

        p = std::max(t + 1, r - B + 1);
        std::vector<int> ndp(dp);
        while(p <= r) {
            ndp.insert(ndp.begin(), 1);
            ndp.pop_back();
            p += 1; 
        }

        std::swap(dp, ndp);
    }

    std::cout << (dp[0] ? "Yes" : "No") << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
