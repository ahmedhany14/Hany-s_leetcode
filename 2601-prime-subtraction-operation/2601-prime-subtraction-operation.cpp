class Solution {
public:
# define ll long long
    vector<int> primes;

    void sieve() {
        bitset<1150> is_prime;
        vector<ll> spf(1150);

        is_prime.set();
        is_prime[0] = is_prime[1] = 0;
        for (ll i = 2; i <= 1100 / i; i++)if (is_prime[i]) for (ll j = i * i; j < 1100; j += i) is_prime[j] = 0;
        for (int i = 1; i <= 1100; i++) spf[i] = i;
        spf[1] = 1e9;
        for (int i = 2; i <= 1100; i += 2) spf[i] = 2;
        for (int i = 3; i * i <= 1100; i++)
            if (spf[i] == i)
                for (int j = i * i; j <= 1100; j += i)
                    if (spf[j] == j)
                        spf[j] = i;
        for (int i = 1; i <= 1100; ++i) if (is_prime[i]) primes.push_back(i);
    }

    bool primeSubOperation(vector<int> &a) {
        sieve();
        int n = primes.size();
        for (int i = n - 1; ~i; --i) {
            if (a[0] > primes[i]) {
                a[0] -= primes[i];
                break;
            }
        }
        for (int i = 1; i < a.size(); ++i) {
            int l = 0, r = n - 1, best = -1, last = a[i - 1];
            while (l <= r) {
                int mid = (l + r) / 2;
                if (a[i] - primes[mid] > 0 and a[i] - primes[mid] > last) best = mid, l = mid + 1;
                else r = mid - 1;
            }
            if (~best) a[i] -= primes[best];
        }
        bool answer = true;
        for (int i = 0; i < a.size() - 1; ++i) if (a[i + 1] <= a[i]) answer = false;
        return answer;
    }
};
