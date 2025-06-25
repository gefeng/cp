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
    std::vector<int> used(N + 1, 0);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        used[A[i]] = 1;
    }

    std::vector<std::vector<int>> G(N);
    for(int i = 0; i < N - 1; i++) {
        int U, V;
        std::cin >> U >> V;
        U -= 1;
        V -= 1;
        G[U].push_back(V);
        G[V].push_back(U);
    }
    
    std::vector<int> free;
    for(int i = 1; i <= N; i++) {
        if(!used[i]) {
            free.push_back(i);
        }
    }

    int ans = N;
    for(int i = 0; i < N; i++) {
        if(A[i]) {
            bool good = true;
            int cnt = 0;
            for(int nei : G[i]) {
                if(A[nei] > A[i]) {
                    good = false;
                    break;
                } else if(A[nei] == 0) {
                    cnt += 1;
                }
            }
            if(!good) {
                continue; 
            }

            if(cnt <= std::upper_bound(free.begin(), free.end(), A[i]) - free.begin()) {
                ans = std::min(ans, A[i]); 
            }
        } else {
            int cnt = 0;
            int max_v = 0;
            for(int nei : G[i]) {
                max_v = std::max(max_v, A[nei]);
                if(A[nei] == 0) {
                    cnt += 1;
                }
            }

            int lo = 0;
            int hi = free.size() - 1;
            int res = -1;
            while(lo <= hi) {
                int mid = (lo + hi) / 2;
                if(free[mid] < max_v) {
                    lo = mid + 1;
                    continue;
                }
                
                if(mid >= cnt) {
                    res = mid;
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            }
            if(res != -1) {
                ans = std::min(ans, free[res]);
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
