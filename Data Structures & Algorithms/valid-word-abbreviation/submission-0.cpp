class Solution {
   public:
    bool validWordAbbreviation(string word, string abbr) {
        int i = 0, j = 0;

        while (i < word.length() && j < abbr.length()) {
            char wc = word[i];
            char ac = abbr[j];

            if (isdigit(ac)) {
                if (ac == '0') {
                    return false;
                }

                // abbreviation mein diya hua number ko generate krre hai
                int curr = 0;

                while (j < abbr.length() && isdigit(abbr[j])) {
                    curr = curr * 10 + (abbr[j] - '0');
                    j++;
                }

                i = i + curr;

            } else {
                if (wc != ac) {
                    return false;
                }

                i++;
                j++;
            }
        }

        return i == word.length() &&
               j == abbr.length();  // jo dono pointer hai vo dono apne respective strings k ekdam
                                    // end mein hone chahiye by the end of the complete iteration
    }
};