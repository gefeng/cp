#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<std::vector<int>> pos(N * 2 + 1);
    for(int i = 0; i < N; i++) {
        pos[A[i]].push_back(i);
    }

    int mex = 0;
    int p = 0;
    std::set<int> seen;
    std::vector<int> ans;
    while(true) {
        auto it = std::lower_bound(pos[mex].begin(), pos[mex].end(), p);
        
        if(it == pos[mex].end()) {
            ans.push_back(mex);
            if(p == A.size() - 1) {
                break;
            }
            seen.clear();
            p += 1;
            mex = 0;
        } else {
            for(int i = p; i <= *it; i++) {
                seen.insert(A[i]);
            } 
            while(seen.find(mex) != seen.end()) {
                mex += 1;
            }
            p = *it;
        }
    }
    
    int size = ans.size();
    std::cout << size << '\n';
    for(int i = 0; i < size; i++) {
        std::cout << ans[i] << " \n"[i == ans.size() - 1];
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
