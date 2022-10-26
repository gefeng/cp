#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;
using LL = long long;

void run_case() {
    int N;
    cin >> N;

    vector<vector<pair<int, int>>> A(N);
    for(int i = 0; i < N; i++) {
        int M;
        cin >> M;

        A[i].resize(M);
        for(int j = 0; j < M; j++) {
            cin >> A[i][j].first >> A[i][j].second;
        }
    }

    unordered_map<int, int> max_e;
    max_e.reserve((unsigned int)2e5);

    for(auto& p : A) {
        for(auto& t : p) {
            if(max_e.find(t.first) == max_e.end()) {
                max_e[t.first] = t.second;
            } else {
                max_e[t.first] = max(max_e[t.first], t.second);
            }
        }
    }

    unordered_map<int, LL> cnt_max_e;
    for(auto& p : A) {
        for(auto& t : p) {
            if(max_e[t.first] == t.second) {
                cnt_max_e[t.first]++;
            }
        }
    }

    LL ans = 0;
    for(auto& p : A) {
        bool change = false;
        for(auto& t : p) {
            if(max_e[t.first] == t.second && cnt_max_e[t.first] == 1)  {
                change = true;
            }
        } 
        if(change) {
            ans++;
        }
    }

    cout << (ans < N ? ans + 1 : ans) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
