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
    
    auto query = [&](std::vector<int>& a) {
        std::cout << "? ";
        for(int i = 0; i < K; i++) {
            std::cout << a[i] + 1;
            if(i < K - 1) {
                std::cout << ' ';
            } else {
                std::cout << std::endl;
            }
        }
        int res = 0;
        std::cin >> res;
        return res;
    };

    std::vector<int> ans(N, 0);

    int sum_p = 0;
    std::vector<int> save;
    for(int i = 0; i < K + 1; i++) {
        std::vector<int> a(K);
        for(int j = 0, k = i; j < K; j++, k = (k + 1) % (K + 1)) {
            a[j] = k; 
        }

        int p = query(a);
        save.push_back(p);
        sum_p += p;
        sum_p %= 2;
    }

    for(int i = 0; i < K + 1; i++) {
        ans[(i + K) % (K + 1)] = (sum_p - save[i] + 2) % 2;
    }

    for(int i = K + 1; i < N; i++) {
        std::vector<int> a(K);
        sum_p = 0;
        for(int j = 0, k = i - K + 1; j < K; j++, k++) {
            a[j] = k;
            if(j < K - 1) {
                sum_p += ans[k];
                sum_p %= 2;
            }
        }
        int p = query(a);
        ans[i] = (p - sum_p + 2) % 2;
    }

    std::cout << "! ";
    for(int i = 0; i < N; i++) {
        std::cout << ans[i] << " \n"[i == N - 1]; 
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
