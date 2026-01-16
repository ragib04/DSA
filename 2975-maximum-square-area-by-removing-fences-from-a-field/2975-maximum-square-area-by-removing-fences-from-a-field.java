class Solution {
    private int mod = 1000000007;
    public int maximizeSquareArea(int m, int n, int[] hFences, int[] vFences) {
        
        HashMap<Integer, Integer> map = new HashMap<>();
        int h = hFences.length;
        int v = vFences.length;
        map.put(m - 1, 1);
        for(int i=0; i<h; i++){
            map.put(hFences[i] - 1, 1);
            map.put(m - hFences[i], 1);
            for(int j=i+1; j<h; j++){
                map.put(Math.abs(hFences[j] - hFences[i]), 1);
            }
        }

        int max = -1;
        if(map.containsKey(n - 1)) max = Math.max(max, n - 1);
        for(int i=0; i<v; i++){
            if(map.containsKey(vFences[i] - 1)) max = Math.max(max, vFences[i] - 1);
            if(map.containsKey(n - vFences[i])) max = Math.max(max, n - vFences[i]);
            for(int j=i+1; j<v; j++){
                if(map.containsKey(Math.abs(vFences[j] - vFences[i]))) max = Math.max(max, Math.abs(vFences[i] - vFences[j]));
            }
        }
        return max == -1 ? -1 : (int) ((long) max % mod * (long) max % mod) % mod;
    }
}