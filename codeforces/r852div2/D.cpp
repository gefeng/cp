#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;
using LL = long long;

void run_case() {
    int N;
    cin >> N;
 
    vector<int> A(N);
    vector<int> posA(N + 1, 0);
    int p1 = 0;
    int p2 = 0;
    for(int i = 0; i < N; i++) {
        cin >> A[i];
        if(A[i] == 1) {
            p1 = i;
        }
        posA[A[i]] = i;
    }
    vector<int> B(N);
    vector<int> posB(N + 1, 0);
    for(int i = 0; i < N; i++) {
        cin >> B[i];
        if(B[i] == 1) {
            p2 = i;
        }
        posB[B[i]] = i;
    }
 
    LL ans = 0LL;
    int l = 0;
    int r = min(p1 - 1, p2 - 1);
    ans += 1LL * (r - l + 2) * (r - l + 1) / 2LL;;
    
    l = max(p1 + 1, p2 + 1);
    r = N - 1;
    ans += 1LL * (r - l + 2) * (r - l + 1) / 2LL;
 
    l = min(p1, p2) + 1;
    r = max(p1, p2) - 1;
    ans += 1LL * (r - l + 2) * (r - l + 1) / 2LL;
 
    int l1 = p1, r1 = p1;
    int l2 = p2, r2 = p2;
    int mex = 2;
    while(mex <= N) {
        int pos1 = posA[mex];
        int pos2 = posB[mex];
 
        l = min(l1, l2);
        r = max(r1, r2);
        
        if((pos1 >= l && pos1 <= r) || (pos2 >= l && pos2 <= r)) {
            // not ok
            l1 = min(l1, pos1);
            r1 = max(r1, pos1);
            l2 = min(l2, pos2);
            r2 = max(r2, pos2);
        } else {
            int can_l1 = pos1 < l1 ? pos1 + 1 : 0;
            int can_r1 = pos1 < l1 ? N - 1 : pos1 - 1;
 
            int can_l2 = pos2 < l2 ? pos2 + 1 : 0;
            int can_r2 = pos2 < l2 ? N - 1 : pos2 - 1;
            
            int can_l = max(can_l1, can_l2);
            int can_r = min(can_r1, can_r2);
 
            ans += 1LL * (l - can_l + 1) * (can_r - r + 1);
 
            l1 = min(l1, pos1);
            r1 = max(r1, pos1);
            l2 = min(l2, pos2);
            r2 = max(r2, pos2);
        }
 
        mex += 1;
    }
 
    cout << ans + 1 << '\n';
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
