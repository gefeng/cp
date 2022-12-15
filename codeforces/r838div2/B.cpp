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

    vector<pair<int, int>> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i].first;
        A[i].second = i;
    }

    sort(A.begin(), A.end());
    
    vector<pair<int, LL>> ans;
    LL cur = 1LL;
    for(int i = 0; i < N; i++) {
        if(A[i].first < cur) {
            ans.emplace_back(A[i].second + 1, cur - A[i].first);
        } else {
            while(cur < A[i].first) {
                cur *= 2LL;
            }
            if(A[i].first < cur) {
                ans.emplace_back(A[i].second + 1, cur - A[i].first);
            }
        }
    }

    int sz = ans.size();
    cout << sz << '\n';
    for(int i = 0; i < sz; i++) {
        cout << ans[i].first << ' ' << ans[i].second << '\n';
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
