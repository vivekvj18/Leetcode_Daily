class Solution {
public:
    int rotatedDigits(int n) {
        int count = 0;
        for (int i = 1; i <= n; i++) {
            int number = i;
            int invalid = 0;
            bool changed = false;
            while (number) {
                int digit = number % 10;
                if (digit == 3 || digit == 4 || digit == 7) {
                    invalid = 1;
                }
                if (digit == 2 || digit == 5 || digit == 6 || digit == 9) {
                    changed = true;
                }
                number = number / 10;
            }
            if (invalid == 0 && changed == true) {
                count++;
            }
        }
        return count;
    }
};
