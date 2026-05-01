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

    std::vector<int> A(N * 2);
    for(int i = 0; i < N * 2; i++) {
        std::cin >> A[i];
    }

    int ans = 1;
    int p1 = -1;
    int p2 = -1;
    for(int i = 0; i < N * 2; i++) {
        if(A[i] == 0) {
            if(p1 == -1) {
                p1 = i;
            } else {
                p2 = i;
            }
        }
    }

    auto expand = [&](int pl, int pr) {
        int l = pl;
        int r = pr;
        std::vector<int> seen(N, 0);
        seen[A[pl]] = 1;
        while(true) {
            if(l - 1 >= 0 && r + 1 < N * 2 && A[l - 1] == A[r + 1]) {
                seen[A[l - 1]] = 1; 
                l--;
                r++;
            } else {
                break;
            }
        }

        int mex = 0;
        for(int i = 0; i < N; i++) {
            if(seen[i]) {
                mex++;
            } else {
                break;
            }
        }

        return mex; 
    };

    ans = std::max(expand(p1, p1), expand(p2, p2));
    
    {
        int l = p1 + 1;
        int r = p2 - 1;
        std::vector<int> seen(N, 0);
        seen[0] = 1;
       
        while(l <= r) {
            if(A[l] == A[r]) {
                seen[A[l]] = 1;
                l++;
                r--;
            } else {
                break;
            }
        }

        if(l >= r) {
            l = p1 - 1;
            r = p2 + 1;
            while(l >= 0 && r < N * 2) {
                if(A[l] == A[r]) {
                    seen[A[l]] = 1;
                    l--;
                    r++;
                } else {
                    break;
                }
            }

            int mex = 0;
            for(int i = 0; i < N; i++) {
                if(seen[i]) {
                    mex++;
                } else {
                    break;
                }
            }
            ans = std::max(ans, mex);
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
