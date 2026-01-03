#include "../include/secknn.h"
vector<uint64_t> secMul(const vector<vector<uint64_t>> &triple_shares,
                        uint64_t x_share1, uint64_t x_share2,
                        uint64_t y_share1, uint64_t y_share2)
{
    // compute e1=x1-a1, e2=x2-a2, f1=y1-b1, f2=y2-b2
    uint64_t e1 = x_share1 - triple_shares[0][0];
    uint64_t e2 = x_share2 - triple_shares[0][1];
    uint64_t f1 = y_share1 - triple_shares[1][0];
    uint64_t f2 = y_share2 - triple_shares[1][1];

    // reconstruct e=x-a, f=y-b
    uint64_t e = e1 + e2;
    uint64_t f = f1 + f2;

    vector<uint64_t> xy_shares(2, 0);

    xy_shares[0] = e * f + triple_shares[1][0] * e + triple_shares[0][0] * f + triple_shares[2][0];
    xy_shares[1] = triple_shares[1][1] * e + triple_shares[0][1] * f + triple_shares[2][1];

    return xy_shares;
}
