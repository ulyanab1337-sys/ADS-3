// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

uint64_t collatzMaxValue(uint64_t num) {
    uint64_t maxVal = num;
    uint64_t current = num;
    
    while (current != 1) {
        if (current % 2 == 0) {
            current /= 2;
        } else {
            current = 3 * current + 1;
        }
        if (current > maxVal) {
            maxVal = current;
        }
    }
    return maxVal;
}

unsigned int collatzLen(uint64_t num) {
    unsigned int length = 1; // начинаем с 1, так как включаем само число
    uint64_t current = num;
    
    while (current != 1) {
        if (current % 2 == 0) {
            current /= 2;
        } else {
            current = 3 * current + 1;
        }
        length++;
    }
    return length;
}

unsigned int seqCollatz(unsigned int *maxlen,
    uint64_t lbound,
    uint64_t rbound) {
    
    uint64_t bestNum = lbound;
    unsigned int maxLength = 0;
    
    for (uint64_t i = lbound; i <= rbound; i++) {
        unsigned int currentLen = collatzLen(i);
        if (currentLen > maxLength) {
            maxLength = currentLen;
            bestNum = i;
        }
    }
    
    *maxlen = maxLength;
    return bestNum;
}
