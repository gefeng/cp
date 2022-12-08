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

    vector<int> cnt(N + 1, 0);
    for(int i = 0; i < 4 * N - 1; i++) {
        int X;
        cin >> X;
        cnt[X] += 1;
    }
    
    for(int i = 1; i <= N; i++) {
        if(cnt[i] == 3) {
            cout << i << '\n';
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
