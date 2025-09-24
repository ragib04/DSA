class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        // unordered_map<long long, int> mp;
        // string ans = "";
        // if ((numerator < 0) ^ (denominator < 0)) ans += "-";
       

        // long long n = llabs((long long)numerator);
        // long long d = llabs((long long)denominator);
        // long long q = numerator/denominator;
        // long long r = numerator%denominator;

        // ans += to_string(q);
        // if(r == 0) return ans;
        // else{
        //     ans += '.';

        //     while(r != 0){
        //         if(mp.find(r) != mp.end()){
                    
        //             ans.insert(mp[r], "(");
        //             ans += ")";
        //             break;
        //         }
        //         else{
        //             mp[r] = ans.size();
        //         r *= 10;
        //         q = r/denominator;
        //         r = r%denominator;

        //         ans += to_string(q);
        //         }
        //     }
        // }
        
        // return ans;



        if (numerator == 0) return "0";

        string ans;

        // neg Handle 
        if ((numerator < 0) ^ (denominator < 0)) ans += "-";

       
        long long n = llabs((long long)numerator);
        long long d = llabs((long long)denominator);

    
        long long q = n / d;
        ans += to_string(q);

        long long r = n % d;
        if (r == 0) return ans;  

        ans += ".";

        unordered_map<long long, int> mp;  // remainder → position

        while (r != 0) {
            if (mp.find(r) != mp.end()) {
                ans.insert(mp[r], "(");
                ans += ")";
                break;
            }

            mp[r] = ans.size();
            r *= 10;
            ans += to_string(r / d);
            r %= d;
        }

        return ans;
    }
};