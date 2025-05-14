#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>
#include <map>

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::set<int> seen;
    for(int i = 0; i < N; i++) {
        int shift = A[i];
        int x = i + shift < 0 ? (N + ((i + shift) % N)) % N : (i + shift) % N;
        if(seen.find(x) != seen.end()) {
            std::cout << "NO" << '\n';
            return;
        }

        seen.insert(x);
    }

    std::cout << "YES" << '\n';
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
