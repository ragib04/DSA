class FindSumPairs {
public:
    vector<int> n1,n2;
    unordered_map<int, int>freq2;

    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        n1=nums1;
        n2=nums2;
        for(int num : n2) {
            freq2[num]++;
        }
    }
    
    void add(int index, int val) {
        int ov=n2[index];
        freq2[ov]--;
        n2[index]+=val;
        freq2[n2[index]]++;
    }
    
    int count(int tot) {
        int res=0;
        for (int num : n1) {
            int target=tot-num;
            if (freq2.count(target)) {
                res+=freq2[target];
            }
        }
        return res;
    }
};