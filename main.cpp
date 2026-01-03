#include "include/secknn.h"
#include <immintrin.h>
#include <wmmintrin.h>

#include <openssl/aes.h>

int main(){
    testPlainAcc();// test accuracy of plaintext baseline
    // testConstKNNAcc(0);// test accuracy of constant knn

    // testLaten(0,0);//test latency

    // test_offline_cost(0,0);//test offline cost

}
