class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        sort(prices.begin(),prices.end());
        int diff=money-(prices[0]+prices[1]);
        if(diff<0)return money;
        return diff;

    }
};