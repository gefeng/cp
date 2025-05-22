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

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int> B(K);
    for(int i = 0; i < K; i++) {
        std::cin >> B[i];
    }

    std::sort(A.begin(), A.end());

    int lo = 1;
    int hi = N;
    int size = 0;
    std::vector<std::vector<int>> ans;
    while(lo <= hi) {
        int mid = (lo + hi) >> 1;
        
        int p = 0;
        bool ok = true;
        std::vector<int> freq(mid, 0);
        std::vector<std::vector<int>> testcase(mid);
        for(int i = K, j = N - 1; i >= 1; i--) {
            while(j >= 0 && A[j] >= i) {
                testcase[p].push_back(A[j]);
                if(++freq[p] > B[i - 1]) {
                    ok = false;
                    break;
                }
                p = (p + 1) % mid;
                j -= 1;
            }
            if(!ok) {
                break;
            }
        }
        
        if(ok) {
            size = mid;
            ans = std::move(testcase);
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    std::cout << size << '\n';
    for(int i = 0; i < size; i++) {
        int m = ans[i].size();
        std::cout << m << ' ';
        for(int j = 0; j < m; j++) {
            std::cout << ans[i][j] << " \n"[j == m - 1];
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
