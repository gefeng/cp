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

    std::vector<std::string> A(N);
    std::vector<int> B(N);

    int min_v = (int)1e9;
    int min_i = 0; 
    for(int i = 0; i < N; i++) {
        std::cin >> A[i] >> B[i];

        if(min_v > B[i]) {
            min_v = B[i];
            min_i = i;
        }
    }

    for(int i = 0; i < N; i++) {
        int j = (i + min_i) % N;

        std::cout << A[j] << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
