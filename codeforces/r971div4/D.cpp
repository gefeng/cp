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
    
    std::vector<std::vector<int>> A(2);
    for(int i = 0; i < N; i++) {
        int X, Y;
        std::cin >> X >> Y;
        A[Y].push_back(X);
    } 

    for(int i = 0; i < 2; i++) {
        std::sort(A[i].begin(), A[i].end());
    }

    int64_t ans = 0;
    for(int j = 0; j < 2; j++) {
        int n = A[j].size();
        for(int i = 0; i < n; i++) {
            auto it = std::lower_bound(A[j ^ 1].begin(), A[j ^ 1].end(), A[j][i]); 
            if(it != A[j ^ 1].end() && *it == A[j][i]) {
                ans += n - 1;
            }

            auto l = std::lower_bound(A[j ^ 1].begin(), A[j ^ 1].end(), A[j][i] - 1);
            auto r = std::lower_bound(A[j ^ 1].begin(), A[j ^ 1].end(), A[j][i] + 1);
            if(l != A[j ^ 1].end() && r != A[j ^ 1].end() && *l == A[j][i] - 1 && *r == A[j][i] + 1) {
                ans += 1;
            }
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
