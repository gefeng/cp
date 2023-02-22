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

void run_case() {
    int N, T;
    cin >> N >> T;

    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    LL ans = 0LL;

    int n_2 = N / 2;
    set<LL> s;
    for(int i = 0; i < (1 << n_2); i++) {
        LL sum = 0LL;
        for(int j = 0; j < n_2; j++) {
            if(i & (1 << j)) {
                sum += A[j]; 
            }
        }

        s.insert(sum);

        if(sum <= T) {
            ans = max(ans, sum);
        }
    }

    int m_2 = N - n_2;
    for(int i = 0; i < (1 << m_2); i++) {
        LL sum = 0LL;
        for(int j = 0; j < m_2; j++) {
            if(i & (1 << j)) {
                sum += A[j + n_2];
            }
        }

        if(sum <= T) {
            ans = max(ans, sum);

            if(T - sum > 0) {
                auto it = s.lower_bound(T - sum);

                if(it != s.end() && *it == T - sum) {
                    ans = T;
                } else {
                    if(it != s.begin()) {
                        it--;
                        ans = max(ans, *it + sum);
                    }
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
