#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;
using LL = long long;

struct vect {
    LL x, y;
    vect() {
        x = 0;
        y = 0;
    }
    vect(LL x, LL y) : x(x), y(y) {};
    bool operator <(const vect& other) const {
        return x * other.y < other.x * y;
    }
};

void run_case() {
    int N;
    cin >> N;

    vector<pair<vect, vect>> A(N);
    for(int i = 0; i < N; i++) {
        int X, Y;
        cin >> X >> Y;

        A[i].first = {X - 1, Y};
        A[i].second = {X, Y - 1};
    }

    sort(A.begin(), A.end());

    int ans = 1;
    pair<vect, vect> cur = A[0]; 
    for(auto& v : A) {
        if(v.first < cur.second) {
            cur.second = min(v.second, cur.second);
        } else {
            ans += 1;
            cur = v;
        }
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
