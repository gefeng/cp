#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    int N, D;
    cin >> N >> D;
 
    vector<pair<int, int>> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i].first >> A[i].second;
        A[i].first = max(1, A[i].first - D / 2);
        A[i].second = min((int)1e9, A[i].second + D / 2);
    }
    
    auto cmp = [](const auto& a, const auto& b) {
        return a.second < b.second;
    };
 
    sort(A.begin(), A.end(), cmp);
 
    int ans = 0;
    for(int i = 0; i < N; ) {
        int j = i;
        while(i < N && A[i].first <= A[j].second) {
            i += 1;
        }
        ans += 1;
    } 

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
