#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t INF = int64_t(1e17);

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }
    
    std::vector<int> pos;
    std::vector<int> neg;
    for(int x : A) {
        if(x < 0) {
            neg.push_back(x);
        } else {
            pos.push_back(x);
        }
    }

    int n = pos.size();
    int m = neg.size();
    int64_t lo = 0;
    int64_t hi = INF;
    int64_t ans = 0;
    while(lo <= hi) {
        int64_t mid = (lo + hi) >> 1; 
        
        int64_t sum = 0;
        bool ok = true;
        
        int i = 0;
        int j = 0;
        while(i < n) {
            if(pos[i] > mid) {
                ok = false;
                break;
            }
            if(sum + pos[i] <= mid) {
                sum += pos[i++]; 
                continue;
            }

            if(j == m) {
                ok = false;
                break;
            }
            sum += neg[j++];
            if(sum < 0) {
                sum = 0;
            }
        }

        if(ok) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
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
