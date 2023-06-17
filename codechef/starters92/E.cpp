#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>
#include <queue>

using LL = long long;

constexpr LL MOD = (LL)1e9 + 7LL;

void run_case() {
    int N, K;
    std::cin >> N >> K;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    auto cmp = [](const auto& a, const auto& b) {
        return a.first > b.first;
    };

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(cmp)> pq(cmp);


    std::map<int, int> m;
    for(int i = 0; i < N; i++) {
        m[A[i]] += 1;
    }

    for(auto [k, v] : m) {
        pq.emplace(k, v);
    }

    while(!pq.empty() && K) {
        std::pair<int, int> x = pq.top();
        pq.pop();
        
        if(pq.empty()) {
            int inc = K / x.second; 
            x.first += inc;
            K %= x.second;
            if(K) {
                pq.emplace(x.first + 1, K);
                pq.emplace(x.first, x.second - K);
            } else {
                pq.emplace(x.first, x.second);
            }
            K = 0;
        } else {
            std::pair<int, int> y = pq.top();
            pq.pop();

            int d1 = y.first - x.first;
            int d2 = K / x.second;

            int d = std::min(d1, d2);

            if(d == 0) {
                x.second -= K;
                pq.emplace(x.first, x.second);
                if(x.first + 1 == y.first) {
                    y.second += K;
                } else {
                    pq.emplace(x.first + 1, K);
                }
                pq.emplace(y.first, y.second);

                K = 0;
            } else {
                x.first += d;
                if(x.first == y.first) {
                    y.second += x.second;
                } else {
                    pq.emplace(x.first, x.second);
                }

                pq.emplace(y.first, y.second);
                K -= d * x.second;
            }
        }
    }

    std::vector<int> a;
    while(!pq.empty()) {
        std::pair<int, int> x = pq.top();
        pq.pop();
        
        for(int i = 0; i < x.second; i++) {
            a.push_back(x.first);
        }
    }

    LL sum = 0LL;
    for(int x : a) {
        sum += x;
        sum %= MOD;
    }

    LL ans = 0LL;
    for(int x : a) {
        sum -= x;
        sum += MOD;
        sum %= MOD;

        ans += (sum * x) % MOD;
        ans %= MOD;
    }

    std::cout << ans << '\n';
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
