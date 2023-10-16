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

    std::string T;
    std::cin >> T;

    int n = T.size();

    std::vector<std::string> A(N);
    std::vector<int> prefix(N, 0);
    std::vector<int> suffix(N, 0);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i]; 
        
        int m = A[i].size();
        int len = 0;
        for(int j = 0, k = 0; j < m && k < n; j++) {
            if(A[i][j] == T[k]) {
                k += 1;
                len += 1;
            }
        }

        prefix[i] = len;
    
        len = 0;
        for(int j = m - 1, k = n - 1; j >= 0 && k >= 0; j--) {
            if(A[i][j] == T[k]) {
                k -= 1;
                len += 1;
            }
        }

        suffix[i] = len;
    }

    std::sort(suffix.begin(), suffix.end());

    int64_t ans = 0;
    for(int i = 0; i < N; i++) {
        int len1 = prefix[i];
        
        if(len1 == n) {
            ans += N;
        } else {
            auto it = std::lower_bound(suffix.begin(), suffix.end(), n - len1);
            ans += suffix.end() - it;
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
