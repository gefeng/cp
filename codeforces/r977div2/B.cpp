#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>

void run_case() {
    int N, X;
    std::cin >> N >> X;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int> freq(N, 0);
    for(int i = 0; i < N; i++) {
        if(A[i] < N) {
            freq[A[i]] += 1;
        }
    }

    int mex = 0;
    for(int i = 0; i < N; i++) {
        if(freq[i] == 0) {
            break;
        } 

        mex += 1;
        if(freq[i] > 1 && i + X < N) {
            freq[i + X] += freq[i] - 1;
        }
    }

    std::cout << mex << '\n';
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
