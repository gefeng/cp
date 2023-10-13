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
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::map<int, int> m;

    for(int x : A) {
        for(int f = 2; f * f <= x; f++) {
            if(x % f == 0) {
                int cnt = 0;
                while(x % f == 0) {
                    x /= f;
                    cnt += 1;
                }
                m[f] += cnt;
            }
        }

        if(x > 1) {
            m[x] += 1;
        }
    }

    for(auto [_, f] : m) {
        if(f % N != 0) {
            std::cout << "No" << '\n';
            return;
        }
    }

    std::cout << "Yes" << '\n';
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
