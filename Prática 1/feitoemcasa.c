#include <stdbool.h>

bool lemonadeChange(int* bills, int billsSize) {
    int box = 0;
    int n5 = 0;
    int n10 = 0;
    int n20 = 0;

    for (int i = 0; i < billsSize; i++) {

        if (bills[i] == 5 || bills[i] == 10) {
            if (bills[i] == 5) {
                n5++;
                box = box + 5;
            }
            if (bills[i] == 10) {
                if (n5 > 0) {
                    box = box + 10;
                    n10++;
                    box = box - 5;
                    n5--;
                } else {
                    return false;
                }
            }
        }
        if (bills[i] == 20) {
            if (n5 > 0 && n10 > 0) {
                box = box + 20;
                n20++;
                box = box - 15;
                n10--;
                n5--;
            } else if (n5 >= 3) {
                box = box + 20;
                n20++;
                box = box - 15;
                n5 = n5 - 3;
            } else {
                return false;
            }
        }
    }
    return true;
}