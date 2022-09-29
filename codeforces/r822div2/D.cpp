#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;
using LL = long long;

const LL INF = 1e18;

void run_case() {
    int N, K;
    cin >> N >> K;

    K--;

    vector<LL> A(N, 0LL);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<pair<LL, LL>> l_groups;
    vector<pair<LL, LL>> r_groups;

    LL sum = 0LL;
    LL min_v = INF;
    for(int i = K - 1; i >= 0; i--) {
        sum += A[i];
        min_v = min(min_v, sum);
        if(sum >= 0 || i == 0) {
            l_groups.emplace_back(sum, -min_v);
            sum = 0LL;
            min_v = INF;
        }
    }

    for(int i = K + 1; i < N; i++) {
        sum += A[i];
        min_v = min(min_v, sum);
        if(sum >= 0 || i == N - 1) {
            r_groups.emplace_back(sum, -min_v);
            sum = 0LL;
            min_v = INF;
        }
    }

    int l = 0;
    int r = 0;
    int m = l_groups.size();
    int n = r_groups.size();
    LL cur = A[K];
    while(l < m && r < n) {
        if(cur < l_groups[l].second && cur < r_groups[r].second) {
            break;
        }
        
        if(cur >= l_groups[l].second) {
            cur += l_groups[l++].first;
        } else {
            cur += r_groups[r++].first;
        }
    }

    cout << ((l == m || r == n) ? "YES" : "NO") << '\n';
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
