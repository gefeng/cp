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
    std::vector<int> freq(N + 1, 0);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        if(A[i] <= N) {
            freq[A[i]] += 1;
        }
    }

    std::vector<int> trap(N + 1, 0);
    for(int i = 1; i <= N; i++) {
        for(int j = i; j <= N; j += i) {
            trap[j] += freq[i];
        }
    }

    std::cout << *std::max_element(trap.begin(), trap.end()) << '\n';;
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
