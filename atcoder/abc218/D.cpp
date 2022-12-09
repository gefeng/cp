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
    int N;
    cin >> N;

    vector<pair<int, int>> A(N);
    map<int, set<int>> m;

    for(int i = 0; i < N; i++) {
        cin >> A[i].first >> A[i].second;
        m[A[i].first].insert(A[i].second);
    }

    int ans = 0;
    for(int i = 0; i < N; i++) {
        int x1 = A[i].first;
        int y1 = A[i].second;
        for(int j = i + 1; j < N; j++) {
            int x2 = A[j].first;
            int y2 = A[j].second;

            if(x1 != x2 && y1 != y2) {
                if(m[x1].find(y2) != m[x1].end() && m[x2].find(y1) != m[x2].end()) {
                    ans += 1;
                }
            }
        }
    }
    
    cout << ans / 2 << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
