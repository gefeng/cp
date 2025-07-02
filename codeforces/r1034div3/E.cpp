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
    std::vector<int> freq(N + 1, 0);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        freq[A[i]] += 1;
    }

    std::vector<int> diff(N + 2, 0);
    
    std::ranges::sort(A);

    int mex = 0;
    for(int i = 0; i < N; ) {
        int j = i;
        while(i < N && A[i] == A[j]) {
            i += 1;
        }
        if(mex == A[j]) {
            mex += 1;
        } else {
            break;
        }
    }

    int prefix = 0;
    int left = N;
    for(int m = 0; m < mex; m++) {
        left -= freq[m];
        int l = freq[m]; 
        int r = prefix + freq[m] + left;

        diff[l] += 1;
        diff[r + 1] -= 1;

        prefix += freq[m] - 1;
    }

    diff[0] += 1;
    diff[prefix + left + 1] -= 1;

    int sum = 0;
    for(int k = 0; k <= N; k++) {
        sum += diff[k];
        std::cout << sum << " \n"[k == N];
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
