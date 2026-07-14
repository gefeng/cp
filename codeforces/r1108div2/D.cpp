#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int MAX = static_cast<int>(4e5);
constexpr int INF = static_cast<int>(2e9) + 10;

std::vector<int> best(MAX + 1, INF);

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    auto solve = [](std::vector<int> a) {
        int n = a.size();
        int odd = 0;
        int res = 0;
        for(int i = 0; i < n; i++) {
            if(a[i] % 2 == 1) {
                odd = 1;
            }
        }

        if(odd) {
            for(int i = 0; i < n; i++) {
                int x = a[i];
                while(x) {
                    if(x % 2 == 1) {
                        x--;
                    } else {
                        x /= 2;
                    }
                    res++;
                }
            }
        } else {
            int min_d = INF;
            for(int i = 0; i < n; i++) {
                int x = a[i];
                int c = 0;
                while(x % 2 == 0) {
                    x /= 2;
                    c++;
                }
                min_d = std::min(min_d, c);
            }

            res += min_d;
            for(int i = 0; i < n; i++) {
                int c = min_d;
                while(c) {
                    a[i] /= 2;
                    c--;
                }
            }

            for(int i = 0; i < n; i++) {
                int x = a[i];
                while(x) {
                    if(x % 2 == 1) {
                        x--;
                    } else {
                        x /= 2;
                    }
                    res++;
                }
            }
        }
        return res;
    };

    int64_t ans = solve(A);
    
    for(int i = 0; i <= 16; i++) {
        std::vector<int> a(A);
        int64_t inc = 0; 
        for(int j = 0; j < N; j++) {
            for(int b = 0; b < i; b++) {
                if(a[j] & (1 << b)) {
                    a[j] += 1 << b;
                    inc += 1 << b;
                }
                inc += best[a[j]] - a[j];
                a[j] = best[a[j]];
            }
        }
        ans = std::min(ans, solve(a) + inc);
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    for(int i = 1; i <= MAX; i++) {
        int min_c = INF;
        for(int j = 0; j <= 40; j++) {
            int x = j + i;
            int c = 0;
            while(x) {
                if(x % 2 == 1) {
                    x--;
                } else {
                    x /= 2;
                }
                c++;
            }
            if(j + c < min_c) {
                best[i] = j + i;
                min_c = j + c;
            }
        }
    }

    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
