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

    std::vector<int> is_prime(N + 1, 1);
    is_prime[1] = 0;
    for(int i = 2; i <= N; i++) {
        if(is_prime[i]) {
            for(int j = i + i; j <= N; j += i) {
                is_prime[j] = 0;
            }
        }
    }
    
    int i = 1;
    int j = 2;
    std::vector<int> ans;
    while(ans.size() != N) {
        while(j <= N && !is_prime[j]) {
            j += 1;
        }
        while(i <= N && is_prime[i]) {
            i += 1;
        }

        if(j > N) {
            ans.push_back(i++);
            continue;
        }

        ans.push_back(j++);
        if(ans.size() != N) {
            ans.push_back(i++);
        }
    }
    
    for(int i = 4; i < N - 1; i++) {
        if(i + 1 < N && is_prime[ans[i]]) {
            std::swap(ans[i], ans[i - 1]);
        }
    }

    for(int i = 0; i < N; i++) {
        std::cout << ans[i] << " \n"[i == N - 1];
    }
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
