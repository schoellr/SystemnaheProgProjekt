#include <stdio.h>
#include <math.h>
#include "sincos.hh"

void sincos(int input){

    int a = input;
    for (int i = 0; i < a+1; i=i+1){
        double winkel = (360/a)*i;
        double sinus = sin(winkel*(M_PI/180));
        double cosinus = cos(winkel*(M_PI/180));
        printf("%0.2f\t%0.3f\t%0.3f\n", winkel, sinus, cosinus);
    }
}
