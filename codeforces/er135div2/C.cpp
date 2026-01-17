#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

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

    std::map<int, int> ma;
    std::map<int, int> mb;
    int ans = 0;
    
    for(int i = 0; i < N; i++) {
        ma[A[i]] += 1;
        mb[B[i]] += 1;
    }

    for(auto& [v, f1] : ma) {
        if(mb.find(v) != mb.end()) {
            int f2 = mb[v];
            int d = std::min(f1, f2);
            f1 -= d;
            mb[v] -= d;
        }
    }

    A.clear();
    B.clear();
    for(auto [v, f] : ma) {
        while(f) {
            A.push_back(v);
            f -= 1;
        }
    }

    for(auto [v, f] : mb) {
        while(f) {
            B.push_back(v); 
            f -= 1;
        }
    }

    for(int& x : A) {
        if(x > 9) {
            int len = 0;
            while(x) {
                x /= 10;
                len += 1;
            }
            x = len;
            ans += 1;
        }
    }

    for(int& x : B) {
        if(x > 9) {
            int len = 0;
            while(x) {
                x /= 10;
                len += 1;
            }
            x = len;
            ans += 1;
        }
    }

    std::array<int, 10> a = {};
    std::array<int, 10> b = {};
    for(int x : A) {
        a[x] += 1;
    }
    for(int x : B) {
        b[x] += 1;
    }

    for(int i = 1; i < 10; i++) {
        int d = std::min(a[i], b[i]);
        a[i] -= d;
        b[i] -= d;
    }

    for(int i = 2; i < 10; i++) {
        assert(a[i] == 0 || b[i] == 0);
        ans += a[i] + b[i]; 
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
