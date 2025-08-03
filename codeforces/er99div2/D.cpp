#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int INF = static_cast<int>(2e9);

void run_case() {
    int N, X;
    std::cin >> N >> X;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    auto is_sorted = [](const std::vector<int>& a) {
        int n = a.size();
        for(int i = 0; i < n - 1; i++) {
            if(a[i] > a[i + 1]) {
                return false;
            }
        }
        return true;
    };

    if(is_sorted(A)) {
        std::cout << 0 << '\n';
        return;
    }

    int ans = INF;
    for(int k = 0; k < N; k++) {
        if(A[k] <= X) {
            continue;
        }

        std::vector<int> a(A);
        int now = A[k];
        a[k] = X;

        int cnt = 1;
        bool ok = true;
        for(int i = 0; i < N; i++) {
            int j = i;
            while(i + 1 < N && a[i + 1] >= a[i]) {
                i += 1;
            }
            
            if(j && a[j - 1] > a[j]) {
                ok = false;
                break;
            }

            if(i == N - 1) {
                break;
            }

            for(int k = j; k <= i; k++) {
                if(a[k] > now) {
                    if(k - 1 >= 0 && now < a[k - 1]) {
                        ok = false;
                        break;
                    }
                    std::swap(a[k], now);
                    cnt += 1;
                }
            }
        }

        if(ok) {
            ans = std::min(ans, cnt);
        }
    }

    std::cout << (ans == INF ? -1 : ans) << '\n';
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
