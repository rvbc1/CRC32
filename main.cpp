#include <iostream>

#include "CRC32.h"
#include "BitReverse.h"

#define DATA_SIZE 3

int main() {
    CRC32 crc32(CRC32::FAST);
    uint32_t poly = 0x1EDC6F41;

    //This CRC32 Algorithm is lsb-first implementation. For "normal" (msb-first) representation Polynomial(Divisor) use BitReverse.
    BitReverse bitReverser(BitReverse::FAST);
    crc32.setDivisor(bitReverser.getReversed(poly));

    uint8_t data[DATA_SIZE] = {'a', 'b', 'c'};
    uint32_t crc_value = crc32.getCRC32(data, DATA_SIZE);
    std::cout << std::hex << crc_value << std::endl;
    return 0;
}