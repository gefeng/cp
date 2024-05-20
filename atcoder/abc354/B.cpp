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

    std::vector<std::pair<std::string, int>> A(N);
    int64_t sum = 0;
    for(int i = 0; i < N; i++) {
        std::cin >> A[i].first >> A[i].second;
        sum += A[i].second;
    }

    std::sort(A.begin(), A.end());

    std::cout << A[sum % N].first << '\n';    
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
