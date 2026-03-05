#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <ranges>

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int> A(N);
    std::vector<int> B(M);
    
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < M; i++) {
        std::cin >> B[i];
    }

    std::ranges::sort(A);    

    int max_v = N + M;
    std::vector<int> cnt(max_v + 1, 0);
    std::vector<int> fa(max_v + 1, 0);
    for(int i = 0; i < N; i++) {
        fa[A[i]] += 1;
    }
    for(int x = 1; x <= max_v; x++) {
        if(fa[x] == 0) {
            continue;
        }
        for(int y = x; y <= max_v; y += x) {
            cnt[y] += fa[x];
        }
    }

    std::ranges::sort(B, [&](int x, int y) {
                return cnt[x] < cnt[y];
            });

    int a = M - 1;
    int b = 0;
    while(b < M && cnt[B[b]] == 0) {
        b += 1;
    }
    while(a >= 0 && cnt[B[a]] == N) {
        a -= 1;
    }

    int l = b;
    int r = a;
    int t = 0;
    if(l > r) {
        
    } else {
        while(l <= r) {
            if(l == r) {
                t = 1;
                break;
            }
            l += 1;
            r -= 1;
        }
    }

    a = M - 1 - a;
    if(t == 0) {
        std::cout << (a > b ? "Alice" : "Bob") << '\n';
    } else {
        std::cout << (b > a ? "Bob" : "Alice") << '\n';
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
