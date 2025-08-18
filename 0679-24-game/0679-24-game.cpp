class Solution {
public:
double eps = 0.001;

bool solve(vector<double> cards){
    if(cards.size() == 1){
        return abs(cards[0] - 24.0)<=eps;
    }
    
    for(int i = 0; i<cards.size(); i++){
        for(int j = 0; j<cards.size(); j++){
            if(i == j) continue;

            vector<double> remaning;
            for(int k = 0; k<cards.size(); k++){
                if(k != i&& k != j)remaning.push_back(cards[k]);
            }
            double a = cards[i], b = cards[j];

            vector<double> possible = {a+b, a-b, b-a, a*b};
            if(abs(b)>0.0) possible.push_back(a/b);

            if(abs(a)>0.0) possible.push_back(b/a);

            for(auto it: possible){
                remaning.push_back(it);
                if(solve(remaning)) return true;
                remaning.pop_back();
            }


        }
    }
    return false;
}
    bool judgePoint24(vector<int>& cards) {
        vector<double> nums;
    
        for(int i = 0; i<cards.size(); i++) nums.push_back(cards[i]);

        return solve(nums);
        
    }
};