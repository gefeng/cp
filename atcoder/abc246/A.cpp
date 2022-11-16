#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

using namespace std;

void run_case() {
    array<pair<int, int>, 3> A;
    map<int, int> m_x;
    map<int, int> m_y;
    for(int i = 0; i < 3; i++) {
        cin >> A[i].first >> A[i].second;
        m_x[A[i].first] += 1;
        m_y[A[i].second] += 1;
    }

    int x = 0;
    int y = 0;
    for(auto& [k, v] : m_x) {
        if(v & 1) {
            x = k;
            break;
        }
    }

    for(auto& [k, v] : m_y) {
        if(v & 1) {
            y = k;
            break;
        }
    }

    cout << x << ' ' << y << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
