#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

const array<int, 4> DR{0, 1, 0, -1};
const array<int, 4> DC{1, 0, -1, 0};

void run_case() {
    int M, N;
    cin >> M >> N;

    int R, C;
    cin >> R >> C;

    R -= 1;
    C -= 1;
    
    int cnt = 0;
    for(int i = 0; i < 4; i++) {
        int nr = R + DR[i];
        int nc = C + DC[i];
        if(nr >= 0 && nc >= 0 && nr < M && nc < N) {
            cnt += 1;
        }
    }

    cout << cnt << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
