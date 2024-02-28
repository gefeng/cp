#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    /*N - x > A
    x < N - A

    N - x > B
    x < N - B

    3 1 2
    
    4 2 2 a
    5 2 2 a
    6 2 2 b
    7 2 2 a
    8 2 2 a */

    int N, A, B;
    std::cin >> N >> A >> B;

    if(A >= N) {
        std::cout << "Alice" << '\n';
        return;
    }

    if(B >= N - 1) {
        std::cout << "Bob" << '\n';
        return;
    }

    if(B > A) {
        std::cout << "Bob" << '\n';
        return;
    }

    if(A > B) {
        std::cout << "Alice" << '\n';
        return;
    }

    //1 A 1 A 1 A
    int rem = (N - A) % (A + 1);
    std::cout << (rem == 1 ? "Bob" : "Alice") << '\n';

    /*3 2 2 b
    4 2 2 a
    5 2 2 a
    6 2 2 b
    7 2 2 a

    3 1 1 a
    4 1 1 b

    6 2 3
    6 3 3
    6 3 2
    
    1 <= x - [1, B] <= A
    B + 1 <= x <= A + 1*/
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
