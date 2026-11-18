class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Map to store the last seen index of each character
        int charIndex[256];
        for (int i = 0; i < 256; i++) {
            charIndex[i] = -1;
        }

        int maxLength = 0;
        int left = 0;

        for (int right = 0; right < s.length(); right++) {
            char currentChar = s[right];

            // If the character has been seen and is within the current window
            if (charIndex[currentChar] >= left) {
                left = charIndex[currentChar] + 1;
            }

            // Update the last seen index of the current character
            charIndex[currentChar] = right;

            // Calculate the maximum length found so far
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};
