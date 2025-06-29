#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int MAX = int(1e9);

void run_case() {
    int N, M;
    std::cin >> N >> M;
    
    std::vector<std::vector<int>> A(N, std::vector<int>(M, 0));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            std::cin >> A[i][j];
        }
    }

    int lo = 0;
    int hi = MAX;
    int x = -1;
    int y = -1;
    while(lo <= hi) {
        int mid = (lo + hi) >> 1;
        
        bool ok = false;
        int p_1 = -1;
        int p_2 = -1;
        int n = 1 << M;
        
        std::vector<int> all(n, -1);
        for(int i = 0; i < N; i++) {
            int mask = 0;
            for(int j = 0; j < M; j++) {
                if(A[i][j] >= mid) {
                    mask |= 1 << j; 
                }
            }
            all[mask] = i;
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(all[i] != -1 && all[j] != -1 && (i | j) == n - 1) {
                    p_1 = all[i];
                    p_2 = all[j];
                    ok = true;
                    break;
                }
            }
            if(ok) {
                break;
            }
        }

        if(ok) {
            x = p_1;
            y = p_2;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    assert(x != -1);
    std::cout << x + 1 << ' ' << y + 1 << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
