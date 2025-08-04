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
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    //j - A[j] = A[i] + i;
    int64_t ans = 0;
    std::map<int, int> m;
    for(int i = 0; i < N; i++) {
        int t = i - A[i];
        if(m.find(t) != m.end()) {
            ans += m[t];
        }
        m[A[i] + i] += 1;
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
