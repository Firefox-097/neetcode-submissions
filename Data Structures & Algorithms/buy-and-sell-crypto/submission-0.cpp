class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maximum=-1;
        for(int i=0;i<prices.size();i++){
            for(int j=i+1;j<prices.size();j++){
                int profit=prices[j]-prices[i];
                maximum=max(maximum,profit);
            }
        }
        if(maximum<=0){
            return 0;
        }
        else{
            return maximum;
        }
    }
};
