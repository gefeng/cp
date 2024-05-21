#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int H, W, N, M;
    std::cin >> H >> W >> N >> M;
    
    std::vector<std::array<int, 3>> A(N);
    std::vector<std::pair<char, int>> B(M);

    for(int i = 0; i < N; i++) {
        std::cin >> A[i][0] >> A[i][1];
        A[i][0] -= 1;
        A[i][1] -= 1;
        A[i][2] = i;
    }

    for(int i = 0; i < M; i++) {
        std::cin >> B[i].first >> B[i].second;
    }
    
    std::sort(A.begin(), A.end());

    std::vector<int> removed_by(N, M + 1);
    for(int i = 0, u = 0, d = N - 1, st = 0, ed = H - 1; i < M; i++) {
        auto [c, k] = B[i];
        if(c == 'U') {
            while(u <= d && A[u][0] < st + k) {
                removed_by[A[u][2]] = i;
                u += 1;
            }
            st += k;
        } else if(c == 'D') {
            while(d >= u && A[d][0] > ed - k) {
                removed_by[A[d][2]] = i;
                d -= 1;
            }
            ed -= k;
        }
    }

    std::sort(A.begin(), A.end(), [](const auto& a, const auto& b) {
                return a[1] < b[1];
            });

    for(int i = 0, l = 0, r = N - 1, st = 0, ed = W - 1; i < M; i++) {
        auto [c, k] = B[i]; 
        if(c == 'L') {
            while(l <= r && A[l][1] < st + k) {
                removed_by[A[l][2]] = std::min(removed_by[A[l][2]], i);
                l += 1;
            }
            st += k;
        } else if(c == 'R') {
            while(r >= l && A[r][1] > ed - k) {
                removed_by[A[r][2]] = std::min(removed_by[A[r][2]], i);
                r -= 1;
            }
            ed -= k;
        }
    }

    int as = 0;
    int bs = 0;
    for(int i = 0; i < N; i++) {
        if(removed_by[i] != M + 1) {
            if(removed_by[i] % 2 == 0) {
                as += 1; 
            } else {
                bs += 1;
            }
        } 
    } 

    std::cout << as << ' ' << bs << '\n';
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
