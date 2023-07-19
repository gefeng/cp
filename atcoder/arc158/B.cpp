#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

const double INF = 2e12;

void run_case() {
    int N;
    cin >> N;

    vector<int> pos;
    vector<int> neg;
    for(int i = 0; i < N; i++) {
        int X;
        cin >> X;

        if(X > 0) {
            pos.push_back(X);
        } else {
            neg.push_back(X);
        }
    }

    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end(), greater<int>());

    int n = pos.size();
    int m = neg.size();

    vector<int> v;
    if(n < 6) {
        for(int i = 0; i < n; i++) {
            v.push_back(pos[i]);
        } 
    } else {
        for(int i = 0; i < 3; i++) {
            v.push_back(pos[i]);
        }
        for(int i = n - 3; i < n; i++) {
            v.push_back(pos[i]);
        }
    }

    if(m < 6) {
        for(int i = 0; i < m; i++) {
            v.push_back(neg[i]);
        } 
    } else {
        for(int i = 0; i < 3; i++) {
            v.push_back(neg[i]);
        }
        for(int i = m - 3; i < m; i++) {
            v.push_back(neg[i]);
        }
    }

    int sz = v.size();
    double max_v = -INF;
    double min_v = INF;
    for(int i = 0; i < (1 << sz); i++) {
        if(__builtin_popcount(i) == 3) {
            vector<int> t;
            for(int j = 0; j < sz; j++) {
                if(i & (1 << j)) {
                    t.push_back(v[j]);
                }
            }

            do {
                double ratio = ((double)t[0] + t[1] + t[2]) / ((double)t[0] * t[1] * t[2]);
                max_v = max(max_v, ratio);
                min_v = min(min_v, ratio);

            } while(next_permutation(t.begin(), t.end()));
        } 
    }

    cout << setprecision(30) << min_v << '\n' << max_v << '\n'; 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
