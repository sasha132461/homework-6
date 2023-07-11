#include <iostream>

void encode_char(const char character, bool bits[8]) {
    for (int i = 0; i < 8; i++) {
        bits[i] = ((character >> (7 - i)) & 1) == 1;
    }
}

char decode_byte(const bool bits[8]) {
    char character = 0;
    for (int i = 0; i < 8; i++) {
        character |= (bits[i] * 1) << (7 - i);
    }
    return character;
}

int main() {
    bool bits1[8];
    encode_char('A', bits1);
    for (int i = 0; i < 8; i++) {
        std::cout << bits1[i] << std::endl;
    }

    bool bits2[8] = {0, 1, 0, 0, 0, 0, 0, 1};
    std::cout << decode_byte(bits2) << std::endl;

    return 0;
}