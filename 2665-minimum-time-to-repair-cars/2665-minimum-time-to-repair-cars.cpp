class Solution {
public:

bool ispossible(long long mid, vector<int> &rank, int cars){
    long long carfixed = 0;

    for(int i = 0; i<rank.size(); i++){
        carfixed += floor(sqrt(mid/rank[i]));
    }
    return carfixed >= cars;
}
    long long repairCars(vector<int>& ranks, int cars) {
        int n = ranks.size();

        long long s = 1;
        int max_R = *max_element(begin(ranks), end(ranks));
        long long e  = 1LL * max_R * cars*cars;
long long res = -1;
        while(s<=e){
            long long mid  = (s+e)/2;   //time

            if(ispossible(mid, ranks, cars)){
                res = mid;
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }
        return res;
    }
};