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

    int k = A.back();
    int sum = 0;
    for(int i = 0; i < N; i++) {
        sum ^= A[i] % (k + 1);
    }

    if(sum) {
        std::cout << -1 << '\n';
        return;
    }

    bool zero = true;
    for(int i = 0; i < N; ) {
        int j = i;
        while(i < N && A[i] == A[j]) {
            i += 1;
        }
        if((i - j) % 2 == 1) {
            zero = false;
            break;
        }
    }

    if(zero) {
        std::cout << 0 << '\n';
        return;
    }

    for(int i = N - 1; i >= 0; ) {
        int j = i;
        while(i >= 0 && A[i] == A[j]) {
            i -= 1;
        }

        if((j - i) % 2 == 1) {
            std::cout << A[j] - 1 << '\n';
            return;
        }
    }

    std::cout << 0 << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
