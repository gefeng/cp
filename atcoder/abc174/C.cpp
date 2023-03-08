#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

using namespace std;

void run_case() {
    int K;
    cin >> K;

    int ans = 1;
    int cur = 7; 
    set<int> seen;
    while(true) {
        if(cur < K) {
            cur = cur * 10 + 7;
            ans += 1;
        } else {
            cur = cur % K;
            if(cur == 0) {
                break;
            }
            if(seen.find(cur) != seen.end()) {
                ans = -1;
                break; 
            }

            seen.insert(cur);
        }
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
