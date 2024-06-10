#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MAX = (int64_t)1e9;

void run_case() {
    int N;
    std::cin >> N;

    std::vector<std::pair<int, int>> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i].first;
        A[i].second = i;
    }

    std::sort(A.begin(), A.end(), std::greater<std::pair<int, int>>());

    int64_t lo = N;
    int64_t hi = MAX * N;
    while(lo <= hi) {
        int64_t mid = (lo + hi) >> 1;

        std::vector<int64_t> a(N);
        int64_t cnt = 0;
        bool ok = true;
        bool too_big = false;
        for(int i = 0; i < N; i++) {
            int64_t need = (mid + 1 + A[i].first - 1) / A[i].first;
            cnt += need;
            a[A[i].second] = need;
            if(need > MAX) {
                too_big = true;
            }
            if(cnt > mid) {
                ok = false;
                break;
            }
        }

        if(!ok) {
            lo = mid + 1;
        } else {
            if(too_big) {
                hi = mid - 1;
            } else {
                for(int i = 0; i < N; i++) {
                    std::cout << a[i] << " \n"[i == N - 1];
                } 
                return;
            }
        }
    }

    std::cout << -1 << '\n';
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
