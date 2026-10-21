class Solution {
   public:
    bool validWordAbbreviation(string word, string abbr) {
        int i = 0, j = 0;

        while (i < word.length() && j < abbr.length()) {
            char wc = word[i];
            char ac = abbr[j];

            if (isdigit(ac)) {
                if (ac == '0') {
                    return false;  // number 0 se start nahi ho skta
                }

                // abbreviation mein diya hua number ko generate krre hai
                int curr = 0;

                while (j < abbr.length() && isdigit(abbr[j])) {
                    curr = curr * 10 + (abbr[j] - '0');  // digit ko number mein convert krre hai
                    j++;
                }

                i = i + curr;  // word mein utne characters skip krdo

            } else {
                if (wc != ac) {
                    return false;  // dono characters match nahi hue toh false
                }

                i++;  // word ka next character
                j++;  // abbreviation ka next character
            }
        }

        // dono pointers apni respective strings ke end mein hone chahiye
        return i == word.length() && j == abbr.length();

        // Time Complexity : O(m + n)
        // ~ word aur abbr ke har character ko maximum ek baar traverse krre hai
        // Space Complexity : O(1)
        // ~ sirf i, j, curr aur kuch character variables use krre hai
    }
};