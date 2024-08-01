#include <stdio.h>


void driver(int argc, char  *argv[])
{
   int tc_number = atoi(argv[1]);
   switch (tc_number)
   {
         case 1:
            printf("%d\n", FnMinus(0, 0));
            printf("%d\n", FnMinus(5, 0));
            printf("%d\n", FnMinus(-5, 0));
            printf("%d\n", FnMinus(0, -5));
            printf("%d\n", FnMinus(0, 5));
            printf("%d\n", FnMinus(-5, 5));
            printf("%d\n", FnMinus(-5, -5));
            break;

        case 2:
            printf("%d\n", FnTimes(2, 3));
            printf("%d\n", FnTimes(-2, 3));
            printf("%d\n", FnTimes(2, -3));
            printf("%d\n", FnTimes(-2, -3));
            printf("%d\n", FnTimes(0, 3));
            printf("%d\n", FnTimes(2, 0));
            printf("%d\n", FnTimes(2, 10)); // Novo teste para FnTimes
            break;

        case 3:
            printf("%d\n", FnDivide(6, 3));
            printf("%d\n", FnDivide(6, -3));
            printf("%d\n", FnDivide(-6, 3));
            printf("%d\n", FnDivide(-6, -3));
            printf("%d\n", FnDivide(5, 2));
            printf("%d\n", FnDivide(7, 3));
            printf("%d\n", FnDivide(5, -2));
            printf("%d\n", FnDivide(7, -3));
            printf("%d\n", FnDivide(-5, 2));
            printf("%d\n", FnDivide(-7, 3));
            printf("%d\n", FnDivide(-5, -2));
            printf("%d\n", FnDivide(-7, -3));
            break;

        case 4:
            printf("%d\n", DefineAndRoundFraction(1, 2));
            printf("%d\n", DefineAndRoundFraction(2, 4));
            printf("%d\n", DefineAndRoundFraction(3, 7));
            printf("%d\n", DefineAndRoundFraction(5, 10));
            printf("%d\n", DefineAndRoundFraction(-1, 2));
            printf("%d\n", DefineAndRoundFraction(1, -2));
            printf("%d\n", DefineAndRoundFraction(-1, -2));
            printf("%d\n", DefineAndRoundFraction(0, 1));
            printf("%d\n", DefineAndRoundFraction(0, -1));
            break;

        case 5:
            printf("%d\n", FnMinus(10, 5)); // Novo teste para FnMinus
            printf("%d\n", FnTimes(-3, 4)); // Novo teste para FnTimes
            printf("%d\n", FnDivide(50, -5)); // Novo teste para FnDivide
            printf("%d\n", DefineAndRoundFraction(7, 10)); // Novo teste para DefineAndRoundFraction
            break;

        case 6:
            printf("%d\n", FnMinus(20, 15)); // Novo teste para FnMinus
            printf("%d\n", FnTimes(6, 7)); // Novo teste para FnTimes
            printf("%d\n", FnDivide(-75, 5)); // Novo teste para FnDivide
            printf("%d\n", DefineAndRoundFraction(3, 5)); // Novo teste para DefineAndRoundFraction
            break;

        case 7:
            printf("%d\n", FnMinus(100, 90)); // Novo teste para FnMinus
            printf("%d\n", FnTimes(-9, 8)); // Novo teste para FnTimes
            printf("%d\n", FnDivide(125, -25)); // Novo teste para FnDivide
            printf("%d\n", DefineAndRoundFraction(1, 3)); // Novo teste para DefineAndRoundFraction
            break;

        case 8:
            printf("%d\n", FnMinus(50, 40)); // Novo teste para FnMinus
            printf("%d\n", FnTimes(10, 11)); // Novo teste para FnTimes
            printf("%d\n", FnDivide(-80, 4)); // Novo teste para FnDivide
            printf("%d\n", DefineAndRoundFraction(2, 7)); // Novo teste para DefineAndRoundFraction
            break;

        case 9:
            printf("%d\n", FnMinus(30, 25)); // Novo teste para FnMinus
            printf("%d\n", FnTimes(-13, 12)); // Novo teste para FnTimes
            printf("%d\n", FnDivide(150, -30)); // Novo teste para FnDivide
            printf("%d\n", DefineAndRoundFraction(4, 5)); // Novo teste para DefineAndRoundFraction
            break;

        case 10:
            printf("%d\n", FnMinus(40, 35)); // Novo teste para FnMinus
            printf("%d\n", FnTimes(-14, 15)); // Novo teste para FnTimes
            printf("%d\n", FnDivide(200, -40)); // Novo teste para FnDivide
            printf("%d\n", DefineAndRoundFraction(5, 6)); // Novo teste para DefineAndRoundFraction
            break;

        case 11:
            printf("%d\n", FnMinus(60, 55)); // Novo teste para FnMinus
            printf("%d\n", FnTimes(16, 17)); // Novo teste para FnTimes
            printf("%d\n", FnDivide(-240, 6)); // Novo teste para FnDivide
            printf("%d\n", DefineAndRoundFraction(6, 7)); // Novo teste para DefineAndRoundFraction
            break;

        case 12:
            printf("%d\n", FnMinus(70, 65)); // Novo teste para FnMinus
            printf("%d\n", FnTimes(-18, 19)); // Novo teste para FnTimes
            printf("%d\n", FnDivide(300, -60)); // Novo teste para FnDivide
            printf("%d\n", DefineAndRoundFraction(7, 8)); // Novo teste para DefineAndRoundFraction
            break;

        case 13:
            printf("%d\n", FnMinus(90, 85)); // Novo teste para FnMinus
            printf("%d\n", FnTimes(20, 21)); // Novo teste para FnTimes
            printf("%d\n", FnDivide(-360, 9)); // Novo teste para FnDivide
            printf("%d\n", DefineAndRoundFraction(8, 9)); // Novo teste para DefineAndRoundFraction
            break;

        case 14:
            printf("%d\n", FnMinus(100, 95)); // Novo teste para FnMinus
            printf("%d\n", FnTimes(22, 23)); // Novo teste para FnTimes
            printf("%d\n", FnDivide(400, -80)); // Novo teste para FnDivide
            printf("%d\n", DefineAndRoundFraction(9, 10)); // Novo teste para DefineAndRoundFraction
            break;
        case 15:
            printf("%d\n", DefineAndRoundFraction(1, 3)); // a * 2 < b
            printf("%d\n", DefineAndRoundFraction(2, 6)); // a * 2 < b
            printf("%d\n", DefineAndRoundFraction(-3, 6)); // a * 2 < b
            break;
        case 16:
            printf("%d\n", FnDivide(10, 0)); // Dividing by zero should trigger the error message and return 0
            break;
   }
}

