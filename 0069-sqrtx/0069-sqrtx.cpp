class Solution {
public:
    int mySqrt(int x) {
        long long low = 0;
        long long high = x;
        long long ans = 0;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (mid * mid <= x) {
                ans = mid;       // mid can be an answer
                low = mid + 1;   // try for a bigger answer
            }
            else {
                high = mid - 1;  // mid is too large
            }
        }

        return ans;
    }
};