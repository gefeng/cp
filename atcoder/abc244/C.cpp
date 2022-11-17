#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

int q(int x) {
    cout << x << endl;
    int res;
    cin >> res;
    return res;
}
void run_case() {
    int N;
    cin >> N;

    vector<bool> seen(2 * N + 2, false);
   
    int cur = 1;
    while(true) {
        while(seen[cur]) {
            cur += 1;
        } 

        int res = q(cur);
        if(res == 0) {
            break;
        }

        seen[res] = true;
        seen[cur] = true;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
