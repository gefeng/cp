#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    int N;
    cin >> N;

    vector<int> digits;
    while(N) {
        digits.push_back(N % 10);
        N /= 10;
    }

    int ans = 0;
    int n = digits.size();
    for(int i = 1; i < (1 << n) - 1; i++) {
        vector<int> a;
        vector<int> b;
        
        for(int j = 0; j < n; j++) {
            if(i & (1 << j)) {
                a.push_back(digits[j]);
            } else {
                b.push_back(digits[j]);
            }
        }

        do {
            do {
                if(a[0] != 0 && b[0] != 0) {
                    int x = 0;
                    int y = 0;
                    for(int d : a) {
                        x = x * 10 + d;
                    }
                    for(int d : b) {
                        y = y * 10 + d;
                    }
                    ans = max(ans, x * y);
                }
            } while(next_permutation(b.begin(), b.end()));
        } while(next_permutation(a.begin(), a.end()));
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
