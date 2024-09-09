#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

constexpr int64_t MOD = int64_t(998244353);

void run_case() {
    int N;
    int64_t K;
    std::cin >> N >> K;
    
    std::vector<int64_t> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }
    
    int64_t pre = 1;
    int64_t now = 0;
    int64_t sum = 0;
    std::map<int64_t, int64_t> m;
    m[0] = 1; 
    for(int i = 0; i < N; i++) {
        sum += A[i]; 

        now = pre;
        if(m.find(sum - K) != m.end()) {
            now -= m[sum - K];
            now += MOD;
            now %= MOD;
        } 
        m[sum] += now;
        m[sum] %= MOD;
        pre += now;
        pre %= MOD;
    }

    std::cout << now << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
