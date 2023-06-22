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

    if(A[N - 1] == 1) {
        std::cout << "NO" << '\n';
        return;
    }

    std::vector<int> ans;
    for(int i = N - 1; i >= 0; ) {
        int cnt_zero = 0;
        while(i >= 0 && A[i] == 0) {
            cnt_zero += 1;
            i -= 1;
        } 

        int cnt_one = 0;
        while(i >= 0 && A[i] == 1) {
            cnt_one += 1;
            i -= 1;
        }

        for(int k = 0; k < cnt_one + cnt_zero - 1; k++) {
            ans.push_back(0);
        } 

        ans.push_back(cnt_one);
    }

    std::cout << "YES" << '\n';
    int sz = ans.size();
    for(int i = 0; i < sz; i++) {
        std::cout << ans[i] << " \n"[i == sz - 1];
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
