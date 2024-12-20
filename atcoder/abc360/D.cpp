#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, T;
    std::cin >> N >> T;
    
    std::string S;
    std::cin >> S;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int> move_left;
    std::vector<int> move_right;
    for(int i = 0; i < N; i++) {
        if(S[i] == '0') {
            move_left.push_back(A[i]);
        } else {
            move_right.push_back(A[i]);
        }
    }
    
    std::sort(move_left.begin(), move_left.end());
    std::sort(move_right.begin(), move_right.end());

    auto bs = [&](int p, int st) {
        int lo = st;
        int hi = move_left.size() - 1;
        int res = -1;
        while(lo <= hi) {
            int mid = (lo + hi) >> 1;
            
            if(p + T >= move_left[mid] - T) {
                res = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return res;
    };

    int64_t ans = 0;
    for(int p : move_right) {
        auto it = std::lower_bound(move_left.begin(), move_left.end(), p);
        if(it == move_left.end()) {
            continue;
        }

        int st = it - move_left.begin();
        int i = bs(p, st);
        if(i != -1) {
            ans += i - st + 1;
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
