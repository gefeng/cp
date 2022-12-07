#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

bool is_colinear(pair<int, int>& a, pair<int, int>& b, pair<int, int>& c) {
    int x1 = b.first - a.first;
    int y1 = b.second - a.second;
    int x2 = c.first - a.first;
    int y2 = c.second - a.second;

    return x1 * y2 - x2 * y1 == 0;
}

void run_case() {
    int N;
    cin >> N;

    vector<pair<int, int>> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i].first >> A[i].second;
    }

    int ans = 0;
    for(int i = 0; i < N; i++) {
        for(int j = i + 1; j < N; j++) {
            for(int k = j + 1; k < N; k++) {
                if(!is_colinear(A[i], A[j], A[k])) {
                    ans += 1; 
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
