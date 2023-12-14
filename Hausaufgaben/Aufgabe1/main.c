#include <stdio.h>
#include "sincos.hh"
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char *argv[]){

    if (argc != 2){
        printf("Nutzung: %s <Zahl>\n", argv[0]);
        return 1;
    }
    else{
        bool input_is_int = true;
        int lenght = strlen(argv[1]);
        for (int i = 0; i < lenght; i++){
            if (!isdigit(argv[1][i])){
                input_is_int = false;
            }
        }
        if (atoi(argv[1]) < 0) {
            printf("Error: Argument ist keine positive Zahl\n");
            return 1;
        } else if (!input_is_int) {
            printf("Error: Argument ist keine Zahl\n");
            return 1;
        } else {
            sincos(atoi(argv[1]));
        }
    }
    return 0;
}
