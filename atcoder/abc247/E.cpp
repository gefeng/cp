#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;
using LL = long long;

void run_case() {
    int N, X, Y;
    cin >> N >> X >> Y;

    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    LL ans = 0LL;
    for(int i = 0; i < N; ) {
        int j = i;
        while(i < N && A[i] <= X && A[i] >= Y) {
            i++;
        }

        if(i == j) {
            i += 1;
            continue;
        }

        int cnt_x = 0;
        int cnt_y = 0;
        for(int l = j, r = j; l < i; l++) {
            while(r < i && (cnt_x == 0 || cnt_y == 0)) {
                if(A[r] == X) {
                    cnt_x += 1;
                }
                if(A[r] == Y) {
                    cnt_y += 1;
                }

                r += 1;
            }

            if(cnt_x && cnt_y) {
                ans += i - r + 1;
            }

            if(A[l] == X) {
                cnt_x -= 1;
            } 
            if(A[l] == Y) {
                cnt_y -= 1;
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
