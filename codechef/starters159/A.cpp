#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, X;
    std::cin >> N >> X;
    
    std::vector<int> A(N);
    std::vector<int> B(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < N; i++) {
        std::cin >> B[i];
    }

    int cnt = 0;
    std::vector<int> need;
    for(int i = 0; i < N; i++) {
        if(A[i] > B[i]) {
            cnt += 1;
        } else {
            need.push_back(B[i] - A[i] + 1);
        }
    }

    std::sort(need.begin(), need.end());
    for(int x : need) {
        if(X >= x) {
            X -= x;
            cnt += 1;
        }
    }

    std::cout << (cnt > N / 2 ? "Yes" : "No") << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;
    while(T--) {
       run_case();
    }
}
