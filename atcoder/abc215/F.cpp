#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

using namespace std;

const int INF = (int)1e9;

void run_case() {
    int N;
    cin >> N;

    //d <= min(xi - xj, yi - yj)
    //d <= xi - xj
    //d <= yi - yj

    vector<pair<int, int>> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i].first >> A[i].second;
    }

    sort(A.begin(), A.end());

    int lo = 0;
    int hi = (int)1e9;
    int ans = 0;
    while(lo <= hi) {
        int mid = (lo + hi) >> 1;
        
        bool ok = false;
        int min_y = INF;
        int max_y = -INF;
        for(int l = 0, r = 0; r < N; r++) {
            while(l < r && A[r].first - A[l].first >= mid) {
                min_y = min(min_y, A[l].second);
                max_y = max(max_y, A[l].second);
                l += 1;
            } 

            if(l != 0 && (abs(min_y - A[r].second) >= mid || abs(max_y - A[r].second) >= mid)) {
                ok = true;
                break;
            }
        }

        if(ok) {
            ans = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
