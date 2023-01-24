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
    int N, M;
    cin >> N >> M;

    vector<pair<int, int>> A(M);
    for(int i = 0; i < M; i++) {
        cin >> A[i].first >> A[i].second;
    }
    
    map<int, vector<int>> m;
    for(auto& p : A) {
        m[p.first].push_back(p.second);
    }

    set<int> s;
    s.insert(N);

    for(auto& [_, v] : m) {
        vector<int> add;
        for(int x : v) {
            if((x - 1 >= 0 && s.find(x - 1) != s.end()) || (x + 1 <= 2 * N && s.find(x + 1) != s.end())) {
                add.push_back(x);
            }
        }

        for(int x : v) {
            s.erase(x);
        }

        for(int x : add) {
            s.insert(x);
        }
    }

    cout << s.size() << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
