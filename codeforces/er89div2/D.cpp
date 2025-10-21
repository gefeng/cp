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
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int max_v = *std::max_element(A.begin(), A.end());
    std::vector<int> is_p(max_v + 1, 1);
    std::vector<int> min_f(max_v + 1, max_v + 1);


    for(int i = 2; i <= max_v; i++) {
        if(is_p[i]) {
            for(int j = i; j <= max_v; j += i) {
                if(j != i) {
                    is_p[j] = 0;
                }
                min_f[j] = std::min(min_f[j], i);
            }
        } 
    }

    std::vector<std::pair<int, int>> ans(N, {-1, -1});
    for(int i = 0; i < N; i++) {
        std::vector<int> factors;
        
        int x = A[i];
        while(min_f[x] != max_v + 1) {
            int f = min_f[x];
            factors.push_back(f);
            while(x % f == 0) {
                x /= f;
            }
        }

        int size = factors.size();
        if(size == 1) {
            continue;
        }

        ans[i].first = factors[0];
        ans[i].second = 1;
        for(int j = 1; j < size; j++) {
            ans[i].second *= factors[j];
        }
    }

    for(int i = 0; i < N; i++) {
        std::cout << ans[i].first << " \n"[i == N - 1];
    }

    for(int i = 0; i < N; i++) {
        std::cout << ans[i].second << " \n"[i == N - 1];
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
