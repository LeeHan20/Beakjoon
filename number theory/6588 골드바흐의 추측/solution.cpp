#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> sieve(int max) {
    vector<bool> is_prime(max + 1, true);
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i <= sqrt(max); ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= max; j += i) {
                is_prime[j] = false;
            }
        }
    }

    vector<int> primes;
    for (int i = 2; i <= max; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }
    return primes;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    const int MAX = 1000000;
    vector<int> primes = sieve(MAX);

    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;

        bool found = false;
        for (int prime : primes) {
            if (prime > n / 2) break;
            if (binary_search(primes.begin(), primes.end(), n - prime)) {
                cout << n << " = " << prime << " + " << n - prime << '\n';
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Goldbach's conjecture is wrong.\n";
        }
    }

    return 0;
}
