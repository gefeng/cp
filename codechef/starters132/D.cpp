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

    std::vector<int> A(N + 1, 0);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    bool end = false;
    int64_t cnt = 0;
    std::vector<int64_t> ans;
    for(int mex = 0; mex <= N; mex++) {
        if(end) {
            ans.push_back(-1);
            continue;
        }

        if(A[mex]) {
            ans.push_back(cnt + A[mex]); 
        } else {
            ans.push_back(cnt);
        }

        if(A[mex] == 0) {
            int x = mex;
            int y = 0;
            bool found = false;
            while(x) {
                if(x % 2 == 0) {
                    x /= 2;
                } else {
                    x = (x - 1) / 2;
                }
                y += 1;
                if(A[x] > 1) {
                    A[x] -= 1;
                    A[mex] += 1;
                    cnt += y;
                    found = true;
                    break;
                }
            }

            if(!found) {
                end = true;
            }
        }
    } 

    for(int i = 0; i <= N; i++) {
        std::cout << ans[i] << " \n"[i == N];
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
