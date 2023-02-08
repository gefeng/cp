#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    int A, B, W;
    cin >> A >> B >> W;
    
    W *= 1000;

    double l = (double)W / B;
    double r = (double)W / A;
    
    int ll = ceil(l);
    int rr = floor(r);
    if(rr < ll) {
        cout << "UNSATISFIABLE" << '\n';
    } else {
        cout << ll << ' ' << rr << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
