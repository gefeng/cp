#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int MAX = int(1e6);

void run_case() {
    int N, D;
    std::cin >> N >> D;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::sort(A.begin(), A.end());
    
    std::vector<int> freq(MAX + 1, 0);
    for(int x : A) {
        freq[x] += 1;
    }
    
    int ans = 0;
    if(D == 0) {
        A.erase(std::unique(A.begin(), A.end()), A.end());
        ans = N - int(A.size());
    } else {
        std::vector<int> vis(MAX + 1, 0);
        for(int i = 0; i <= MAX; i++) {
            if(vis[i]) {
                continue;
            }
            std::vector<int> a;
            for(int j = i; j <= MAX; j += D) {
                vis[j] = 1;
                a.push_back(freq[j]); 
            }
            
            if(a.empty()) {
                continue;
            }

            int n = a.size();
            int remove = a[0];
            int keep = 0;

            for(int j = 1; j < n; j++) {
                int n_remove = std::min(remove, keep) + a[j];
                int n_keep = remove;
                std::swap(remove, n_remove);
                std::swap(keep, n_keep);
            }

            ans += std::min(remove, keep);
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
