#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, Q;
    std::cin >> N >> Q;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }
    
    std::vector<int> save(N + 1, 0);
    save[1] = 1;

    int cnt = 0;
    for(int i = 1; i < N; i++) {
        if(A[i] <= A[i - 1]) {
            cnt += 1;
        } else {
            cnt = 0;
        }

        if(cnt >= 2) {
            save[i + 1] = save[i];
        } else {
            save[i + 1] = save[i] + 1;
        }
    }

    for(int i = 0; i < Q; i++) {
        int L, R;
        std::cin >> L >> R;
        L -= 1;
        R -= 1;

        int res = save[R + 1] - save[L];
        
        if(R - L + 1 < 3) {
            res = R - L + 1;
        } else {
            if(save[L + 1] == save[L]) {
                res += 1;
            }
            if(save[L + 1] == save[L + 2]) {
                res += 1;
            }
        }

        std::cout << res << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
