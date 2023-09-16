#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

void run_case() {
    std::string S;
    std::cin >> S;

    std::map<std::string, int> m = {
        {"tourist", 3858}, {"ksun48", 3679},
        {"Benq", 3658},
        {"Um_nik", 3648},
        {"apiad", 3638},
        {"Stonefeang", 3630},
        {"ecnerwala", 3613},
        {"mnbvmar", 3555},
        {"newbiedmy", 3516},
        {"semiexp", 3481}};

    std::cout << m[S] << '\n';
}
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
