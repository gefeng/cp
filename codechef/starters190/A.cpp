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

    bool sorted = true;
    for(int i = 1; i < N; i++) {
        if(A[i] < A[i - 1]) {
            sorted = false;
            break;
        }
    }

    if(sorted) {
        std::cout << 0 << '\n';
        return;
    }
    

    int ans = 0;
    for(int i = 0; i < 30; i++) {
        bool ok = true;
        bool add = false;
        for(int j = 0; j < N; j++) {
            if(!(A[j] & (1 << i))) {
                A[j] |= 1 << i;
                add = true;
            }
            if(j && A[j] < A[j - 1]) {
                ok = false;
            }
        }
        if(add) {
            ans = 1 << i;
        }
        if(ok) {
            break;
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
