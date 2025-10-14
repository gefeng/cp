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

    std::ranges::sort(A);
    
    int64_t sum = 0;
    int cnt = 0;
    std::vector<int> s;
    for(int i = 0; i < N; ) {
        int j = i;
        while(i < N && A[i] == A[j]) {
            i += 1;
        }
        int64_t f = i - j;
        sum += f / 2 * 2 * A[j];
        cnt += f / 2;
        if(f % 2 == 1) {
            s.push_back(A[j]);
        }
    }

    if(cnt == 0) {
        std::cout << 0 << '\n';
        return;
    }

    int64_t ans = cnt > 1 ? sum : 0;
    
    int n = s.size();
    for(int i = 0; i < n; i++) {
        if(sum > s[i]) {
            ans = std::max(ans, s[i] + sum); 
        }
        if(i && sum + s[i - 1] > s[i]) {
            ans = std::max(ans, s[i] + s[i - 1] + sum);
        }
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
