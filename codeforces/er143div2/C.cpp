#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;
using LL = long long;

int bs(vector<LL>& psum, int N, int st, LL t) {
    int lo = st;
    int hi = N - 1;
    int ans = st - 1;
    while(lo <= hi) {
        int mid = (lo + hi) >> 1;

        LL sum = psum[mid + 1] - psum[st];
        if(sum <= t) {
            ans = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    return ans;
}

void run_case() {
    int N;
    cin >> N;
    
    vector<int> A(N);
    vector<int> B(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<LL> psum(N + 1, 0LL);
    for(int i = 0; i < N; i++) {
        cin >> B[i];
        psum[i + 1] = psum[i] + B[i];
    }

    vector<LL> cnt_full(N + 1, 0LL);
    vector<LL> cnt_left(N, 0LL);
    
    for(int i = 0; i < N; i++) {
        int j = bs(psum, N, i, A[i]); // less or equal
        
        // from i to j ppl can have a full drink
        cnt_full[i] += 1;
        cnt_full[j + 1] -= 1;
        
        LL sum = psum[j + 1] - psum[i];
        if(A[i] > sum && j + 1 < N) {
            cnt_left[j + 1] += A[i] - sum; 
        }
    }

    int rolling = 0;
    for(int i = 0; i < N; i++) {
        rolling += cnt_full[i];
       
        LL res = 1LL * rolling * B[i] + cnt_left[i];
        cout << res << " \n"[i == N - 1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    while(T--) {
        run_case();
    }
}
