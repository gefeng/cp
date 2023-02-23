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

    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int ans = 0;
    int max_f = 0;
    for(int i = 2; i <= 1000; i++) {
        int cnt = 0;
        for(int x : A) {
            if(x % i == 0) {
                cnt += 1;
            }
        }
        if(cnt > max_f) {
            max_f = cnt;
            ans = i;
        }
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
