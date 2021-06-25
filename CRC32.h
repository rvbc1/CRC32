/*
 * CRC32.h
 *
 *  Created on: Nov 15, 2020
 *      Author: rvbc1
 */

#ifndef SRC_CRC32_H_
#define SRC_CRC32_H_

#include <stddef.h>

#include "stdint.h"

class CRC32 {
   public:
    enum crc_mode {
        FAST,
        MEMORY_OPTIMIZED
    };

    CRC32(crc_mode mode);
    uint32_t getCRC32(uint8_t *data, size_t size);
    void setDivisor(uint32_t divisor);

   private:
    const uint16_t CRC32_TABLE_SIZE = 256;
    uint32_t *crc32_table = nullptr;
    const uint32_t DEFAULT_DIVISOR = 0xEDB88320;
    uint32_t divisor = DEFAULT_DIVISOR;

    crc_mode mode = FAST;
    void build_crc32_table(void);
    uint32_t crc32_fast(uint8_t *data, size_t size);
    uint32_t crc32(uint8_t *data, size_t size);
};

#endif /* SRC_CRC32_H_ */
