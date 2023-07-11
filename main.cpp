#include <iostream>

int string_length(const char string[]) 
{
    int length = 0;
    while (string[length] != '\0') 
    {
        length++;
    }
    return length;
}

void encode_string(const char string[], bool bytes[][8]) 
{
    int len = string_length(string);
    
    for (int j = 0; j < len; j++) 
    {
        char character = string[j];
        for (int i = 0; i < 8; i++) 
        {
            bytes[j][i] = ((character >> (7 - i)) & 1) == 1;
        }
    }
    for (int i = 0; i < 8; i++) 
    {
        bytes[len][i] = ((char)0 >> (7 - i)) & 1;
    }
}

void decode_bytes(int rows, const bool bytes[][8], char string[]) 
{
    for (int j = 0; j < rows; j++) 
    {
        char character = 0;
        for (int i = 0; i < 8; i++) 
        {
            if (bytes[j][i]) 
            {
                character |= (1 << (7 - i));
            }
        }
        string[j] = character;
    }
}

int main() 
{
    const char* text = "Hello, how are you?";
    const int len = string_length(text);
    bool bytes1[len + 1][8];
    encode_string(text, bytes1);
    for (int j = 0; j <= len; j++) 
    {
        std::cout << text[j] << ": ";
        for (int i = 0; i < 8; i++) 
        {
            std::cout << bytes1[j][i];
        }
        std::cout << std::endl;
    }
    
    char decoded_text[len + 1];
    decode_bytes(len + 1, bytes1, decoded_text);
    std::cout << "Decoded text: " << decoded_text << std::endl;
    
    return 0;
}
