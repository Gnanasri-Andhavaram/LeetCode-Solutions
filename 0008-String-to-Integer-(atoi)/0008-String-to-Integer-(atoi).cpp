class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int n = s.length();
        
        // Step 1: Skip leading whitespace
        while (i < n && s[i] == ' ') {
            i++;
        }
        
        // If string is all whitespace
        if (i == n) return 0;
        
        // Step 2: Check sign
        int sign = 1;
        if (s[i] == '-') {
            sign = -1;
            i++;
        } else if (s[i] == '+') {
            i++;
        }
        
        // Step 3: Convert digits and handle overflow
        long long result = 0; // Use long long to detect overflow beyond 32-bit limits
        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';
            result = result * 10 + digit;
            
            // Step 4: Handle 32-bit signed integer rounding / overflow limits
            if (sign == 1 && result > INT_MAX) {
                return INT_MAX;
            }
            if (sign == -1 && -result < INT_MIN) {
                return INT_MIN;
            }
            
            i++;
        }
        
        return static_cast<int>(result * sign);
    }
};
