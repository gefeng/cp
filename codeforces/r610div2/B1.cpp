#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, P, K;
    std::cin >> N >> P >> K;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::sort(A.begin(), A.end());

    int cnt = 0;
    int ans = 0;
    int have = P;
    for(int i = 0; i < N; ) {
        if(i + 1 < N && have >= A[i + 1]) {
            cnt += 2;
            have -= A[i + 1];
            i += 2;
        } else {
            if(have >= A[i]) {
                cnt += 1;
                have -= A[i];
            }
            break;
        }
    }

    ans = cnt;
    have = P;
    cnt = 0;
    for(int i = 1; i < N; ) {
        if(i + 1 < N && have >= A[i + 1]) {
            cnt += 2;
            have -= A[i + 1];
            i += 2;
        } else {
            if(have >= A[i]) {
                cnt += 1;
                have -= A[i];
            }
            break;
        }
    }

    if(have >= A[0]) {
        cnt += 1;
    }

    ans = std::max(ans, cnt);

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
