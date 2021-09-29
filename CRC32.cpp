/*
 * CRC32.cpp
 *
 *  Created on: Nov 15, 2020
 *      Author: rvbc1
 *
 *      https://lxp32.github.io/docs/a-simple-example-crc32-calculation/
 */

#include "CRC32.h"

uint32_t CRC32::getCRC32(uint8_t *data, size_t size) {
    if (mode == FAST) {
        return crc32_fast(data, size);
    } else if (mode == MEMORY_OPTIMIZED) {
        return crc32(data, size);
    }
    return 0;
}

void CRC32::setDivisor(uint32_t divisor) {
    this->divisor = divisor;
    if (mode == FAST) {
        build_crc32_table();
    }
}

uint32_t CRC32::crc32(uint8_t *data, size_t size) {
    uint32_t crc = 0xFFFFFFFF;

    for (size_t i = 0; i < size; i++) {
        uint8_t byte = data[i];
        for (size_t j = 0; j < 8; j++) {
            uint32_t b = (byte ^ crc) & 1;
            crc >>= 1;
            if (b)
                crc = crc ^ divisor;
            byte >>= 1;
        }
    }
    return ~crc;
}

void CRC32::build_crc32_table(void) {
    if(crc32_table){
        delete[] crc32_table;
    }

    crc32_table = new uint32_t[CRC32_TABLE_SIZE];

    for (uint32_t i = 0; i < CRC32_TABLE_SIZE; i++) {
        uint32_t ch = i;
        uint32_t crc = 0;
        for (size_t j = 0; j < 8; j++) {
            uint32_t b = (ch ^ crc) & 1;
            crc >>= 1;
            if (b)
                crc = crc ^ divisor;
            ch >>= 1;
        }
        crc32_table[i] = crc;
    }
}

uint32_t CRC32::crc32_fast(uint8_t *data, size_t size) {
    uint32_t crc = 0xFFFFFFFF;

    for (size_t i = 0; i < size; i++) {
        uint8_t byte = data[i];
        uint32_t t = (byte ^ crc) & 0xFF;
        crc = (crc >> 8) ^ crc32_table[t];
    }
    return ~crc;
}

CRC32::CRC32(crc_mode mode) {
    this->mode = mode;
    if (mode == FAST) {
        build_crc32_table();
    }
}
