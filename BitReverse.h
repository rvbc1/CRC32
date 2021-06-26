/*
 * BitReverse.h
 *
 *  Created on: Nov 15, 2020
 *      Author: rvbc1
 */

#ifndef SRC_BitReverse_H_
#define SRC_BitReverse_H_

#include <stddef.h>

#include "stdint.h"

class BitReverse {
   public:
    enum Mode {
        FAST,
        MEMORY_OPTIMIZED
    };

    BitReverse(Mode mode);
    uint32_t getReversed(uint32_t value);
    static uint32_t reverseBitOrderSlow(register uint32_t value);

   private:
    static const uint16_t BIT_REVERSE_TABLE_SIZE = 256;
    static uint8_t *bitReverseTable;

    Mode mode = FAST;
    void buildBitReverseTable(uint8_t *table, uint8_t value = 0, uint8_t position = 0, uint8_t shit = 0);
    uint32_t reverseBitOrderFast(uint32_t value);
};

#endif /* SRC_BitReverse_H_ */
