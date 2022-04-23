// Runtime: 8 ms Memory Usage: 7.2 MB

class Solution
{
public:
    string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    long long MOD = 56800235583; // 6 ^62
    unordered_map<string, string> urlMap;

    // Encodes a URL to a shortened URL.
    string encode(string longUrl)
    {
        long long randomNum = rand() % MOD;
        string tinyThing = convertToB62(randomNum);
        while (urlMap.find(tinyThing) != urlMap.end())
        {
            randomNum = rand() % MOD;
            tinyThing = convertToB62(randomNum);
        }
        urlMap[tinyThing] = longUrl;
        return tinyThing;
    }

    string convertToB62(long long num)
    {
        string ans = "";
        while (num)
        {
            int mod = num % 62;
            ans += characters[mod];
            num /= 62;
        }
        return ans;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl)
    {
        return urlMap[shortUrl];
    }
};

// Runtime: 9 ms Memory Usage: 7.6 MB

class Solution
{

    unordered_map<string, string> encodeBase;
    unordered_map<string, string> decodeBase;

    string getAlphabet()
    {

        string ans;

        int num = (rand() % (122 - 97 + 1)) + 97;

        ans = char(num);

        return ans;
    }

    string getCode()
    {

        string code = "";

        code += to_string(rand() % 10) + getAlphabet() + to_string(rand() % 10) + getAlphabet() + to_string(rand() % 10) + getAlphabet();

        return code;
    }

public:
    Solution()
    {
        decodeBase[""] = "";
    }

    // Encodes a URL to a shortened URL.
    string encode(string longUrl)
    {

        if (encodeBase.find(longUrl) != encodeBase.end())
        {
            return encodeBase[longUrl];
        }

        string code = "";

        while (decodeBase.find(code) != decodeBase.end())
        {

            code = getCode();
        }

        string encodedString = "http://tinyurl.com/" + code;
        encodeBase[longUrl] = encodedString;
        decodeBase[encodedString] = longUrl;

        return encodedString;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl)
    {

        return decodeBase[shortUrl];
    }
};

// Runtime: 4 ms Memory Usage: 6.8 MB

class Solution
{
public:
    map<string, string> mp;
    int n = 0;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl)
    {
        string res = "http://tinyurl.com/" + to_string(n);
        n++;
        mp[res] = longUrl;
        return res;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl)
    {
        return mp[shortUrl];
    }
};