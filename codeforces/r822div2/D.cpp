#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <numeric>

void run_case() {
    int N, K;
    std::cin >> N >> K;
    
    K -= 1;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int64_t hp = A[K];
    int64_t max_v = hp;
    int l = K - 1;
    int r = K + 1;
    while(r < N) {
        if(hp + A[r] >= 0) {
            hp += A[r++];
            max_v = std::max(max_v, hp);
            continue;
        }
        
        int64_t now = max_v;
        int64_t need = -A[r] - hp;

        while(l >= 0 && need > 0) {
            if(now + A[l] >= 0) {
                need -= A[l];
                now += A[l--];
            } else {
                break;
            }
        }
        if(need > 0) {
            break;
        }

        max_v += -A[r] - hp - need;
        hp = -A[r] - need;
    }

    if(r == N) {
        std::cout << "YES" << '\n';
        return;
    }

    hp = A[K];
    max_v = hp;
    l = K - 1;
    r = K + 1;
    while(l >= 0) {
        if(hp + A[l] >= 0) {
            hp += A[l--];
            max_v = std::max(max_v, hp);
            continue;
        }
        
        int64_t now = max_v;
        int64_t need = -A[l] - hp;
        
        while(r < N && need > 0) {
            if(now + A[r] >= 0) {
                need -= A[r];
                now += A[r++];
            } else {
                break;
            }
        }
        if(need > 0) {
            break;
        }
        
        max_v += -A[l] - hp - need;
        hp = -A[l] - need;
    }

    if(l < 0) {
        std::cout << "YES" << '\n';
    } else {
        std::cout << "NO" << '\n';
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
