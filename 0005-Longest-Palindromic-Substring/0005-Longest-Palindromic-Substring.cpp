class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        
        int start = 0, maxLength = 0;
        
        for (int i = 0; i < s.length(); i++) {
            // Odd length palindrome (e.g., "aba")
            int len1 = expandAroundCenter(s, i, i);
            // Even length palindrome (e.g., "abba")
            int len2 = expandAroundCenter(s, i, i + 1);
            
            int len = max(len1, len2);
            
            if (len > maxLength) {
                maxLength = len;
                // Update the start index of the longest palindrome found so far
                start = i - (len - 1) / 2;
            }
        }
        
        return s.substr(start, maxLength);
    }
    
private:
    int expandAroundCenter(const string& s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        // Return the length of the palindrome
        return right - left - 1;
    }
};
