class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty())
            return 0;
        auto minPrices = prices.front();
        auto maxProfit = 0;
        for(const auto& i : prices)
        {
            maxProfit = max(maxProfit, i - minPrices);
            minPrices = min(minPrices, i);
        }
        /*
        auto begin = prices.cbegin();
        auto end = prices.cend();
        for(; begin != end; ++begin)
        {
            auto t = *begin;
            maxProfit = max(maxProfit, t - minPrices);
            minPrices = min(minPrices, t);
        }
        */
        return maxProfit;
    }
};
