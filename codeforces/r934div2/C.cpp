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

    std::sort(A.begin(), A.end());
    
    if(A[0] > 0) {
        std::cout << 0 << '\n';
        return;
    }

    int p = N;
    for(int i = 1; i < N; i++) {
        if(A[i] - 1 > A[i - 1]) {
            p = i;
            break;
        }
    }

    std::vector<int> unique;
    for(int i = 0; i < p; ) {
        int j = i;
        while(i < p && A[i] == A[j]) {
            i += 1;
        }
        if(i - j == 1) {
            unique.push_back(A[j]);
        }
    }

    if(unique.size() > 1) {
        std::cout << unique[1] << '\n';
    } else {
        std::cout << A[p - 1] + 1 << '\n';
    }
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
