class Solution {
    public int maxProfit(int[] prices) {

        int buyingPrice = prices[0];
        int maximumProfit = 0;

        for (int i = 1; i < prices.length; i++) {

            if (prices[i] < buyingPrice) {
                buyingPrice = prices[i];
            } else {

                int currentProfit = prices[i] - buyingPrice;

                if (currentProfit > maximumProfit) {
                    maximumProfit = currentProfit;
                }
            }
        }

        return maximumProfit;
    }
}