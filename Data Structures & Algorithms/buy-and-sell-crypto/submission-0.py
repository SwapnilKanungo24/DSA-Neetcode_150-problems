class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        i, j, profit, n = 0, 0, 0, len(prices)
        while(j < n):
            if prices[j] < prices[i]:
                i = j
            if prices[j] > prices[i]:
                if profit < prices[j] - prices[i]:
                    profit = prices[j] - prices[i]
            j+=1
        return profit