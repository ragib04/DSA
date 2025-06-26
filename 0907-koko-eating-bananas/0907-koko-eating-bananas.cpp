/*class Solution {
public:
    
    bool canEatAll(vector<int>& piles, int givenHour, int h) {
        int actualHour = 0;
        
        for(int &x : piles) {
            actualHour += x/givenHour;
            
            if(x%givenHour != 0)
                actualHour++;
            
        }
        
        return actualHour <= h;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        
        int l = 1, r = *max_element(begin(piles), end(piles));
        
        while(l < r) {
            int mid = l + (r-l)/2;
            
            if(canEatAll(piles, mid, h)) {
                r = mid;
            } else {
                l = mid+1;
            }
            
        }
        
        return l;
    }
};


*/





class Solution
{
public:
    int minEatingSpeed(vector<int>& piles, int h)
    {
        int l=1,r=1e9;
        while(l<r)
        {
            int cur=0;
            int mid=(r-l)/2+l;
            if(mid==0)
            {
                break;
            }
            for(int p:piles)
            {
                cur+=(p+mid-1)/mid;
                if(cur>h)
                {
                    break;
                }
            }
            if(cur<=h)
            {
                r=mid;
            }
            else
            {
                l=mid+1;
            }
        }
        return l;
    }
};
