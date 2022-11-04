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

    cout << 1 << '\n';
    vector<int> cur(1, 1);
    
    for(int i = 2; i <= N; i++) {
        vector<int> nxt(i, 0); 
        nxt[0] = 1;
        nxt[i - 1] = 1;

        for(int j = 1; j < i - 1; j++) {
            nxt[j] = cur[j - 1] + cur[j];
        }

        for(int j = 0; j < i; j++) {
            cout << nxt[j] << " \n"[j == i - 1];
        }

        swap(nxt, cur);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
