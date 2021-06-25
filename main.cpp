#include <iostream>

#include "CRC32.h"

#define DATA_SIZE 3

int main()
{
    CRC32 crc32(CRC32::FAST);
    uint8_t data[DATA_SIZE] = {'a', 'b', 'c'};
    uint32_t crc_value = crc32.getCRC32(data, DATA_SIZE);
    std::cout << std::hex << crc_value << std::endl;
    return 0;
}