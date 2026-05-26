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

    std::vector<int> ans;
    int flip = 0;
    for(int i = N - 1; i >= 0; i--) {
        if(A[i] == 0) {
            continue;
        }
        
        if(flip) {
            if(A[i] > 0) {
                continue;
            }
            flip ^= 1;
            ans.push_back(i);
        } else {
            if(A[i] < 0) {
                continue;
            }
            flip ^= 1;
            ans.push_back(i);
        }
    }

    int size = ans.size();
    std::cout << size << '\n';
    for(int i = 0; i < size; i++) {
        std::cout << ans[i] + 1 << " \n"[i == size - 1];
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
