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
    
    bool inc = true;
    bool dec = true;
    for(int i = 1; i < N; i++) {
        if(A[i] < A[i - 1]) {
            inc = false;
        }
        if(A[i] > A[i - 1]) {
            dec = false;
        }
    }

    if(inc || dec) {
        std::cout << "Yes" << '\n';
        return;
    }

    int p = 0;
    while(p + 1 < N && A[p + 1] >= A[p]) {
        p += 1;
    }

    while(p + 1 < N && A[p + 1] <= A[p]) {
        p += 1;
    }
    
    std::cout << (p == N - 1 ? "Yes" : "No") << '\n';
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
