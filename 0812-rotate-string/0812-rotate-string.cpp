/*
class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size();
        int m = goal.size();
        if(n != m) return false;

        string concat = s+s;
        return concat.find(goal) != string::npos;
       
    }
};
*/

class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size();
        int m = goal.size();
        if(n != m) return false;
        for(int i = 0; i<n; i++){
            rotate(s.begin(),s.begin()+1 ,s.end());
            if(s == goal) return true;
        }
        return false;
    }
};