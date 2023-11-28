#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>
#include <set>

constexpr int MAX = (int)1e5;

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::sort(A.begin(), A.end());

    std::vector<std::vector<int>> div(MAX + 1);
    for(int i = 0; i < N; i++) {
        for(int f = 1; f * f <= A[i]; f++) {
            if(A[i] % f == 0) {
                div[f].push_back(i);
                if(A[i] / f != f) {
                    div[A[i] / f].push_back(i);
                }
            }
        }
    }

    std::vector<int64_t> cnt(MAX + 1, 0);
    for(int i = 0; i < N; i++) {
        std::vector<int> d;
        for(int f = 1; f * f <= A[i]; f++) {
            if(A[i] % f == 0) {
                d.push_back(f);
                if(A[i] / f != f) {
                    d.push_back(A[i] / f);
                }
            }
        }

        std::sort(d.begin(), d.end(), std::greater<int>());

        for(int g : d) {
            auto it = std::lower_bound(div[g].begin(), div[g].end(), i);
            cnt[g] += (int64_t)(it - div[g].begin()) * (N - i - 1);
        }
    }

    for(int i = MAX; i > 0; i--) {
        for(int j = i + i; j <= MAX; j += i) {
            cnt[i] -= cnt[j];
        }
    }

    int64_t ans = 0;
    for(int i = 1; i <= MAX; i++) {
        ans += cnt[i] * i;
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
