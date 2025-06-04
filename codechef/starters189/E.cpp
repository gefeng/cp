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
    int N;
    std::cin >> N;

    std::string S;
    std::cin >> S;

    std::vector<int> gap_00;
    std::vector<int> gap_11;
    std::vector<int> gap_01;
    int cnt_one = 0;
    int cnt_q = 0;
    int cnt_seg = 0;
    for(int i = 0; i < N; ) {
        int j = i;
        while(i < N && S[j] == S[i]) {
            i += 1;
        }
        if(S[j] == '?') {
            if(S[j - 1] == '0' && S[i] == '0') {
                gap_00.push_back(i - j);
                cnt_seg += 1;
            } else if(S[j - 1] == '1' && S[i] == '1') {
                gap_11.push_back(i - j);
                cnt_seg += 1;
            } else {
                gap_01.push_back(i - j);
            }
            cnt_q += i - j;
        } else if(S[j] == '1') {
            cnt_one += i - j;
            cnt_seg += 1;
        } else {
            cnt_seg += 1;
        }
    }

    std::sort(gap_00.begin(), gap_00.end());
    std::sort(gap_11.begin(), gap_11.end());
    std::sort(gap_01.begin(), gap_01.end()); 

    int n = gap_11.size();
    int m = gap_00.size();
    int tot = std::accumulate(gap_01.begin(), gap_01.end(), 0);
    std::vector<int> psum(n + 1, 0);
    std::vector<int> psum_2(m + 1, 0);
    for(int i = 0; i < n; i++) {
        psum[i + 1] = psum[i] + gap_11[i];
    }

    for(int i = 0; i < m; i++) {
        psum_2[i + 1] = psum_2[i] + gap_00[i];
    }

    std::vector<int> ans(N + 1, -1);
    for(int k = 0; k <= N; k++) {
        if(k < cnt_one) {
            continue;
        }

        int need = k - cnt_one;
        int q = cnt_q;
        int res = cnt_seg;
        if(need > cnt_q) {
            continue;
        }

        int lo = 0;
        int hi = n - 1;
        int j = -1;
        while(lo <= hi) {
            int mid = (lo + hi) >> 1;
            if(psum[mid + 1] <= need) {
                j = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        
        res -= 2 * (j + 1);
        need -= psum[j + 1];
        q -= psum[j + 1];

        int d = std::min(need, tot);
        need -= d;
        q -= d;
         
        q -= need;
        lo = 0;
        hi = m - 1;
        j = -1;
        while(lo <= hi) {
            int mid = (lo + hi) >> 1;
            if(psum_2[mid + 1] <= q) {
                j = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        res -= 2 * (j + 1);

        ans[k] = res;
    }

    for(int i = 0; i <= N; i++) {
        std::cout << ans[i] << " \n"[i == N];
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
