#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>

using namespace std;

void run_case() {
    int N;
    cin >> N;

    vector<pair<int, int>> B(N / 2);
    for(int i = 0; i < N / 2; i++) {
        cin >> B[i].first;
        B[i].second = i;
    }

    sort(B.begin(), B.end(), greater<pair<int, int>>());

    vector<int> match(N + 1, 0);
    for(auto& x : B) {
        match[x.first] = x.first;
    }
    
    vector<int> v;
    v.reserve(N / 2);
    for(int i = 1; i <= N; i++) {
        if(match[i] == 0) {
            v.push_back(i);
        }
    }

    auto cmp = [](const auto& a, const auto& b) {
        return a.first < b.first;
    };

    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> q(cmp);
    for(int i = v.size() - 1, j = 0; i >= 0; i--) {
        while(j < N / 2 && B[j].first > v[i]) {
            q.emplace(B[j].second, B[j].first);
            j += 1;
        }

        if(q.empty()) {
            cout << -1 << '\n';
            return;
        }

        pair<int, int> best = q.top();
        q.pop();

        match[best.second] = v[i];
    }
    
    vector<int> ans(N, 0);
    for(auto& x : B) {
        int v = x.first;
        int p = x.second;

        ans[p * 2] = match[v];
        ans[p * 2 + 1] = v;
    }

    for(int i = 0; i < N; i++) {
        cout << ans[i] << " \n"[i == N - 1];
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
