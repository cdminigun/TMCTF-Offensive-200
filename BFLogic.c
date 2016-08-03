#include <stdio.h>
#include <stdlib.h>


int main(){
    int pwned;
    pwned = 0;
    printf("%x\n", pwned);
    while (1){
        if((((pwned >> 16)&0xFFFF ^ 0xc0fe) == 0x7eaf && (((pwned & 0xFFFF)^0x1a1a) == 0xdae4)))
        {
            printf("you got it.\n Pwned is: 0x%x\n", pwned);
        }
        pwned++;
    }

}
