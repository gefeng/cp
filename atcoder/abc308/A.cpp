#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    std::vector<int> A(8);
    
    for(int i = 0; i < 8; i++) {
        std::string S;
        std::cin >> S;

        A[i] = stoi(S);
    }

    bool ans = true;
    for(int i = 1; i < 8; i++) {
        if(A[i] < A[i - 1]) {
            ans = false;
            break;
        }
    }

    for(int i = 0; i < 8; i++) {
        if(A[i] < 100 || A[i] > 675 || A[i] % 25 != 0) {
            ans = false;
            break;
        }
    }

    std::cout << (ans ? "Yes" : "No") << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
