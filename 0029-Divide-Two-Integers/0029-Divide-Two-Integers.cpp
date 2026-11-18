class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == divisor) return 1;
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        if (dividend == INT_MIN && divisor == 1) return INT_MIN;

        long long dvd = labs(dividend);
        long long dvs = labs(divisor);
        bool negative = (dividend < 0) ^ (divisor < 0);
        long long quotient = 0;

        while (dvd >= dvs) {
            long long temp = dvs, multiple = 1;
            while (dvd >= (temp << 1) && (temp << 1) > 0) {
                temp <<= 1;
                multiple <<= 1;
            }
            dvd -= temp;
            quotient += multiple;
        }

        return negative ? -quotient : quotient;
    }
};
