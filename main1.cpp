#include <iostream>

void encode_char(const char character, bool bits[8]) {
    int arr[8] = {128, 64, 32, 16, 8, 4, 2, 1};
    int a = character;
    if (a % 2 != 0) 
    {
        bits[7] = true;
        a = a - 1;
        for(int b=0; b<7; b++)
        {
            if (arr[b] == a) 
            {
                bits[b] = true;
                a = 0;
            } else if (arr[b] < a)
            {
                a = a % arr[b];
                bits[b] = true;
            } else if(arr[b] > a)
            {
                bits[b] = false;
            }
        }
    }
}

char decode_byte(const bool bits[8]) 
{
    int arr[8] = {128, 64, 32, 16, 8, 4, 2, 1};
    int a = 0;

    for (int i = 0; i < 8; i++) {
        if (bits[i]==true)
        {
            a += arr[i];
        }
    }
    return a;
}

int main() 
{
    bool bits1[8];
    encode_char('A', bits1);
    for (int i = 0; i < 8; i++) 
    {
        std::cout << bits1[i] << std::endl;
    }

    bool bits2[8] = {0, 1, 0, 0, 0, 0, 0, 1};
    std::cout << decode_byte(bits2) << std::endl;

    return 0;
}