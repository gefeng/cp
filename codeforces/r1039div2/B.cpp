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
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int l = 0;
    int r = N - 1;
    std::string ans = "";
    std::vector<int> a;
    int t = 0;
    while(l <= r) {
        if(l == r) {
            ans.push_back('L');
            a.push_back(A[l]);
            break;
        }

        if(t == 0) {
            if(A[l] > A[r]) {
                ans.push_back('L');
                a.push_back(A[l]);
                l += 1;
            } else {
                ans.push_back('R');
                a.push_back(A[r]);
                r -= 1;
            }
        } else {
            if(A[l] < A[r]) {
                ans.push_back('L');
                a.push_back(A[l]);
                l += 1;
            } else {
                ans.push_back('R');
                a.push_back(A[r]);
                r -= 1;
            }
        }
        t ^= 1;
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
