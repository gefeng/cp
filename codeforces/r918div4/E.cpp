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
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int64_t> psum_eve(N + 1, 0);
    std::vector<int64_t> psum_odd(N + 1, 0);
    for(int i = 0; i < N; i++) {
        if(i % 2 == 0) {
            psum_eve[i + 1] = psum_eve[i] + A[i];
            psum_odd[i + 1] = psum_odd[i];
        } else {
            psum_eve[i + 1] = psum_eve[i];
            psum_odd[i + 1] = psum_odd[i] + A[i];
        }
    }

    std::set<int64_t> s;
    s.insert(0);
    for(int i = 0; i < N; i++) {
        int64_t sum_eve = psum_eve[i + 1];
        int64_t sum_odd = psum_odd[i + 1];
        if(s.find(sum_eve - sum_odd) != s.end()) {
            std::cout << "Yes" << '\n';
            return;
        }

        s.insert(sum_eve - sum_odd);
    }

    std::cout << "No" << '\n';
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
