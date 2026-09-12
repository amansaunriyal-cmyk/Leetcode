class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int freq[10] = {0};

        for (int d : digits)
            freq[d]++;

        int ans = 0;

        // Hundreds digit: 1-9
        for (int i = 1; i <= 9; i++) {

            // Tens digit: 0-9
            for (int j = 0; j <= 9; j++) {

                // Units digit must be even
                for (int k = 0; k <= 8; k += 2) {

                    int a = i, b = j, c = k;

                    freq[a]--;
                    freq[b]--;
                    freq[c]--;

                    if (freq[a] >= 0 &&
                        freq[b] >= 0 &&
                        freq[c] >= 0) {
                        ans++;
                    }

                    // Restore frequencies
                    freq[a]++;
                    freq[b]++;
                    freq[c]++;
                }
            }
        }

        return ans;
    }
};