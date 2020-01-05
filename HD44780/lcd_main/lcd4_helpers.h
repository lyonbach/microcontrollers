
#ifndef LCD4_HELPER_HEADER
#define LCD4_HELPER_HEADER


int* decToBin(int dec)
{
    static int dataBits[4];
    for(int i = 3; i >= 0; i--)
    {
        dataBits[i] = dec % 2;
        dec /= 2;
    }
    return dataBits;
}

int* getRomCode(char c)
{
    static int romCode[8];
    int rows = 16;
    int *currentBits;
    int offset = (int)c;   // 2*rows+1 = 33 -> from the space for CG RAM;

    currentBits = decToBin(offset / rows);
    for (int i = 0; i < 4; i++)
        romCode[i] = currentBits[i];

    currentBits =  decToBin(offset % rows);
    for (int i = 0; i < 4; i++)
        romCode[4 + i] = currentBits[i];

    return romCode;
}

#endif /*LCD4_HELPER_HEADER*/
// int* getRomCodes(char* word, int len)
// {

//     int romCodeChain[len];
//     int* romCode;
//     for (int i = 0; i < len; i++)
//     {
//         romCode = getRomCode(word[i]);
//         std::cout << "character: " << word[i] << ": ";
//         for(int j = 0; j < 8; j++)
//             romCodeChain[j] = romCode[j];
//         for(int j = 0; j < 8; j++)
//             std::cout << romCode[j];
//         std::cout << std::endl;
//     }

// }
