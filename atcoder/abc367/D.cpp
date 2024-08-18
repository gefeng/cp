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

    std::map<int, int> suffix;
    std::map<int, int> prefix;
    
    int64_t sum = 0;
    for(int i = N - 1; i >= 0; i--) {
        sum += A[i];
        if(i > 0) {
            suffix[sum % M] += 1;
        }
    }

    int64_t ssum = sum;
    int64_t ans = 0;
    sum = 0;
    for(int i = 0; i < N; i++) {
        if(i > 0 && --suffix[ssum % M] == 0) {
            suffix.erase(ssum % M);
        }
        ssum -= A[i];

        int rem = sum % M;
        if(i && prefix.find(rem) != prefix.end()) {
            ans += prefix[rem];
        }
        prefix[sum % M] += 1;

        if(i < N - 1 && suffix.find((M - rem) % M) != suffix.end()) {
            ans += suffix[(M - rem) % M];
        }

        sum += A[i];
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
