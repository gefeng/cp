#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int sum = 0;
    int ans = 0;
    std::vector<int> neg;
    for(int i = 0; i < N; i++) {
        if(A[i] >= 0) {
            sum += A[i];
            ans++;
        } else {
            neg.push_back(A[i]);
        }
    }

    std::ranges::sort(neg);
    
    for(int i = neg.size() - 1; i >= 0; i--) {
        if(sum + neg[i] >= 0) {
            sum += neg[i];
            ans++;
        }
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
