class Solution {
public:
    string largestGoodInteger(string num) {
        char maxchar = ' ';
        for(int i = 2; i<num.length(); i++){
            if(num[i] == num[i-1] && num[i] == num[i-2]){
                
                    maxchar = max(maxchar,num[i]);
                }
            
        }
        if(maxchar == ' ') return "";
        return string(3, maxchar);
    }
};