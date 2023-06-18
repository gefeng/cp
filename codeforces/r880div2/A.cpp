#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }
    
    std::sort(A.begin(), A.end());

    if(A[0] != 0) {
        std::cout << "NO" << '\n';
        return;
    }

    int pre_cnt = 0;
    int pre = 0; 
    for(int i = 0; i < N; ) {
        int j = i;
        while(i < N && A[i] == A[j]) {
            i += 1;
        }

        int cnt = i - j;

        if(A[j] != 0 && (cnt > pre_cnt || A[j] - 1 != pre)) {
            std::cout << "NO" << '\n';
            return;
        }

        pre_cnt = cnt;
        pre = A[j];
    } 

    std::cout << "YES" << '\n';
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
