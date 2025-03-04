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

    int max_v = 0;
    int l = -1;
    int r = -1;
    for(int i = 0; i < N; i++) {
        int cnt_smaller = 0;
        int cnt_greater = 0;
        int last = -1;
        int max_d = -1;
        for(int j = i + 1; j < N; j++) {
            if(A[j] < A[i]) {
                cnt_smaller += 1;
            } else if(A[j] > A[i]) {
                cnt_greater += 1;
            }

            int d = cnt_smaller - cnt_greater;
            if(d > 0 && d > max_d) {
                max_d = d;
                if(A[j] < A[i]) {
                    last = j;
                }
            }
        }
        if(max_d > 0 && max_d > max_v) {
            max_v = max_d;
            l = i;
            r = last;
        }
    }

    if(max_v == 0) {
        std::cout << 1 << ' ' << 1 << '\n';
        return;
    }
    
    std::cout << l + 1 << ' ' << r + 1 << '\n';
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
