#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

constexpr int INF = int(2e9) + 10;

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<int> A(N);
    int p = -1;
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        if(A[i] != -1 && A[i] != 1) {
            p = i;
        }
    }

    auto min_sum = [&](int l, int r) {
        int sum = 0;
        int res = INF;
        for(int i = l; i <= r; i++) {
            sum += A[i];
            res = std::min(res, sum);
            sum = std::min(sum, 0);
        }
        return res;
    };

    auto max_sum = [&](int l, int r) {
        int sum = 0;
        int res = -INF;
        for(int i = l; i <= r; i++) {
            sum += A[i];
            res = std::max(res, sum);
            sum = std::max(sum, 0);
        }
        return res;
    };

    if(p == -1) {
        int min_s = std::min(0, min_sum(0, N - 1));
        int max_s = std::max(0, max_sum(0, N - 1));
        std::cout << max_s - min_s + 1 << '\n';
        for(int i = min_s; i <= max_s; i++) {
            std::cout << i << " \n"[i == max_s];
        }
    } else {
        int l_1 = std::min(0, min_sum(0, p - 1));
        int r_1 = std::max(0, max_sum(0, p - 1));
        int l_2 = std::min(0, min_sum(p + 1, N - 1));
        int r_2 = std::max(0, max_sum(p + 1, N - 1));
        std::set<int> s;
        for(int i = l_1; i <= r_1; i++) {
            s.insert(i);
        }
        for(int i = l_2; i <= r_2; i++) {
            s.insert(i);
        }

        int min_v = 0;
        int max_v = 0;
        int sum = 0;
        for(int i = p - 1; i >= 0; i--) {
            sum += A[i]; 
            min_v = std::min(min_v, sum);
            max_v = std::max(max_v, sum);
        }

        min_v += A[p];
        max_v += A[p];
        int l = min_v;
        int r = max_v;
        
        for(int i = p + 1; i < N; i++) {
            min_v += A[i]; 
            max_v += A[i];
            l = std::min(min_v, l);
            r = std::max(max_v, r);
        }

        for(int i = l; i <= r; i++) {
            s.insert(i);
        }

        int n = s.size();
        std::cout << n << '\n';
        for(int x : s) {
            std::cout << x << ' ';
        }
        std::cout << '\n';
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
