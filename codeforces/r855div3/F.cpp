#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

using namespace std;
using LL = long long;

const int MASK_ALL = (1 << 26) - 1;

void run_case() {
    int N;
    cin >> N;

    vector<string> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    map<int, array<int, 26>> m;
    LL ans = 0LL;
    for(string s : A) {
        int mask = 0;

        array<bool, 26> seen{false};
        for(char c : s) {
            mask ^= (1 << (c - 'a'));
            seen[c - 'a'] = true;
        }

        for(int i = 0; i < 26; i++) {
            if(seen[i]) {
                continue;
            }

            int t_mask = mask ^ MASK_ALL;
            t_mask ^= 1 << i;

            if(m.find(t_mask) != m.end()) {
                ans += m[t_mask][i];
            }
        }

        for(int i = 0; i < 26; i++) {
            if(!seen[i]) {
                m[mask][i] += 1;
            }
        }
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    run_case();
}
