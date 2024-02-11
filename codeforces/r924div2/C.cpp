#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

void run_case() {
    int N, X;
    std::cin >> N >> X;

    auto get_divisors = [](int x) {
        std::vector<int> divisors;
        for(int f = 1; f * f <= x; f++) {
            if(x % f == 0) {
                divisors.push_back(f);
                if(x / f != f) {
                    divisors.push_back(x / f);
                }
            }
        }

        return divisors;
    };

    std::set<int> k;

    std::vector<int> d = get_divisors(N + X - 2);
    for(int x : d) {
        if(x % 2 == 0 && (N + X - 2) / x + 1 > 1) {
            int cand = (N + X - 2) / x + 1;
            if(cand > 1 && cand >= X) {
                k.insert(cand);
            }
        }
    } 

    d = get_divisors(N - X);
    for(int x : d) {
        if(x % 2 == 0) {
            int cand = (N - X) / x + 1;
            if(cand > 1 && cand >= X) {
                k.insert(cand);
            }
        }
    }

    std::cout << k.size() << '\n';
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
