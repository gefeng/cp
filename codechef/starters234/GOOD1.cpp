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
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    std::vector<int> seen(N + 1, 0);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        seen[A[i]] = 1;
    }

    int ans = 0;
    int now = 1;
    for(int i = 0; i < N; i++) {
        int unique = 0;
        std::vector<int> cnt(N + 1, 0);
        for(int j = i; j >= 0; j--) {
            cnt[A[j]]++;
            if(cnt[A[j]] == 1) {
                unique++;
            } else if(cnt[A[j]] == 2) {
                unique--;
            }
            if(unique == 0) {
                break;
            }
        }

        if(unique == 0) {
            while(seen[now]) {
                now++;
            }
            A[i] = now;
            seen[now] = 1;
            ans++;
        }
    }
    
    std::cout << ans << '\n';
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
