class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        int unplacedfruits = 0;
        int s = 0;
        while(s<n){
            bool placed = false;
            for(int j = 0; j<n; j++){
                if(fruits[s]<=baskets[j]){
                    placed = true;
                    baskets[j] = 0;
                   
                    break;
                }
            }
            s++;
            if(!placed) unplacedfruits++;
        }
    
        return unplacedfruits;
    }
};