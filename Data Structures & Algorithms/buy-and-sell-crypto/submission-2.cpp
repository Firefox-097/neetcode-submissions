class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minP=prices[0];
        int n=prices.size();
        int maxi=0;
        for(int i=1;i<n;i++){
            minP=min(prices[i],minP);
            int profit=prices[i]-minP;
            maxi=max(maxi,profit);
        }
    return maxi;
    }
};
