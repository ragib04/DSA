class Solution {
public:

string getsortedstr(int n){
    string s = to_string(n);
    sort(begin(s), end(s));
    return s;
}
    bool reorderedPowerOf2(int n) {
        string s = getsortedstr(n);

        for(int p = 0; p<=29; p++){
            if(s == getsortedstr(pow(2, p))) return true;

            
        }
        return false;
    }
};