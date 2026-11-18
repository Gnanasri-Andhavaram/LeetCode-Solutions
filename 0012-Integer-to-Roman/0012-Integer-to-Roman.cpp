class Solution {
public:
    string intToRoman(int num) {
        // Store all standard and subtractive Roman numeral values in descending order
        vector<pair<int, string>> valueSymbols = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
            {100, "C"},  {90, "XC"},  {50, "L"},  {40, "XL"},
            {10, "X"},   {9, "IX"},   {5, "V"},   {4, "IV"},
            {1, "I"}
        };

        string roman = "";

        // Iterate through each value-symbol pair from largest to smallest
        for (const auto& [value, symbol] : valueSymbols) {
            // Stop early if the remaining number is reduced to 0
            if (num == 0) break;

            // Append the symbol while its value can be subtracted from num
            while (num >= value) {
                roman += symbol;
                num -= value;
            }
        }

        return roman;
    }
};
