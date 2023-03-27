#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using LL = long long;

LL gcd(LL a, LL b) {
    if(a == 0) {
        return b;
    }
    return gcd(b % a, a);
}

LL lcm(LL a, LL b) {
    return a * b / gcd(a, b);
}

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    std::vector<int> B(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i] >> B[i];
    }

    std::vector<std::pair<LL, LL>> s;
    for(int i = 0; i < N; i++) {
        if(!s.empty()) { 
            LL g = gcd(s.back().first, 1LL * A[i] * B[i]); 
            LL l = lcm(s.back().second, 1LL * B[i]);

            if(g % l == 0) {
                s.back().first = g;
                s.back().second = l;
            } else {
                s.emplace_back(1LL * A[i] * B[i], B[i]);
            }
        } else {
            s.emplace_back(1LL * A[i] * B[i], B[i]);
        }
    }

    std::cout << s.size() << '\n';
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
