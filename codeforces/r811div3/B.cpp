#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

void run_case() {
    int N;
    cin >> N;
    
    vector<int> A(N, 0);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int lo = 0;
    int hi = N - 1; 
    int ans = 0;
    while(lo <= hi) {
        int mid = lo + hi >> 1;
        
        unordered_set<int> seen;
        bool unique = true;
        for(int i = mid; i < N; i++) {
            if(seen.count(A[i])) {
                unique = false;
                break;
            }
            seen.insert(A[i]);
        }

        if(unique) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);        // de-sync with c stream
    cin.tie(0);                         // disable flushing of std::cout
    
    int t = 0;
    cin >> t;
    while(t--) {
        run_case();
    }
}
