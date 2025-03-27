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

    std::vector<std::pair<int, int>> ans;
    while(A.size() > 1) {
        int n = A.size();
        std::vector<int> nxt;
        
        int l = -1;
        int r = -1;
        int mex = 0;
        for(int i = 0; i < n; i++) {
            if(A[i] != 0) {
                continue;
            }
            
            int j = i;
            while(i < n && A[i] == 0) {
                i += 1;
            }
            
            int cnt = i - j;
            if(cnt == 1) {
                if(j) {
                    mex = A[j - 1] == 1 ? 2 : 1;
                    l = j - 1;
                    r = i - 1;
                } else {
                    mex = A[i] == 1 ? 2 : 1;
                    l = j;
                    r = i;
                }
            } else if(cnt == n) {
                mex = 1;
                l = 0;
                r = 1;
            } else {
                mex = 1;
                l = j;
                r = i - 1;
            }
            break;
        }

        if(l == -1) {
            nxt.push_back(0);
            ans.emplace_back(0, n - 1);
        } else {
            for(int i = 0; i < l; i++) {
                nxt.push_back(A[i]);
            }
            nxt.push_back(mex);
            for(int i = r + 1; i < n; i++) {
                nxt.push_back(A[i]);
            }

            ans.emplace_back(l, r);
        }
        
        std::swap(A, nxt);
    }

    assert(A[0] == 0);

    int size = ans.size();
    std::cout << size << '\n';
    for(auto [l, r] : ans) {
        std::cout << l + 1 << ' ' << r + 1 << '\n';
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
