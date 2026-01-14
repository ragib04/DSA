class Solution {
public:
    string reverseWords(string s) {
        //step 1
        reverse(s.begin(), s.end());
        int i = 0, r= 0, l = 0;
        int n = s.size();
        while(i<n){
            while(i<n && s[i] == ' '){
                i++;
            }
            if(i == n) break;
            while(i<n && s[i] != ' '){
                s[r++] = s[i++];
                
            }
            reverse(s.begin()+l, s.begin()+r);
            s[r++] = ' ';
            
            l = r;
            i++;
        }
        s.resize(r-1);
        return s;
    }
};