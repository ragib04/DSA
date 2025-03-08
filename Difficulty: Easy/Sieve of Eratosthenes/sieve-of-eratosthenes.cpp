//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends

//User function Template for C++
class Solution
{
public:
    vector<int> sieveOfEratosthenes(int N)
    {
        // Write Your Code here
        vector<bool> isprime(N+1, true);
        vector<int> ans;
        isprime[0] = isprime[1] = false;
        for(int i = 2; i<=N; i++){
           if(isprime[i] == true){
              
               for(int j = i*2; j <=N; j+=i){
                   isprime[j] = false;
               }
           }
        }
        for(int i =2; i<=N; i++){
            if(isprime[i] == true){
                ans.push_back(i);
            }
        }
      return ans;
        
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        Solution ob;
        vector<int> primes  = ob.sieveOfEratosthenes(N);
        for(auto prime : primes) {
            cout<< prime <<" ";
        }
        cout<<endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends