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
    int N, K;
    std::cin >> N >> K;

    std::string S;
    std::cin >> S;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int ans = 0;
    if(K == 0) {
        for(int i = 0; i < N; i++) {
            if(S[i] == 'B') {
                ans = std::max(ans, A[i]);
            }
        }
        std::cout << ans << '\n';
        return;
    }

    int lo = 0;
    int hi = MAX;
    while(lo <= hi) {
        int mid = (lo + hi) >> 1;
        int cnt = 0;
        
        for(int i = 0; i < N; ) {
            if(S[i] == 'R') {
                i += 1;
                continue;
            } else {
                if(A[i] > mid) {
                    int j = i;
                    while(i < N) {
                        if(S[i] == 'B' || A[i] <= mid) {
                            i += 1;
                        } else {
                            break;
                        }
                    }
                    cnt += 1;
                } else {
                    i += 1;
                    continue;
                }
            }
        }

        if(cnt <= K) {
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
