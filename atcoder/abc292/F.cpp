#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

const double EPS = 1e-9;

void run_case() {
    int A, B;
    cin >> A >> B;

    if(A > B) {
        swap(A, B);
    }

    cout << setprecision(20);

    if(B >= A * 2 / sqrt(3)) {
        cout << A * 2 / sqrt(3) << '\n';
        return;
    }

    double pi = acos(-1);
    double lo = 0.0;
    double hi = pi / 6.0; 
    double theta = 0.0;
    while(hi - lo > EPS) {
        double mid = (hi + lo) / 2.0;
        
        if(B * cos(mid) - A * cos(pi / 6.0 - mid) >= EPS) {
            theta = mid;
            lo = mid;
        } else {
            hi = mid;
        }
    }

    cout << A / cos(theta) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
