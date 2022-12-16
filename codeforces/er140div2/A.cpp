#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

bool is_codiag(pair<int, int> a, pair<int, int> b, pair<int, int> c) {
    int x1 = b.first - a.first;
    int y1 = b.second - a.second;
    int x2 = c.first - a.first;
    int y2 = c.second - a.second;
    
    return x1 * x2 + y1 * y2 == 0;
}

void run_case() {
    vector<pair<int, int>> A(3);

    for(int i = 0; i < 3; i++) {
        cin >> A[i].first >> A[i].second;
    }

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            for(int k = 0; k < 3; k++) {
                if(i != j && j != k && i != k) {
                    if(is_codiag(A[i], A[j], {A[i].first, A[k].second}) && is_codiag(A[k], A[j], {A[i].first, A[k].second})) {
                        cout << "NO" << '\n';
                        return;
                    }
                }
            }
        }
    }
    
    cout << "YES" << '\n';
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
