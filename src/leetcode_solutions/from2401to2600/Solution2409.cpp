#include <iostream>

using namespace std;

/**
 * 2409. 统计共同度过的日子数 | 难度：简单
 */
class Solution2409
{
    int monthDay[13] = {0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};

public:
    /**
     * 执行用时：0 ms, 在所有 C++ 提交中击败了 100.00% 的用户
     * 内存消耗：5.8 MB, 在所有 C++ 提交中击败了 43.90% 的用户
     * 通过测试用例：51 / 51
     */
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob)
    {
        int aam = (arriveAlice[0] - '0') * 10 + arriveAlice[1] - '0';
        int aad = (arriveAlice[3] - '0') * 10 + arriveAlice[4] - '0';
        int abm = (arriveBob[0] - '0') * 10 + arriveBob[1] - '0';
        int abd = (arriveBob[3] - '0') * 10 + arriveBob[4] - '0';
        int dayArriveA = monthDay[aam] + aad;
        int dayArriveB = monthDay[abm] + abd;

        int lam = (leaveAlice[0] - '0') * 10 + leaveAlice[1] - '0';
        int lad = (leaveAlice[3] - '0') * 10 + leaveAlice[4] - '0';
        int lbm = (leaveBob[0] - '0') * 10 + leaveBob[1] - '0';
        int lbd = (leaveBob[3] - '0') * 10 + leaveBob[4] - '0';
        int dayLeaveA = monthDay[lam] + lad;
        int dayLeaveB = monthDay[lbm] + lbd;

        if (dayArriveB > dayLeaveA || dayArriveA > dayLeaveB) {
            return 0;
        }
        return min(dayLeaveA, dayLeaveB) - max(dayArriveA, dayArriveB) + 1;
    }
};