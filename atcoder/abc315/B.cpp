#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int M;
    std::cin >> M;

    std::vector<int> A(M);
    int sum = 0;
    for(int i = 0; i < M; i++) {
        std::cin >> A[i];
        sum += A[i];
    }

    int mid = sum / 2 + 1;
    int month = 1;
    int day = 1;
    for(int i = 0; i < M; i++) {
        if(mid > A[i]) {
            mid -= A[i];
            month += 1;
        } else {
            day = mid;
            break;
        }
    }

    std::cout << month << ' ' << day << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
