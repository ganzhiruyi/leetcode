class Solution {
public:
    /** 找规律，一次可以取1,2,3个，所以1,2,3是先手必胜，2是先手必败,
    接下去有5,6,7先手必胜，8先手必败，以此类推得出结论
    **/
    bool canWinNim(int n) {
        return n%4;
    }
};
