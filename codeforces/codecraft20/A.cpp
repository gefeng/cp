#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() { 
    int N, M;
    std::cin >> N >> M;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    if(A[0] >= M) {
        std::cout << A[0] << '\n';
        return;
    }

    int ans = 0;
    for(int i = M; i >= 0; i--) {
        int d = i - A[0];
        
        for(int j = 1; j < N; j++) {
            d -= A[j];
        }

        if(d <= 0) {
            ans = i;
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
