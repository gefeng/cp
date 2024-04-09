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
    int N, C, D;
    std::cin >> N >> C >> D;

    std::vector<int> A(N * N);
    for(int i = 0; i < N * N; i++) {
        std::cin >> A[i];
    }

    std::sort(A.begin(), A.end());
    
    std::vector<std::vector<int>> a(N, std::vector<int>(N, 0));
    a[0][0] = A[0];

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(i + 1 < N) {
                a[i + 1][j] = a[i][j] + C;
            }
            if(j + 1 < N) {
                a[i][j + 1] = a[i][j] + D;
            }
        }
    }

    std::vector<int> v;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            v.push_back(a[i][j]);
        }
    }

    std::sort(v.begin(), v.end());
    
    std::cout << (A == v ? "Yes" : "No") << '\n';
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
