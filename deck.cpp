//
// Created by ponso00 on 3/27/2023.
//
#include <cstdlib>
#include <random>

#include <ctime>
int card(int card){
    int i;
    srand(time(0));
    i = rand() % 52 + 1;
    if(i>=1 && i<=4){
        return 2;
    }
    else if(i>=5 && i<=8){
        return 3;
    }
    else if(i>=9 && i<=12){
        return 4;
    }
    else if(i>=13 && i<=16){
        return 5;
    }
    else if(i>=17 && i<=20){
        return 6;
    }
    else if(i>=21 && i<=24){
        return 7;
    }
    else if(i>=25 && i<=28){
        return 8;
    }
    else if(i>=29 && i<=32){
        return 9;
    }
    else if(i>=33 && i<=48){
        return 10;
    }
    else{
        return 11;
    }

}