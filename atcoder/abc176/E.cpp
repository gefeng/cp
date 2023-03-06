#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

void run_case() {
    int H, W, M;
    cin >> H >> W >> M;

    vector<pair<int, int>> A(M);
    for(int i = 0; i < M; i++) {
        cin >> A[i].first >> A[i].second;
        A[i].first -= 1;
        A[i].second -= 1;
    }
    
    map<int, int> mr;
    map<int, int> mc;
    int max_r = 0;
    int max_c = 0;

    for(auto& p : A) {
        mr[p.first] += 1;
        max_r = max(max_r, mr[p.first]);
    }

    for(auto& p : A) {
        mc[p.second] += 1; 
        max_c = max(max_c, mc[p.second]);
    }

    set<int> sc;
    for(auto [k, v] : mc) {
        if(v == max_c) {
            sc.insert(k);
        }
    }

    map<int, vector<int>> m;
    for(auto& p : A) {
        m[p.first].push_back(p.second);
    }

    int ans = 0;
    for(auto& [k, v] : m) {
        int sz = v.size();
        sort(v.begin(), v.end());

        ans = max(ans, sz + max_c - 1);

        if(*sc.begin() < v[0]) {
            ans = max(ans, sz + max_c);
        } else {
            for(int i = 0; i < sz; i++) {
                auto it = sc.upper_bound(v[i]);
                if(it != sc.end() && (i == sz - 1 || v[i + 1] > *it)) {
                    ans = max(ans, sz + max_c);
                }
            }
        }
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
