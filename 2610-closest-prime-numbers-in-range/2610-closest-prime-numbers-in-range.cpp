class Solution {
public:
vector<bool> sive(int right){
    vector<bool> isprime(right+1, true);
    isprime[0] = false;
    isprime[1] = false;

    for(int i = 2; i<=right; i++){
        if(isprime[i] == true){
            for(int j = 2*i; j<=right; j+=i){
                isprime[j] = false;
            }
        }
    }
    return isprime;
}
    vector<int> closestPrimes(int left, int right) {
        vector<bool> isprime = sive(right);

        vector<int> primes;
        for(int num = left; num<= right; num++){
            if(isprime[num] == true){
                if(!primes.empty() && num - primes.back() <= 2) return {primes.back(), num};
                primes.push_back(num);
            }
        }
        int mindiff = INT_MAX;
        vector<int> result = {-1, -1};
        for(int i = 1; i<primes.size(); i++){
            int diff = primes[i]-primes[i-1];
            if(diff<mindiff){
                mindiff = diff;
                result = {primes[i-1], primes[i]};
            }
        }
        return result;
    }
};