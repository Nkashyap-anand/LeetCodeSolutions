class Solution
{
public:
    int uniqueMorseRepresentations(vector<string> &words)
    {
        vector<string> morse_code = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
        unordered_set<string> set;

        for (auto word : words)
        {
            string code = "";
            for (auto ch : word)
                code += morse_code[ch - 'a'];
            set.insert(code);
        }

        return set.size();
    }
};