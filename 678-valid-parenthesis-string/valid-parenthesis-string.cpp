class Solution {
public:
    bool checkValidString(string s) {
        int minOpen = 0, maxOpen = 0;
        for (char c : s) {
            if (c == '(') {
                minOpen++; // Treat as opening
                maxOpen++; // Treat as opening
            } else if (c == ')') {
                minOpen--; // Treat as closing
                maxOpen--; // Treat as closing
            } else if (c == '*') {
                minOpen--; // Treat as closing
                maxOpen++; // Treat as opening
            }
            if (maxOpen < 0) return false; // More closing parentheses than opening
            if (minOpen < 0) minOpen = 0; // Reset minOpen if negative
        }
        return minOpen == 0; // Check if balanced
    }
};