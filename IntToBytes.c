#include <stdint.h>
#include <stdio.h>
void printLONGINT(unsigned long long num){
    unsigned long int size = sizeof(unsigned long int);
    long int i;
    for(i = size*8-1; i>= 0; i--){
        printf("%u",(num >>i) & 1 );
    }
    printf("\n");
}
void printB(unsigned int num){
    unsigned int size = sizeof(unsigned int);
    int i;
    for(i = size*8-1; i>= 0; i--){
        printf("%u",(num >>i) & 1 );
    }
    printf("\n");
}
void splitInt64ToTwoInt32(uint64_t input, uint32_t* high, uint32_t* low) {
    // Extract the higher 32 bits and lower 32 bits
    *high = (uint32_t)(input >> 32);
    *low = (uint32_t)(input & 0xFFFFFFFF);
}

int main() {
    uint64_t originalValue = 0xDEADBEEF12345678; // Replace this with your 64-bit value
    printLONGINT(originalValue);
    uint32_t highPart, lowPart;

    // Split the 64-bit value into two 32-bit values
    splitInt64ToTwoInt32(originalValue, &highPart, &lowPart);

    // Print the results
    printf("Original 64-bit value: %lu\n", originalValue);
    printLONGINT(originalValue);
    printf("High 32 bits: %u\n", highPart);
    printB(highPart);
    printf("Low 32 bits: %u\n", lowPart);
    printB(lowPart);

    return 0;
}
