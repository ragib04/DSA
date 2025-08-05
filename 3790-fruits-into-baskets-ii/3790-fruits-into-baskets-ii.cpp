class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        int unplacedfruits = 0;
        for(int i = 0; i<n; i++){
            bool placed = false;
            for(int j = 0; j<n; j++){
                if(fruits[i]<=baskets[j]){
                    placed = true;
                    baskets[j] = 0;
                    break;
                }
            }
            if(!placed) unplacedfruits++;
        }
        return unplacedfruits;
    }
};