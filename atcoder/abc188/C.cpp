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

    int n = 1 << N;
    vector<pair<int, int>> A(n);
    for(int i = 0; i < n; i++) {
        cin >> A[i].first;
        A[i].second = i + 1;
    }

    vector<pair<int,int>> cur(A);
    while(cur.size() != 2) {
        vector<pair<int, int>> nxt;
        
        int sz = cur.size();
        for(int i = 0; i < sz; i += 2) {
            if(cur[i].first > cur[i + 1].first) {
                nxt.emplace_back(cur[i].first, cur[i].second);
            } else {
                nxt.emplace_back(cur[i + 1].first, cur[i + 1].second);
            }
        }
        
        swap(nxt, cur);
    }

    if(cur[0].first < cur[1].first) {
        cout << cur[0].second << '\n';
    } else {
        cout << cur[1].second << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
