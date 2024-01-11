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
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::map<int, int> m;
    int a = N;
    int b = N;
    int ans = 0;
    for(int i = 0; i < N; i++) {
        if(A[i] <= a || A[i] <= b) {
            if(A[i] <= a && A[i] <= b) {
                if(a < b) {
                    a = A[i];
                } else {
                    b = A[i];
                }
            } else {
                if(A[i] <= a) {
                    a = A[i];
                } else {
                    b = A[i];
                }
            }
        } else {
            if(a < b) {
                a = A[i];
            } else {
                b = A[i];
            }
            ans += 1;
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
