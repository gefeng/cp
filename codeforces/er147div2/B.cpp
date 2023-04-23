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
    std::vector<int> B(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < N; i++) {
        std::cin >> B[i];
    }

    //std::vector<int> cnt1(N + 1, 0);
    //std::vector<int> cnt2(N + 1, 0);
    
    int max_len = 0;
    int l = 0;
    int r = 0;
    for(int i = 0; i < N; i++) {
        int j = i;
        bool ok = A[i] != B[i];
        while(i + 1 < N && B[i + 1] >= B[i]) {
            if(A[i + 1] != B[i + 1]) {
                ok = true;
            }
            i += 1;
        }

        if(i - j + 1 > max_len && ok) {
            max_len = i - j + 1;
            l = j; 
            r = i;
        } 
    }

    std::cout << l + 1 << ' ' << r + 1 << '\n';
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
