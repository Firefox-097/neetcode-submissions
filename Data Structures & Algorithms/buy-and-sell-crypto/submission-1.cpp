class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi=0;
        int n=prices.size();
        for(int i=0;i<n-1;i++){
            for(int j=i+1; j<n;j++){
                
                    int diff=prices[j]-prices[i];
                    maxi=max(maxi,diff);
                
            }
            
        }
       return maxi;
    }
};
