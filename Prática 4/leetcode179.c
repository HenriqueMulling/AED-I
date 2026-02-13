#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* largestNumber(int* nums, int numsSize) {

    char* result = (char*)malloc(numsSize *15 *sizeof(char)); //malloc para resultado final
    result[0] = '\0'; // resultado inicia vazio
    
    for(int i = 0; i < numsSize - 1; i++){ // numsSize - 1 para não chegar no ultimo elemento
        for(int j = i + 1; j < numsSize; j++){
            char ab[40]; //strings para soma a + b
            char ba[40]; //string para soma b + a

        sprintf(ab, "%d%d", nums[i], nums[j]); // (a+b)
        sprintf(ba, "%d%d", nums[j], nums[i]); // (b+a)

            if(strcmp(ba,ab) > 0){ // se (b+a) > (a+b), troca eles de lugar
                int temp = nums[i];
                nums[i] = nums[j]; // o resultado de i vira j
                nums[j] = temp; // j vira resultado de i
            }
        }
    }

        if(nums[0] == 0){ //sem nums tiver só 0, retorna 0
            return "0";
        }

        for(int i = 0; i < numsSize; i++){
            char temp[30];
            sprintf(temp, "%d", nums[i]); //salva em temp o numero
            strcat(result, temp); //coloca o valr em temp
        }

    return result;
}



int main() {
    int nums[] = {3, 30, 34, 5, 9};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    char* finalResult = largestNumber(nums, numsSize);

    printf("Maior numero: %s\n", finalResult);

    if (strcmp(finalResult, "0") != 0) {
        free(finalResult); 
    }

    return 0;
}