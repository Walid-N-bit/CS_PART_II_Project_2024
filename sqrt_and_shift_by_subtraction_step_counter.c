//this code calculates the square root of a number
//it also calculates the number of instructions needed to simulate it in Y-86 assembly code for the project


#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int shift_by_one(int32_t x, int *i);
int shift_by_two(int32_t x, int *n);

int main()
{
    int32_t num = 5000004;      //largest possible number to be processed in the project's code
    //int32_t num = 3025;
    int32_t res = 0;
    int32_t bit = 1 << 22;
    int32_t bit2 = 1 << 22;
    int i = 0;
    int n = 0;
    printf("bit = %d\n", bit);
    //res = shift_by_one(num, &i);

    while (bit > num)
    {
        bit >>= 2;
        bit2 >>= 2;
    }
    while (bit != 0)
    {
        if (num >= res + bit)
        {
            num -= res + bit;
            res = shift_by_one(res, &i) + bit;
        }
        else
        {
            res = shift_by_one(res, &i);
        }
        bit >>= 2;
        //bit = shift_by_two(bit, &n);
    }

    // iterations number = number of subtractions * number of instruction per small loop + number of non-looping instructions
    i = i * 4 + 9 + 12;
    printf("result = %d\n", res);
    printf("shift by one iterations = %d\n", i);

    bit2 = shift_by_two(bit2, &n);
    bit2 = shift_by_two(bit2, &n);
    bit2 = shift_by_two(bit2, &n);
    bit2 = shift_by_two(bit2, &n);
    bit2 = shift_by_two(bit2, &n);
    bit2 = shift_by_two(bit2, &n);
    bit2 = shift_by_two(bit2, &n);
    bit2 = shift_by_two(bit2, &n);
    bit2 = shift_by_two(bit2, &n);
    bit2 = shift_by_two(bit2, &n);
    bit2 = shift_by_two(bit2, &n);

    // iterations number = number of subtractions * number of instruction per small loop + number of non-looping instructions
    n = n * 4 + 9 + 12;
    printf("new bit = %d\n", bit2);
    printf("shift by two iterations= %d\n", n);
    return 0;
}

int shift_by_one(int32_t x, int *i)
{


    int32_t counter = 0;
    while (x != 0)
    {
        if (x >= 32768)
        {
            x -= 32768;
            counter += 16384;
            (*i)++;
        }
        else if (x >= 128)
        {
            x -= 128;
            counter += 64;
            (*i)++;
        }
        else if (x >= 2)
        {
            x -= 2;
            counter += 1;
            (*i)++;
        }

    }
    return counter;
}

int shift_by_two(int32_t x, int *n)
{

    int32_t counter = 0;
    while (x != 0)
    {
        if (x >= 1048576)
        {
            x -= 1048576;
            counter += 262144;
            (*n)++;
        }
        else if (x >= 16384)
        {
            x -= 16384;
            counter += 4096;
            (*n)++;
        }
        else if (x >= 4)
        {
            x -= 4;
            counter += 1;
            (*n)++;
        }

    }

    return counter;
}
