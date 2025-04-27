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

    std::sort(A.begin(), A.end());

    std::vector<std::pair<int, int>> a;
    for(int i = 0; i < N; ) {
        int j = i;
        while(i < N && A[j] == A[i]) {
            i += 1;
        }
        if(i - j > 3) {
            std::cout << "Yes" << '\n';
            return;
        }
        
        a.emplace_back(A[j], i - j);
    }

    int n = a.size();
    for(int i = 0; i < n; i++) {
        if(a[i].second > 1) {
            if(i + 1 == n || a[i + 1].first != a[i].first + 1) {
                continue;
            }

            while(i + 1 < n && a[i + 1].first == a[i].first + 1) {
                if(a[i + 1].second > 1) {
                    std::cout << "Yes" << '\n';
                    return;
                }
                i += 1;
            }
        }
    }

    std::cout << "No" << '\n';
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
