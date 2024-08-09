#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int INF = int(2e9);

void run_case() {
    int N, K;
    std::cin >> N >> K;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int> a(A);
    std::sort(a.begin(), a.end());

    int x = 0;
    int y = 0;
    int min_d = INF;
    for(int i = 0, j = 0; i < N && j < N; ) {
        while(j + 1 < N && a[j + 1] == a[j]) {
            j += 1;
        }

        int cnt = j - i + 1;
        if(cnt - (N - cnt) >= K) {
            if(a[j] - a[i] < min_d) {
                min_d = a[j] - a[i];
                x = a[i];
                y = a[j];
            }     
            
            int k = i;
            while(i < N && a[i] == a[k]) {
                i += 1;
            }
        } else {
            j += 1;
        }
    }

    std::vector<std::pair<int, int>> ans;
    for(int i = 0; i < N; ) {
        if(ans.size() == K - 1) {
            ans.emplace_back(i + 1, N);
            break;
        }

        int sum = 0;
        int j = i;
        while(i < N && sum <= 0) {
            sum += A[i] >= x && A[i] <= y ? 1 : -1;
            i += 1;
        }
        
        ans.emplace_back(j + 1, i);
    }
    
    std::cout << x << ' ' << y << '\n';
    for(int i = 0; i < K; i++) {
        std::cout << ans[i].first << ' ' << ans[i].second << '\n';
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
