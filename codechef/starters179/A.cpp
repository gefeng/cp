#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<std::vector<int>> a(N + 1);
    for(int i = 0; i < N; i++) {
        a[A[i]].push_back(i);
    }

    std::vector<std::pair<int, int>> events;
    for(int i = 0; i < N; ) {
        int j = i;

        if(j == N - 1) {
            events.emplace_back(N, 1);
            break;
        }

        int d = -2;
        while(i + 1 < N && (d == -2 || A[i + 1] - A[i] == d)) {
            d = d == -2 ? A[i + 1] - A[i] : d;
            i += 1;
        }

        for(int k = j; k < i; k++) {
            events.emplace_back(i + 1, 1);
        }
    }

    for(int i = N - 1; i >= 0; ) {
        int j = i;

        if(j == 0) {
            events.emplace_back(0, 0);
            break;
        }
        
        int d = -2;
        while(i - 1 >= 0 && (d == -2 || A[i] - A[i - 1] == d)) {
            d = d == -2 ? A[i] - A[i - 1] : d;
            i -= 1;
        }
        
        for(int k = j; k > i; k--) {
            events.emplace_back(i, 0);
        }
    }

    std::sort(events.begin(), events.end());
    
    int64_t ans = 0;
    int64_t tot = 0;
    for(int i = 0; i < N * 2; ) {
        int j = i;
        int64_t cnt = 0;
        while(i < N * 2 && events[i].first == events[j].first) {
            if(events[i].second == 1) {
                tot -= 1;
            } else {
                cnt += 1;
                tot += 1;
            }
            i += 1;
        }
        
        ans += (tot - 1 + tot - cnt) * cnt / 2;
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
