#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        char *buffer = NULL;
        scanf("%ms", &buffer);
        int i = 0, CoefficientOfX = 0, Const = 0, coefficient = 0;
        bool plus = true, EmptyCoefficient = true;
        while(buffer[i] != '=') {
            if(isdigit(buffer[i])) {
                coefficient = coefficient * 10 + buffer[i] - '0';
                EmptyCoefficient = false;
            } else if(buffer[i] == '+') {
                if(plus)
                    Const += coefficient;
                else {
                    Const -= coefficient;
                    plus = true;
                }
                coefficient = 0;
                EmptyCoefficient = true;
            } else if(buffer[i] == '-') {
                if(plus) {
                    Const += coefficient;
                    plus = false;
                } else
                    Const -= coefficient;
                coefficient = 0;
                EmptyCoefficient = true;
            } else if(buffer[i] == 'x') {
                if(plus)
                    CoefficientOfX += EmptyCoefficient + coefficient;
                else
                    CoefficientOfX -= EmptyCoefficient + coefficient;
                coefficient = 0;
                EmptyCoefficient = true;
            }
            ++i;
        }
        if(plus)
            Const += coefficient;
        else
            Const -= coefficient;
        plus = true;
        coefficient = 0;
        EmptyCoefficient = true;
        ++i;
        int len = strlen(buffer);
        while(i < len) {
            if(isdigit(buffer[i])) {
                coefficient = coefficient * 10 + buffer[i] - '0';
                EmptyCoefficient = false;
            } else if(buffer[i] == '+') {
                if(plus)
                    Const -= coefficient;
                else {
                    Const += coefficient;
                    plus = true;
                }
                coefficient = 0;
                EmptyCoefficient = true;
            } else if(buffer[i] == '-') {
                if(plus) {
                    Const -= coefficient;
                    plus = false;
                } else
                    Const += coefficient;
                coefficient = 0;
                EmptyCoefficient = true;
            } else if(buffer[i] == 'x') {
                if(plus)
                    CoefficientOfX -= EmptyCoefficient + coefficient;
                else
                    CoefficientOfX += EmptyCoefficient + coefficient;
                coefficient = 0;
                EmptyCoefficient = true;
            }
            ++i;
        }
        if(plus)
            Const -= coefficient;
        else
            Const += coefficient;
        if(CoefficientOfX == 0 && Const == 0)
            puts("IDENTITY");
        else if(CoefficientOfX == 0 && Const != 0)
            puts("IMPOSSIBLE");
        else
            printf("%.f\n", floor((double)Const / CoefficientOfX * (-1)));
        free(buffer);
    }
    return 0;
}
