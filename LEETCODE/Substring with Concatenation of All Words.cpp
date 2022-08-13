class Solution
{
public:
    vector<int> findSubstring(string s, vector<string> &words)
    {

        unordered_map<string, int> M, temp;
        vector<int> Ans;
        int N = words.size();
        int L = words[0].size();

        // Store all the frequencies of all strings
        // in the array words[]
        for (auto &it : words)
        {
            M[it]++;
        }
        int size = s.length();

        // Loop till possible number of starting
        // index of the valid indices
        for (int i = 0; i < size - N * L + 1; i++)
        {

            // Iterate the current window of
            // length N*L over the range
            // [i, i + N*L] and extract the
            // substring of length L and store
            // it's frequency
            for (int j = i; j < i + N * L; j += L)
            {
                string ans = s.substr(j, L);
                if (M.find(ans) != M.end()) // string exists hance check for next word else this window is usless
                    temp[ans]++;
                else
                    break;
            }

            if (temp == M)
                Ans.push_back(i);

            // Clear the temp for another window
            temp.clear();
        }

        // Return the resultant vector of indices
        return Ans;
    }
};
