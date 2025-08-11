#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>
#include <set>

void run_case() {
    int N, K;
    std::cin >> N >> K;

    std::vector<int> A(N);
    std::map<int, int> m;
    for(int i = 0; i < N; i++) {
        std::cin >> A[i]; 
    }

    for(int i = 0; i < N; i++) {
        int X;
        std::cin >> X;
        m[X % K] += 1;
    }

    for(int i = 0; i < N; i++) {
        int r = A[i] % K;
        if(m.find(r) != m.end()) {
            if(--m[r] == 0) {
                m.erase(r);
            }
            continue;
        }

        r = K - (A[i] % K);
        if(m.find(r) != m.end()) {
            if(--m[r] == 0) {
                m.erase(r);
            }
            continue;
        }

        std::cout << "No" << '\n';
        return;
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
