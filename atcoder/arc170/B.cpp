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

    std::vector<std::vector<int>> save(N, std::vector<int>(11, -1));
    int64_t ans = 0;
    int best = -1;
    for(int i = 1; i < N; i++) {
        int j = -1;
        
        save[i] = save[i - 1];
        std::vector<int>& a = save[i];
        a[A[i - 1]] = i - 1;

        for(int d = -9; d < 10; d++) {
            int x = A[i] + d;
            int y = A[i] + 2 * d;
            if(x > 0 && x <= 10 && a[x] != -1) {
                int k = a[x]; 
                if(y > 0 && y <= 10 && save[k][y] != -1) {
                    j = std::max(j, save[k][y]);
                } 
            }
        }

        best = std::max(best, j);
        ans += best + 1;
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
