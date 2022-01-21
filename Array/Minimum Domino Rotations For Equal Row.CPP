class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        int nums1 = tops[0], nums2 = bottoms[0];
        int cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0;
        for(int i=0; i<n; i++) {
            if(cnt1!=INT_MAX) {
                if(tops[i]==nums1) {}
                else if(bottoms[i]==nums1) cnt1++;
                else cnt1 = INT_MAX;
            }
            if(cnt2!=INT_MAX) {
                if(tops[i]==nums2) {}
                else if(bottoms[i]==nums2) cnt2++;
                else cnt2 = INT_MAX;
            }
            if(cnt3!=INT_MAX) {
                if(bottoms[i]==nums1) {}
                else if(tops[i]==nums1) cnt3++;
                else cnt3 = INT_MAX;
            }
            if(cnt4!=INT_MAX) {
                if(bottoms[i]==nums2) {}
                else if(tops[i]==nums2) cnt4++;
                else cnt4 = INT_MAX;
            }
        }
        int ans = min({cnt1, cnt2, cnt3, cnt4});
        return ans==INT_MAX ? -1 : ans;
    }
};