#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

constexpr int64_t INF = int64_t(2e18);

void run_case() {
    int N, K;
    std::cin >> N >> K;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int64_t ans = INF; 
    int t_len = N - K;
    std::set<int> s;

    for(int i = K; i < N; i++) {
        s.insert(A[i]);
    }

    int mid = (t_len + 1) / 2 - 1;
    int median = 0;
    int64_t sum = 0;
    auto it = s.begin();
    for(int i = 0; i <= mid; i++, it = std::next(it)) {
        median = *it;
        sum += *it * 2;
    }    

    auto add = [&](int x) {
        s.insert(x);
        if(x > median) {
            if(t_len % 2 == 0) {
                median = *s.upper_bound(median);
                sum += median * 2;
            }
        } else {
            if(t_len % 2 == 1) {
                sum -= 2 * median;
                median = *std::prev(s.find(median));
            }
            sum += 2 * x;
        }
    };

    auto remove = [&](int x) {
        s.erase(x);
        if(x == median) {
            sum -= 2 * x;
            if(t_len % 2 == 0) {
                median = *std::prev(s.upper_bound(x));
            } else {
                median = *s.upper_bound(x);
                sum += 2 * median;
            }
        } else if(x < median) {
            sum -= 2 * x;
            if(t_len % 2 == 1) {
                median = *s.upper_bound(median);
                sum += 2 * median;
            }
        } else {
            if(t_len % 2 == 0) {
                sum -= 2 * median;
                median = *std::prev(s.find(median));
            }
        }
    };

    ans = sum - (t_len % 2 == 1 ? median : 0);
    for(int i = K; i < N; i++) {
        int j = i - K;
        
        // add A[j] remove A[i]
        add(A[j]);
        remove(A[i]);

        ans = std::max(ans, sum - (t_len % 2 == 1 ? median : 0));
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
