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

    std::vector<int> eve;
    std::vector<int> odd;
    for(int i = 0; i < N; i++) {
        if(A[i] % 2 == 0) {
            eve.push_back(A[i]);
        } else {
            odd.push_back(A[i]);
        }
    }

    std::sort(eve.begin(), eve.end());
    std::sort(odd.begin(), odd.end());

    for(int i = 0, j = 0, k = 0; i < N; i++) {
        if(A[i] % 2 == 0) {
            A[i] = eve[j++];
        } else {
            A[i] = odd[k++];
        }
    }

    for(int i = 1; i < N; i++) {
        if(A[i] < A[i - 1]) {
            std::cout << "NO" << '\n';
            return;
        }
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
