class Solution
{
public:
    int maxArea(int h, int w, vector<int> &hc, vector<int> &vc)
    {

        int m = 1e9 + 7;

        sort(hc.begin(), hc.end());
        sort(vc.begin(), vc.end());

        int maxh = hc[0];
        int maxw = vc[0];
        int i;

        for (i = 1; i < hc.size(); ++i)
        {
            maxh = max(maxh, hc[i] - hc[i - 1]);
        }
        maxh = max(maxh, h - hc[i - 1]);

        for (i = 1; i < vc.size(); ++i)
        {
            maxw = max(maxw, vc[i] - vc[i - 1]);
        }
        maxw = max(maxw, w - vc[i - 1]);

        return ((long long)maxh * maxw) % m;
    }
};