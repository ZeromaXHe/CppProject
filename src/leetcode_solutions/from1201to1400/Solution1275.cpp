#include <iostream>
#include <vector>

using namespace std;

/**
 * 1275. 找出井字棋的获胜者 | 难度：简单
 */
class Solution1275
{
public:
    /**
     * 执行用时：0 ms, 在所有 C++ 提交中击败了 100.00% 的用户
     * 内存消耗：7.9 MB, 在所有 C++ 提交中击败了 95.42% 的用户
     * 通过测试用例：100 / 100
     */
    string tictactoe(vector<vector<int>> &moves)
    {
        int set = 0;
        for (int i = (moves.size() - 1) % 2; i < moves.size(); i += 2)
        {
            set += (1 << (3 * moves[i][0] + moves[i][1]));
        }
        // std::cout << "set: " << set << std::endl;
        // std::cout << "0b1010100: " << 0b1010100 << std::endl;
        // std::cout << "set & 0b1010100: " << (set & 0b1010100) << std::endl;
        // std::cout << "equals: " << (0b1010100 & set == 0b1010100) << std::endl;   // 0
        // std::cout << "equals: " << ((0b1010100 & set) == 0b1010100) << std::endl; // 1
        if ((0b111000000 & set) == 0b111000000 || (0b111000 & set) == 0b111000 ||
            (0b111 & set) == 0b111 || (0b100010001 & set) == 0b100010001 ||
            (0b1010100 & set) == 0b1010100 || (0b100100100 & set) == 0b100100100 ||
            (0b10010010 & set) == 0b10010010 || (0b1001001 & set) == 0b1001001)
        {
            return moves.size() % 2 == 0 ? "B" : "A";
        }
        return moves.size() == 9 ? "Draw" : "Pending";
    }
};

int main(int argc, char *argv[])
{
    Solution1275 solution;
    vector<vector<int>> moves = {{0, 0}, {1, 1}, {0, 1}, {0, 2}, {1, 0}, {2, 0}};
    std::cout << solution.tictactoe(moves) << std::endl; // B
    return 0;
}