#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

using namespace std;
using LL = long long;

int gcd(int a, int b) {
    if(a == 0) {
        return b;
    }
    return gcd(b % a, a);
}
void run_case() {
    int N; 
    cin >> N;

    vector<pair<int, int>> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i].first >> A[i].second;
    }

    int ans = 0;
    set<pair<int, int>> s;
    for(int i = 0; i < N; i++) {
        for(int j = i + 1; j < N; j++) {
            int dx = A[j].first - A[i].first;
            int dy = A[j].second - A[i].second;
            int g = gcd(dx, dy);
            dx /= g;
            dy /= g;
            if(s.find({dx, dy}) == s.end()) {
                ans += 2;
                s.insert({dx, dy});
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
