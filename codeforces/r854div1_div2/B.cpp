#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    int N;
    cin >> N;

    vector<pair<int, int>> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i].first;
        A[i].second = i;
    }

    if(N == 1) {
        cout << 0 << '\n';
        return;
    }
    
    sort(A.begin(), A.end());

    if(A[0].first == A[N - 1].first) {
        cout << 0 << '\n';
        return;
    }
    
    if(A[0].first == 1) {
        cout << -1 << '\n';
        return;
    }

    vector<pair<int, int>> ans;
    while(true) {
        bool end = true;
        for(int i = N - 1; i > 0; i--) {
            if(A[i].first != A[0].first) {
                A[i].first = (A[i].first + A[0].first - 1) / A[0].first;
                ans.emplace_back(A[i].second, A[0].second);
                end = false;
            }
        } 

        if(end) {
            break;
        }

        sort(A.begin(), A.end());
    }

    int sz = ans.size();
    cout << sz << '\n';
    for(int i = 0; i < sz; i++) {
        cout << ans[i].first + 1 << ' ' << ans[i].second + 1 << '\n';
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
