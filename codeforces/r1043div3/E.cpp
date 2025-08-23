#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <ranges>

void run_case() {
    int N, M, Q;
    std::cin >> N >> M >> Q;

    std::vector<std::pair<int, int>> A;
    for(int i = 0; i < N; i++) {
        int X;
        std::cin >> X;
        A.emplace_back(X, 0);
    } 

    for(int i = 0; i < M; i++) {
        int X;
        std::cin >> X;
        A.emplace_back(X, 1);
    }

    std::ranges::sort(A, std::greater<std::pair<int, int>>());
    
    int n = N + M;
    std::vector<int64_t> psum1(n + 1, 0);
    std::vector<int64_t> psum2(n + 1, 0);
    std::vector<int64_t> psum3(n + 1, 0);
    std::vector<int64_t> pcnt1(n + 1, 0);
    std::vector<int64_t> pcnt2(n + 1, 0);

    auto get_pos = [](int cnt, std::vector<int64_t>& pcnt) {
        int lo = 0;
        int hi = pcnt.size() - 1;
        int p = -1; 
        while(lo <= hi) {
            int mid = (lo + hi) >> 1;
            
            if(pcnt[mid + 1] >= cnt) {
                if(pcnt[mid + 1] == cnt) {
                    p = mid;
                }
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return p;
    };
    
    for(int i = 0; i < n; i++) {
        psum1[i + 1] = psum1[i] + A[i].first; 
        psum2[i + 1] = psum2[i] + (A[i].second == 0 ? A[i].first : 0);
        psum3[i + 1] = psum3[i] + (A[i].second == 1 ? A[i].first : 0);
        pcnt1[i + 1] = pcnt1[i] + (A[i].second == 0 ? 1 : 0);
        pcnt2[i + 1] = pcnt2[i] + (A[i].second == 1 ? 1 : 0);
    }

    for(int i = 0; i < Q; i++) {
        int X, Y, Z;
        std::cin >> X >> Y >> Z;
        
        int64_t ans = psum1[Z];

        int cx = pcnt1[Z];
        int cy = pcnt2[Z];

        if(cx > X) {
            int d = cx - X;
            int px = get_pos(X, pcnt1);
            int py = get_pos(d + cy, pcnt2);
            ans = psum2[px + 1] + psum3[py + 1];
        } else if(cy > Y) {
            int d = cy - Y;
            int px = get_pos(d + cx, pcnt1);
            int py = get_pos(Y, pcnt2);
            ans = psum2[px + 1] + psum3[py + 1];
        }

        std::cout << ans << '\n';
    }
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
