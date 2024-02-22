#include <stdio.h>

#define ARRAY_SIZE 7

void shift_right(int array_in[], int array_out[], int shift_amount);
void shift_left(int array_in[], int array_out[], int shift_amount);
void print_array(int array[ARRAY_SIZE]);


int main(){
    int array_in[ARRAY_SIZE] = {0, 1, 2, 3, 4, 5, 6};
    int array_out[ARRAY_SIZE];
    char direction;
    int shift_amount;
    
    printf("Direction (l/r)?\n");
    scanf(" %c", &direction);
    printf("Shift ammount by?\n");
    scanf("%d", &shift_amount);

    if (direction == 'r')
    {
        shift_right(array_in, array_out, shift_amount);
    }
    else{
        shift_left(array_in, array_out, shift_amount);
    }
    
    printf("\n");
    print_array(array_out);

    return 0;
}


void shift_right(int array_in[], int array_out[], int shift_amount){
    
    for(int i=0; i<ARRAY_SIZE-shift_amount; i++){
        array_out[i+shift_amount] = array_in[i];
    }

    for (int i = ARRAY_SIZE-shift_amount; i < ARRAY_SIZE; i++)
    {
        array_out[i-ARRAY_SIZE+shift_amount] = array_in[i];
    }
    
}

void shift_left(int array_in[], int array_out[], int shift_amount){
    
    for (int i = shift_amount; i < ARRAY_SIZE; i++)
    {
        array_out[i-shift_amount] = array_in[i];
    }

    for (int i = 0; i < shift_amount; i++)
    {
        array_out[i+ARRAY_SIZE-shift_amount] = array_in[i];
    }

}

void print_array(int array[ARRAY_SIZE]){
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        printf("%d\n", array[i]);
    }
    
}