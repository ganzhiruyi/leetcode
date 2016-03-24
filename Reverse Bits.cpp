// O(32)
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ret = 0;
        int k = 0;
        while(k++ < 32){
            ret = (ret<<1)|(n&1);
            n >>= 1;
        }
        return ret;
    }
};
// 利用位运算，二分的思想依次交换16,8,4,2,1位，每一次直接将这一层的树节点全部交换
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        n = (n>>16)|(n<<16);
        n = ((n&0xff00ff00)>>8)|((n&0x00ff00ff)<<8);
        n = ((n&0xf0f0f0f0)>>4)|((n&0x0f0f0f0f)<<4);
        n = ((n&0xcccccccc)>>2)|((n&0x33333333)<<2);
        n = ((n&0xaaaaaaaa)>>1)|((n&0x55555555)<<1);
        return n;
    }
};
