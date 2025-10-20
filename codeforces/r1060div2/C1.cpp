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
constexpr int INF = static_cast<int>(2e9);

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
                std::cout << 1 << '\n';
                return;
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

    std::cout << 2 << '\n';
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
