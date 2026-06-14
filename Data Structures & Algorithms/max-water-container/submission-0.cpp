class Solution {
public:
    int maxArea(vector<int>& heights) {
        int width = 0;
        int height = 0;
        int area = INT_MIN;
        int n = heights.size();
        int start = 0;
        int end = n-1;

        while(start < end) {
            width = end - start;
            height = min(heights[start], heights[end]);
            area = max(area, width * height);

            if(heights[start] > heights[end]) {
                end--;
            } else if(heights[start] < heights[end]) {
                start++;
            } else {
                end--;
                start++;
            }
        }

        return area;
    }
};
