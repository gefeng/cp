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
    
    int64_t ans = 0;
    for(int i = 0; i < N; ) {
        int j = i;
        while(i < N && A[i] == A[j]) {
            i += 1;
        }

        if(A[j] != 2) {
            int len = i - j;
            ans += int64_t(len + 1) * len / 2;
        }
    }
    
    int sum = 0;
    std::map<int, int> m;
    m[0] += 1;
    for(int i = 0; i < N; i++) {
        sum += A[i];
        ans += m[sum - (i + 1) * 2];
        m[sum - (i + 1) * 2] += 1;
    }

    m.clear();
    sum = 0;
    m[0] = 1;
    int pre = -1;
    for(int i = 0; i < N; i++) {
        if(A[i] == 2) {
            m = std::map<int, int>();
            sum = 0;
            m[0] = 1;
            pre = i;
        } else {
            sum += A[i];
            int x = sum - (i - pre) * 2;
            ans -= m[x];
            m[x] += 1;
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
