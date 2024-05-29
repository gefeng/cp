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

    std::sort(A.begin(), A.end());
    
    std::vector<int> ans;
    ans.push_back(A.back());
    A.pop_back();
    
    while(true) {
        std::vector<int> nxt;
        int max_v = 0;
        int size = A.size();
        for(int i = 0; i < size; i++) {
            max_v = std::max(max_v, A[i] & ans.back());
        }

        for(int i = 0; i < size; i++) {
            if((A[i] & ans.back()) == max_v) {
                ans.push_back(ans.back() & A[i]);
            } else {
                nxt.push_back(A[i]);
            }
        }

        if(nxt.empty()) {
            break;
        }
        std::swap(A, nxt);
    }

    for(int i = 0; i < N; i++) {
        std::cout << ans[i] << " \n"[i == N - 1]; 
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
