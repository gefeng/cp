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

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }
    
    std::vector<int> freq(N + 1, 0);
    for(int x : A) {
        freq[x] += 1;
    }

    std::vector<int> a;
    for(int i = 0; i <= N; i++) {
        if(freq[i]) {
            a.push_back(freq[i]);
        }
    }

    std::sort(a.begin(), a.end(), std::greater<int>());
    
    int cnt = 0;
    int ans = 0;
    int n = a.size();
    int len = 0;
    for(int i = 0; i < n; i++) {
        cnt += a[i] - 1;
        len += a[i]; 
        int rem = len % (i + 1);
        if(cnt >= rem) {
            ans = std::max(ans, len - rem);
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
