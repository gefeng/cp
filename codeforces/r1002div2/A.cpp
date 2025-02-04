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
    std::vector<int> B(N);

    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < N; i++) {
        std::cin >> B[i];
    }

    std::sort(A.begin(), A.end());
    std::sort(B.begin(), B.end());
    
    int cnt_1 = 0;
    int cnt_2 = 0;
    for(int i = 0; i < N; ) {
        int j = i;
        while(i < N && A[i] == A[j]) {
            i += 1;
        }
        cnt_1 += 1;
    }

    for(int i = 0; i < N; ) {
        int j = i;
        while(i < N && B[i] == B[j]) {
            i += 1;
        }
        cnt_2 += 1;
    }

    if(cnt_1 > 2 || cnt_2 > 2) {
        std::cout << "Yes" << '\n';
        return;
    }

    if(cnt_1 == 2 && cnt_2 == 2) {
        std::cout << "Yes" << '\n';
        return;
    }

    std::cout << "No" << '\n';
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
