#include <stdio.h>

#define ARRAY_SIZE 7

int* shift_array(int array_in[], int shift_amount, char direction);
void print_array(int array[ARRAY_SIZE]);

int main()
{
    int array_in[ARRAY_SIZE] = {0, 1, 2, 3, 4, 5, 6};
    int array_out[ARRAY_SIZE];
    int* result_ptr;
    char direction;
    int shift_amount;

    printf("Direction (l/r)?\n");
    scanf(" %c", &direction);
    printf("Shift ammount by?\n");
    scanf("%d", &shift_amount);

    result_ptr = shift_array(array_in, shift_amount, direction);
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        array_out[i] = *(result_ptr + i);
    }
    

    printf("\n");
    print_array(array_out);

    return 0;
}

int* shift_array(int array_in[], int shift_amount, char direction)
{
    static int array_out[ARRAY_SIZE];
    if (direction == 'r')
    {
        for (int i = 0; i < ARRAY_SIZE - shift_amount; i++)
        {
            array_out[i + shift_amount] = array_in[i];
        }

        for (int i = ARRAY_SIZE - shift_amount; i < ARRAY_SIZE; i++)
        {
            array_out[i - ARRAY_SIZE + shift_amount] = array_in[i];
        }
    }

    else
    {
        for (int i = shift_amount; i < ARRAY_SIZE; i++)
        {
            array_out[i - shift_amount] = array_in[i];
        }

        for (int i = 0; i < shift_amount; i++)
        {
            array_out[i + ARRAY_SIZE - shift_amount] = array_in[i];
        }
    }

    return array_out;
}


void print_array(int array[ARRAY_SIZE])
{
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        printf("%d\n", array[i]);
    }
}