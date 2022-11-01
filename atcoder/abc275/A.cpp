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
    
    int ans = 0;
    int max_h = 0;
    for(int i = 0; i < N; i++) {
        int H;
        cin >> H;
        if(H > max_h) {
            max_h = H;
            ans = i;
        }
    }

    cout << ans + 1 << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
