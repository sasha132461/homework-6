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
    int arr[8] = {128, 64, 32, 16, 8, 4, 2, 1};

    for (int i = 0; i < string_length(string) + 1; i++)
    {
        int x = (int)string[i];
        int y = (int)string[i];

        if (x % 2 != 0)
        {
            bytes[i][7] = true;
            x = x - 1;

            for (int b = 0; b < 7; b++)
            {
                if (arr[b] > x)
                {
                    bytes[i][b] = false;
                }
                if (arr[b] == x)
                {
                    bytes[i][b] = true;
                    x = 0;
                }
                if (arr[b] < x)
                {
                    x = x % arr[b];
                    bytes[i][b] = true;
                }
            }
        }
        if (y % 2 == 0)
        {
            for (int c = 0; c < 8; c++)
            {
                if (arr[c] > y)
                {
                    bytes[i][c] = false;
                }
                if (arr[c] == y)
                {
                    bytes[i][c] = true;
                    y = 0;
                }
                if (arr[c] < y)
                {
                    y = y % arr[c];
                    bytes[i][c] = true;
                }
            }
        }
    }
}

void decode_bytes(const int rows, const bool bytes[][8], char string[]) {
    int arr[8] = {128, 64, 32, 16, 8, 4, 2, 1};
    int sum = 0;
    for (int a = 0; a < rows; a++) {
        for (int b = 0; b < 8; b++) {
            if (bytes[a][b]) {
                sum += arr[b];
            }
        }
        string[a] = sum;
        sum = 0;
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
    
    bool bytes2[20][8] = 
    {
        {0,1,0,0,1,0,0,0},
        {0,1,1,0,0,1,0,1},
        {0,1,1,0,1,1,0,0},
        {0,1,1,0,1,1,0,0},
        {0,1,1,0,1,1,1,1},
        {0,0,1,0,1,1,0,0},
        {0,0,1,0,0,0,0,0},
        {0,1,1,0,1,0,0,0},
        {0,1,1,0,1,1,1,1},
        {0,1,1,1,0,1,1,1},
        {0,0,1,0,0,0,0,0},
        {0,1,1,0,0,0,0,1},
        {0,1,1,1,0,0,1,0},
        {0,1,1,0,0,1,0,1},
        {0,0,1,0,0,0,0,0},
        {0,1,1,1,1,0,0,1},
        {0,1,1,0,1,1,1,1},
        {0,1,1,1,0,1,0,1},
        {0,0,1,1,1,1,1,1},
        {0,0,0,0,0,0,0,0}
    };
    char string[20];
    decode_bytes(20, bytes2, string);
    std::cout << string << std::endl;

    return 0;
}
