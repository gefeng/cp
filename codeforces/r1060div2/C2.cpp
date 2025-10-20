#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

constexpr int MAX = static_cast<int>(4e5);
constexpr int INF = static_cast<int>(2e9) + 10;

std::vector<int> factors(MAX + 1, INF);

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<int> A(N);
    std::vector<int> B(N);

    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < N; i++) {
        std::cin >> B[i];
    }

    std::set<int> s;
    for(int i = 0; i < N; i++) {
        int x = A[i];
        if(x == 1) {
            continue;
        }
        while(x > 1) {
            int f = factors[x];
            if(s.find(f) != s.end()) {
                std::cout << 0 << '\n';
                return;
            }
            s.insert(f);
            while(x % f == 0) {
                x /= f;
            }
        }
    }

    int64_t ans = static_cast<int64_t>(2e18);
    for(int i = 0; i < N; i++) {
        int x = A[i];
        std::vector<int> a;
        
        if(A[i] != 1) {
            while(x > 1) {
                int f = factors[x];
                a.push_back(f);
                s.erase(f);
                while(x % f == 0) {
                    x /= f;
                }
            } 
        }

        x = A[i] + 1;
        while(x > 1) {
            int f = factors[x];
            if(s.find(f) != s.end()) {
                ans = std::min(ans, static_cast<int64_t>(B[i]));
                break;
            }
            while(x % f == 0) {
                x /= f;
            }
        }

        if(A[i] != 1) {
            for(int f : a) {
                s.insert(f);
            }
        }
    }

    int min_c = *std::ranges::min_element(B);
    int min_c2 = INF;
    int cnt = 0;
    int p = -1;
    for(int i = 0; i < N; i++) {
        if(min_c == B[i]) {
            p = i;
            cnt += 1;
        }
        if(B[i] < min_c2 && B[i] != min_c) {
            min_c2 = B[i];
        }
    }
    if(cnt > 1) {
        ans = std::min(ans, static_cast<int64_t>(min_c) + min_c);
    } else {
        ans = std::min(ans, static_cast<int64_t>(min_c) + min_c2);
        if(A[p] != 1) {
            int x = A[p];
            while(x > 1) {
                int f = factors[x];
                s.erase(f);
                while(x % f == 0) {
                    x /= f;
                }
            } 
        }

        for(int f : s) {
            int64_t t = (A[p] + f - 1) / f; 
            ans = std::min(ans, (f * t - A[p]) * B[p]);
        }
    }
    
    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    

    for(int f = 2; f <= MAX; f++) {
        for(int i = f; i <= MAX; i += f) {
            factors[i] = std::min(factors[i], f);
        }
    }

    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
