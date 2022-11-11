#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

using namespace std;

int gcd(int a, int b) {
    if(a == 0) {
        return b;
    }
    return gcd(b % a, a);
}

void run_case() {
    int N;
    cin >> N;

    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int t = A[0];
    for(int i = 1; i < N; i++) {
        t = gcd(t, A[i]);
    }

    int ans = 0;
    for(int x : A) {
        int y = x / t;
        while(y != 1) {
            if(y % 3 == 0) {
                y /= 3;
                ans += 1;
                continue;
            }
            if(y % 2 == 0) {
                y /= 2;
                ans += 1;
                continue;
            }

            break;
        }

        if(y != 1) {
            cout << -1 << '\n';;
            return;
        }
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
