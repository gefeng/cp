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
        cin >> A[i].first >> A[i].second;
    }

    sort(A.begin(), A.end());

    vector<pair<int, int>> ans;
    ans.reserve(N);

    for(int i = 0; i < N; i++) {
        if(!ans.empty() && ans.back().second >= A[i].first) {
            ans.back().second = max(ans.back().second, A[i].second);
        } else {
            ans.emplace_back(A[i].first, A[i].second);
        }
    }

    for(auto& p : ans) {
        cout << p.first << ' ' << p.second << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
