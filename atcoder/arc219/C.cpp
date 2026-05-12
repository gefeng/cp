#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t INF = static_cast<int64_t>(2e18);

void run_case() {
    int64_t H, W;
    int N;
    std::cin >> H >> W >> N;

    std::vector<std::pair<int64_t, int64_t>> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i].first >> A[i].second;
        A[i].first--;
        A[i].second--;
    }

    std::ranges::sort(A);
    
    int64_t sum = 0;
    int64_t ans = INF;
    for(int i = 0; i < N; ) {
        int j = i;
        while(i < N && A[i].first == A[j].first) {
            i++;
        }
        sum += A[i - 1].second * 2;
    }

    ans = sum;

    std::vector<int64_t> a;
    sum = 0;
    for(int i = 0; i < N; ) {
        int j = i;
        while(i < N && A[i].first == A[j].first) {
            i++;
        }

        int64_t pre = 0;
        int64_t max_v = 0;
        for(int k = j; k < i; k++) {
            max_v = std::max(max_v, A[k].second - pre);
            pre = A[k].second;
            if(k == i - 1) {
                max_v = std::max(max_v, W - 1 - A[k].second);
            }
        }
        int64_t cost = 2 * (W - 1) - 2 * max_v;
        a.push_back(cost);
        sum += cost;
    }
    
    std::ranges::sort(a);

    if(a.size() == 1) {
        std::cout << ans << '\n';
        return;
    }
        
    for(int i = a.size() - 1; i >= 0; i -= 2) {
        if(i - 1 >= 0) {
            int64_t d = 2 * (W - 1) - a[i] - a[i - 1];
            if(d < 0) {
                sum += d;
            } else {
                if(i == a.size() - 1) {
                    sum += d;
                } else {
                   break;
                }
            }
        }
    }

    ans = std::min(ans, sum);

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
