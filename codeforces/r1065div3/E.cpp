#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

int gcd(int a, int b) {
    if(a == 0) {
        return b;
    }
    return gcd(b % a, a);
}

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> pf(N + 1, 0);
    std::vector<int> is_prime(N + 1, 1);
    for(int i = 2; i <= N; i++) {
        if(is_prime[i]) {
            pf[i] = i;
            for(int j = i + i; j <= N; j += i) {
                is_prime[j] = 0;
            }
        }
    }
    for(int i = 2; i <= N; i++) {
        if(!is_prime[i]) {
            continue;
        }
        for(int j = i + i; j <= N; j += i) {
            pf[j] = std::max(pf[j], i);
        } 
    }

    std::vector<std::vector<int>> groups(N + 1);
    for(int i = 2; i <= N; i++) {
        groups[pf[i]].push_back(i);
    }

    std::vector<int> alone;
    for(int i = 1; i <= N; i++) {
        if((i == 1 || is_prime[i]) && groups[i].size() <= 1) {
            alone.push_back(i);
        }
    }

    std::vector<int> ans(N);
    int p = 0;
    for(int i = 2; i <= N; i++) {
        int size = groups[i].size();
        if(size > 1) {
            for(int j = 0; j < size; j++) {
                if(p > 2 && gcd(ans[p - 3], ans[p - 2]) != 1 && gcd(ans[p - 1], groups[i][j]) != 1 && gcd(ans[p - 2], ans[p - 1]) != 1 && !alone.empty()) {
                    ans[p] = ans[p - 1];
                    ans[p - 1] = alone.back();
                    alone.pop_back();
                    ans[++p] = groups[i][j];
                } else {
                    ans[p] = groups[i][j];
                }
                p += 1;
            }
        }
    }

    while(!alone.empty()) {
        ans[p++] = alone.back();
        alone.pop_back();
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
