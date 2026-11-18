class Solution {
public:
    string convert(string s, int numRows) {
        // Base case: if numRows is 1 or greater than or equal to string length, 
        // no zigzag transformation is needed.
        if (numRows == 1 || numRows >= s.length()) {
            return s;
        }

        vector<string> rows(min(numRows, int(s.length())));
        int currentRow = 0;
        bool goingDown = false;

        for (char c : s) {
            rows[currentRow] += c;
            
            // Change direction when we hit the top or bottom row
            if (currentRow == 0 || currentRow == numRows - 1) {
                goingDown = !goingDown;
            }
            
            // Move up or down based on the current direction
            currentRow += goingDown ? 1 : -1;
        }

        // Combine all rows together
        string result = "";
        for (const string& row : rows) {
            result += row;
        }

        return result;
    }
};
