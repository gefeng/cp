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
    int N, M;
    std::cin >> N >> M;

    std::vector<int> A(N);
    
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::map<int, int> m;
    for(int i = 0; i < M; i++) {
        int X;
        std::cin >> X;
        m[X] += 1;
    }

    std::vector<int> ans;
    for(int i = 0; i < N; ) {
        int j = i;
        while(i < N && A[i] == A[j]) {
            i += 1;
        }

        int cnt = std::max(0, i - j - m[A[j]]);
        while(cnt) {
            ans.push_back(A[j]);
            cnt -= 1;
        }
    }

    int size = ans.size();
    for(int i = 0; i < size; i++) {
        std::cout << ans[i] << " \n"[i == size - 1];
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
