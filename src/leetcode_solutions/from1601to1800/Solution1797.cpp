#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/**
 * 1797. 设计一个验证系统 | 难度：中等
 */
class Solution1797
{
public:
    /**
     * 执行用时：56 ms, 在所有 C++ 提交中击败了 99.07% 的用户
     * 内存消耗：29.3 MB, 在所有 C++ 提交中击败了 92.99% 的用户
     * 通过测试用例：90 / 90
     */
    class AuthenticationManager
    {
    private:
        int timeToLive;
        unordered_map<string, int> map;

    public:
        AuthenticationManager(int timeToLive)
        {
            this->timeToLive = timeToLive;
        }

        void generate(string tokenId, int currentTime)
        {
            map[tokenId] = currentTime + timeToLive;
        }

        void renew(string tokenId, int currentTime)
        {
            if (map.count(tokenId) && map[tokenId] > currentTime)
            {
                map[tokenId] = currentTime + timeToLive;
            }
            else
            {
                map.erase(tokenId);
            }
        }

        int countUnexpiredTokens(int currentTime)
        {
            for (auto iter = map.begin(); iter != map.end();)
            {
                if (iter->second <= currentTime)
                    map.erase(iter++);
                else
                    ++iter;
            }
            return map.size();
        }
    };

    /**
     * Your AuthenticationManager object will be instantiated and called as such:
     * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
     * obj->generate(tokenId,currentTime);
     * obj->renew(tokenId,currentTime);
     * int param_3 = obj->countUnexpiredTokens(currentTime);
     */
};
