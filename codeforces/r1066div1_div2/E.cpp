#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, K;
    std::cin >> N >> K;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::ranges::sort(A);
    
    std::vector<std::pair<int, int>> a;
    for(int i = 0; i < N; ) {
        int j = i;
        while(i < N && A[i] == A[j]) {
            i += 1;
        }
        a.emplace_back(A[j], i - j);
    }

    int ans = 0;
    int len = 0;
    int head = -1;
    int n = a.size();
    for(int i = 0; i < n; i++) {
        auto [v, f] = a[i];
        
        if(head == -1) {
            head = v;
            len = f;
            continue;
        }

        if(len <= K) {
            head = v;
            len = f;
        } else {
            int tail = len - K + head;
            if(tail >= v) {
                len += f;
            } else {
                ans = std::max(ans, len - K);
                head = v;
                len = f;
            }
        }
    }

    if(len > K) {
        ans = std::max(ans, len - K);
    }

    std::cout << ans << '\n';
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
