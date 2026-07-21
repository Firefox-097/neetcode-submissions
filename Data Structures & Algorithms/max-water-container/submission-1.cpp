class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n=heights.size();
        int left=0,right=n-1;
        int maxi=0;
        while(left<right){
            int ht = min(heights[left] , heights[right]);
            int width=right - left;
            int area= ht * width;
            if(area > maxi ) maxi=area;
            if(heights[left]<heights[right]) left++;
            else right--;
        }
    return maxi;
    }
};
