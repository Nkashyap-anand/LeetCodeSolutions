class Solution
{
public:
    int maxScore(vector<int> &cardPoints, int k)
    {
        vector<int> sum(cardPoints.size(), 0);
        int arrSum = 0;

        for (int i = 0; i < cardPoints.size(); i++)
        {
            arrSum += cardPoints[i];
            sum[i] = arrSum;
        }

        // case of selecting all elms
        if (k == cardPoints.size())
            return arrSum;

        int score = 0;     // final answer
        int subArrSum = 0; // window sum

        for (int i = 0; i <= k; i++)
        {
            int j = i + cardPoints.size() - k - 1; // window size

            if (i == 0)
                subArrSum = sum[j];

            else
            {
                subArrSum = sum[j] - sum[i - 1];
            }

            score = max(score, arrSum - subArrSum);
        }

        return score;
    }
};