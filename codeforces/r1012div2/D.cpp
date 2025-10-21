#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int MAX = int(1e5) + 10;

std::vector<int> is_prime(MAX + 1, 1);
std::vector<int> primes;

void run_case() {
    int N;
    std::cin >> N;
    
    if(N == 2) {
        std::cout << 2 << ' ' << 1 << '\n';
        return;
    }

    std::vector<int> ans(N, 0);
    std::vector<int> used(N + 1, 0);

    int p = N / 3;
    while(!is_prime[p]) {
        p += 1;
    }

    ans[0] = p;
    used[p] = 1;
    for(int i = 1, j = 1; i < N; i += 2, j++) {
        if(p - j > 0 && p + j <= N) {
            ans[i] = p - j;
            ans[i + 1] = p + j;
            used[p - j] = 1;
            used[p + j] = 1;
        }
    }
    
    for(int i = 0, j = 1; i < N; i++) {
        if(ans[i] == 0) {
            while(j <= N && used[j]) {
                j += 1;
            }
            ans[i] = j++;
        } 
    }

    int cnt = 0;
    int64_t sum = 0;
    for(int i = 0; i < N; i++) {
        sum += ans[i]; 
        if(is_prime[(sum + i) / (i + 1)]) {
            cnt += 1;
        }
    }

    //std::cout << cnt << '\n';
    assert(cnt >= N / 3 - 1);

    for(int i = 0; i < N; i++) {
        std::cout << ans[i] << " \n"[i == N - 1];
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    is_prime[0] = 0;
    is_prime[1] = 0;
    for(int i = 2; i <= MAX; i++) {
        if(is_prime[i]) {
            primes.push_back(i);
            for(int j = i + i; j <= MAX; j += i) {
                is_prime[j] = 0;
            }
        }
    }

    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
