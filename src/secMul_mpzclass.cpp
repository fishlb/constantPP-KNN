#include "../include/secknn.h"
vector<mpz_class> secMul_mpz(const vector<vector<mpz_class>> &triple_shares,
                        mpz_class x_share1, mpz_class x_share2,
                        mpz_class y_share1, mpz_class y_share2)
{

    // e1=x1-a1, e2=x2-a2, f1=y1-b1, f2=y2-b2
    mpz_class e1 = x_share1 - triple_shares[0][0];
    mpz_class e2 = x_share2 - triple_shares[0][1];
    mpz_class f1 = y_share1 - triple_shares[1][0];
    mpz_class f2 = y_share2 - triple_shares[1][1];

    // e=x-a, f=y-b
    mpz_class e = e1 + e2;
    mpz_class f = f1 + f2;

    vector<mpz_class> xy_shares(2, 0);

    xy_shares[0] = e * f + triple_shares[1][0] * e + triple_shares[0][0] * f + triple_shares[2][0];
    xy_shares[1] = triple_shares[1][1] * e + triple_shares[0][1] * f + triple_shares[2][1];

    return xy_shares;
}
