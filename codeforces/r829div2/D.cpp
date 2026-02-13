#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <ranges>
#include <map>

void run_case() {
    int N, X;
    std::cin >> N >> X;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::ranges::sort(A);
    
    std::map<int, int> m;
    for(int i = 0; i < N; ) {
        int j = i;
        while(i < N && A[i] == A[j]) {
            i += 1;
        }

        int cnt = i - j;
        if(A[j] >= X) {
            break;
        }

        m[A[j]] += cnt;
    }

    while(!m.empty()) {
        auto [x, f] = *m.begin();

        if(f % (x + 1) == 0) {
            m.erase(x);
            if(x + 1 < X) {
                m[x + 1] += f / (x + 1);
            }
        } else {
            std::cout << "No" << '\n';
            return;
        }
    }

    std::cout << "Yes" << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
