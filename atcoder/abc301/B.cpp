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
    for(int i = 1; i < N; i++) {
        if(A[i] > A[i - 1]) {
            for(int j = A[i - 1]; j < A[i]; j++) {
                ans.push_back(j);
            } 
        } else {
            for(int j = A[i - 1]; j > A[i]; j--) {
                ans.push_back(j);
            }
        }
    }

    ans.push_back(A.back());

    int sz = ans.size();
    for(int i = 0; i < sz; i++) {
        std::cout << ans[i] << " \n"[i == sz - 1];
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
