class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int s = 0;
        int e = arr.size()-1;
        while(s<e){
            int mid = s+(e-s)/2;
            if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]) return mid;
            if(arr[mid]<arr[mid+1]) s = mid+1;
            else e = mid;
        }
        return -1;
    }
};

//  s  m      e
//. [0 2 4 5 3 1 1]
//         e
//   0 1 2 3 4 5