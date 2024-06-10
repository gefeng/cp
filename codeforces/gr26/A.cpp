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

    if(A[0] == A.back()) {
        std::cout << "NO" << '\n';
        return;
    }

    std::string ans(N, 'B');
    bool found = false;
    for(int i = 1; i < N; i++) {
        if(A[i] == A[i - 1]) {
            ans[i - 1] = 'R';
            found = true;
            break;
        }
    }

    if(!found) {
        ans[0] = 'R';
    }

    std::cout << "YES" << '\n' << ans << '\n';
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
