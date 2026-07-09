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
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int> a;
    for(int i = 0; i < N; ) {
        int j = i;
        while(i < N && A[i] == A[j]) {
            i++;
        }
        a.push_back(i - j);
    }

    std::ranges::sort(a);

    int m = a.size();
    int ans = 0;
    int left = N;
    int c = m;
    for(int t = 0, i = 0; t <= a.back(); t++) {
        while(i < m && a[i] <= t) {
            left -= a[i];
            c--;
            i++;
        }
        
        int s = left - c * t;
        if(K == s) {
            ans++;
        }
    }

    left = N;
    c = m;
    for(int i = 0; i < m; ) {
        int j = i;
        while(i < m && a[i] == a[j]) {
            c--;
            left -= a[i];
            i++;
        }
        
        int s = left - c * a[j];
        if(c && K > s && (K - s) % c == 0) {
            ans++;
        }
    }

    if(K > N && (K - N) % m == 0) {
        ans++;
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
