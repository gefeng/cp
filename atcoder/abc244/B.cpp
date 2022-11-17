#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

const array<int, 4> DR{1, 0, -1, 0};
const array<int, 4> DC{0, -1, 0, 1};

void run_case() {
    int N;
    cin >> N;

    string T;
    cin >> T;

    int x = 0;
    int y = 0;
    int d = 0; 

    for(char c : T) {
        if(c == 'S') {
            x += DR[d];
            y += DC[d];
        } else {
            d = (d + 1) % 4;
        }
    }

    cout << x << ' ' << y << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
