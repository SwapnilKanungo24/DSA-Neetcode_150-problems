class Solution:
    def maxArea(self, heights: List[int]) -> int:
        i = 0
        j = len(heights) - 1
        maxwater = -1e5
        while(i < j):
            l = j - i;
            b = min(heights[i], heights[j])
            maxwater = max(maxwater, l*b)

            if(heights[i] < heights[j]):
                i += 1
            else:
                j -= 1
        return maxwater

        