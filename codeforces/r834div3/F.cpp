#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

using namespace std;

void run_case() {
    int N, P;
    cin >> N >> P;

    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    reverse(A.begin(), A.end());

    int lo = 0;
    int hi = P - 1;
    int ans = -1;
    while(lo <= hi) {
        int mid = (lo + hi) >> 1;

        map<int, int> m;

        int c = mid;
        for(int x : A) {
            int nc = 0;
            if(c + x >= P) {
                m[x] = P - 1;
                nc += 1;
                
                c -= P - x;
                nc += c / P;
                
                m[0] = max(m[0], min(c, P - 1));
            } else {
                m[x] = max(m[x], c + x); 
            }

            c = nc;
        }
        if(c && m.find(c) == m.end()) {
            m[c] = c; 
        }

        bool ok = true;
        int r = -1;
        for(auto& [k, v] : m) {
            if(k - 1 > r) {
                ok = false;
                break;
            } 

            r = max(r, v);
        }
        
        if(ok && r == P - 1) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    cout << ans << '\n';
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
