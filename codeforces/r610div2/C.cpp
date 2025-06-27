#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, T, X, Y;
    std::cin >> N >> T >> X >> Y;

    std::vector<std::pair<int, int>> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i].second;
    }

    for(int i = 0; i < N; i++) {
        std::cin >> A[i].first;
    }

    std::sort(A.begin(), A.end());

    std::vector<int64_t> psum(N + 1, 0);
    int easy = 0;
    int hard = 0;
    for(int i = 0; i < N; i++) {
        psum[i + 1] = psum[i] + (A[i].second == 0 ? X : Y);
        if(A[i].second == 0) {
            easy += 1;
        } else {
            hard += 1;
        }
    }
    
    int ans = psum[N] <= T ? N : 0;

    for(int i = 0; i < N; ) {
        int j = i;
        while(i < N && A[i].first == A[j].first) {
            i += 1;
        }
        
        int t = A[j].first - 1;
        int cnt = 0;
        int64_t sum = psum[j];
        if(sum <= t) {
            cnt = j;
            t -= sum;
            int f = std::min(t / X, easy);
            cnt += f;
            t -= f * X;
            f = std::min(t / Y, hard);
            cnt += f;
            ans = std::max(ans, cnt);
        }

        for(int k = j; k < i; k++) {
            if(A[k].second == 0) {
                easy -= 1;
            } else {
                hard -= 1;
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
