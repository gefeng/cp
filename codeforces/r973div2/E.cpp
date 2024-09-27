#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

constexpr int INF = int(2e9);
constexpr int MAX = int(1e5);

std::vector<int> fact(MAX + 1);

int gcd(int a, int b) {
    if(a == 0) {
        return b;
    }
    return gcd(b % a, a);
}

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    std::set<int> s;
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        s.insert(A[i]);
    }

    int g = A[0];
    for(int i = 1; i < N; i++) {
        g = gcd(g, A[i]);
    }


    int now_g = *s.begin();
    int left = N;
    int64_t ans = 0;

    s.erase(now_g);
    while(now_g != g) {
        ans += now_g;
        left -= 1;
        
        int x = -1;
        int min_v = INF;
        for(int v : s) {
            int candidate = gcd(now_g, v);
            if(candidate < min_v) {
                min_v = candidate;
                x = v;
            }
        }

        s.erase(x);
        now_g = min_v;
    }

    ans += int64_t(g) * left;
    
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
