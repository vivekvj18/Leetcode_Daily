class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int count = 0;
        for (int i = num1; i <= num2; i++) {
            int number = i;
            string str;
            while (number) {
                str += number % 10;
                number /= 10;
            }
            reverse(str.begin(), str.end());
            int length = str.length();
            if (length >= 3) {
                for (int j = 1; j < length - 1; j++) {
                    if (str[j] > str[j - 1] && str[j] > str[j + 1]) {
                        count++;
                    } else if (str[j] < str[j - 1] && str[j] < str[j + 1]) {
                        count++;
                    }
                }
            }
        }
        return count;
    }
};
