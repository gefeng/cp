#include <vector>

std::vector<bool> is_prime;
std::vector<int> primes;

void sieve(int max_v) {
    is_prime.resize(max_v + 1, true);
    
    is_prime[0] = false;
    is_prime[1] = false;

    for(int i = 2; i <= max_v; i++) {
        if(is_prime[i]) {
            primes.push_back(i);

            for(int j = i + i; j <= max_v; j += i) {
                is_prime[i] = false;
            }
        }
    }
}

std::vector<int> min_prime;  // minimum prime factors for each i, normally i can be maximum 1e7

void linear_sieve(int max_v) {
    is_prime.resize(max_v + 1, true); 
    min_prime.resize(max_v + 1, 0);

    is_prime[0] = false;
    is_prime[1] = false;

    for(int i = 2; i <= max_v; i++) {
        if(is_prime[i]) {
            primes.push_back(i);
            min_prime[i] = i;
        }

        for(int j = 0; j < primes.size() && i * primes[j] <= max_v; j++) {
            is_prime[i * primes[j]] = false;
            min_prime[i * primes[j]] = primes[j];

            if(i % primes[j] == 0) {
                break;
            }
        }
    }
}
