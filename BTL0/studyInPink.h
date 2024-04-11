/*
    * Ho Chi Minh City University of Technology
    * Faculty of Computer Science and Engineering
    * Initial code for Assignment 0
    * Programming Fundamentals Spring 2022
    * Author: Tran Huy
    * Date: 06.01.2022
*/

//The library here is concretely set, students are not allowed to include any other libraries.
#ifndef studyInPink_h
#define studyInPink_h

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>

using namespace std;

////////////////////////////////////////////////////////////////////////
///STUDENT'S ANSWER BEGINS HERE
///Complete the following functions
///DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////
void test(int& HP1, int& HP2, int& EXP1, int& EXP2, int& M1, int& M2) {
    if (HP1 < 0) HP1 = 0;
    if (HP1 > 999) HP1 = 999;
    HP1 = ceil(HP1);
    if (HP2 < 0) HP2 = 0;
    if (HP2 > 999) HP2 = 999;
    HP2 = ceil(HP2);
    if (EXP1 < 0) EXP1 = 0;
    if (EXP1 > 900) EXP1 = 900;
    EXP1 = ceil(EXP1);
    if (EXP2 < 0) EXP2 = 0;
    if (EXP2 > 900) EXP2 = 900;
    EXP2 = ceil(EXP2);
    if (M1 < 0) M1 = 0;
    if (M1 > 2000) M1=2000;
    M1 = ceil(M1);
    if (M2 < 0) M2 = 0;
    if (M2 > 2000) M2 = 2000;
    M2 = ceil(M2);
}
void test1(int& EXP1, int& EXP2) {
    if (EXP1 < 0) EXP1 = 0;
    if (EXP1 > 900) EXP1 = 900;
    EXP1 = ceil(EXP1);
    if (EXP2 < 0) EXP2 = 0;
    if (EXP2 > 900) EXP2 = 900;
    EXP2 = ceil(EXP2);
}
void test2(int& EXP1, int& EXP2, int& HP2, int& M2) {
    if (EXP1 < 0) EXP1 = 0;
    if (EXP1 > 900) EXP1 = 900;
    EXP1 = ceil(EXP1);
    if (EXP2 < 0) EXP2 = 0;
    if (EXP2 > 900) EXP2 = 900;
    EXP2 = ceil(EXP2);
    if (HP2 < 0) HP2 = 0;
    if (HP2 > 999) HP2 = 999;
    HP2 = ceil(HP2);
    if (M2 < 0) M2 = 0;
    if (M2 > 2000) M2 = 2000;
    M2 = ceil(M2);
}
void test3(int& HP1, int& EXP1, int& M1) {
    if (HP1 < 0) HP1 = 0;
    if (HP1 > 999) HP1 = 999;
    HP1 = ceil(HP1);
    if (EXP1 < 0) EXP1 = 0;
    if (EXP1 > 900) EXP1 = 900;
    EXP1 = ceil(EXP1);
    if (M1 < 0) M1 = 0;
    if (M1 > 2000) M1 = 2000;
    M1 = ceil(M1);
}
int firstMeet(int& EXP1, int& EXP2, const int& E1){
    //Complete this function to gain point on task 1
    test1(EXP1, EXP2);
    if ((E1 >= 0) && (E1 < 1000)) {
        if ((E1 >= 0) && (E1 < 400)) {
            if ((E1 >= 0) && (E1 < 50)) EXP2 += 25;
            else if ((E1 >= 50) && (E1 < 100)) EXP2 += 50;
            else if ((E1 >= 100) && (E1 < 150)) EXP2 += 85;
            else if ((E1 >= 150) && (E1 < 200)) EXP2 += 75;
            else if ((E1 >= 200) && (E1 < 250)) EXP2 += 110;
            else if ((E1 >= 250) && (E1 < 300)) EXP2 += 135;
            else EXP2 += 160;
            if (E1 % 2 != 0) EXP1 = ceil(EXP1 + E1 / 10.0);
            else EXP1 = ceil(EXP1 - E1 / 5.0);
        }
        else {
            if ((E1 >= 400) && (E1 < 500)) EXP2 = ceil(EXP2 + E1 / 7.0 + 9);
            else if ((E1 >= 500) && (E1 < 600)) EXP2 = ceil(EXP2 + E1 / 9.0 + 11);
            else if ((E1 >= 600) && (E1 < 700)) EXP2 = ceil(EXP2 + E1 / 5.0 + 6);
            else if ((E1 >= 700) && (E1 < 800)) {
                EXP2 = ceil(EXP2 + E1 / 7.0 + 9);
                if (EXP2 > 200) EXP2 = ceil(EXP2 + E1 / 9.0 + 11);
            }
            else {
                EXP2 = ceil(EXP2 + E1 / 7.0 + 9 + E1 / 9.0 + 11);
                if (EXP2 > 600) {
                    EXP2 = ceil(EXP2 + E1 / 5.0 + 6);
                    EXP2 = ceil(EXP2 + EXP2 * 15.0 / 100);
                }
            }
            EXP1 = ceil(EXP1 - E1 / 10.0);
        }
        test1(EXP1, EXP2);
        return EXP1 + EXP2;
    }
    return -999;
}

int investigateScene(int& EXP1, int& EXP2, int& HP2, int& M2, const int& E2) {
    //Complete this function to gain point on task 2
    test2(EXP1, EXP2, HP2, M2);
    if ((E2 >= 0) && (E2 < 1000)) {
        if ((E2 >= 0) && (E2 < 300)) {
            float d = E2 / 9.0 + 10;
            EXP2 = ceil(EXP2 + d);
            EXP1 = ceil(EXP1 + d / 3.0);
        }
        else if ((E2 >= 300) && (E2 < 500)) {
            float d1 = E2 / 9.0 + 10;
            EXP2 = ceil(EXP2 + d1);
            EXP1 = ceil(EXP1 + d1 / 3.0);
            float d2 = 0.35 * E2;
            EXP2 = ceil(EXP2 + d2);
            EXP1 = ceil(EXP1 + d2 / 3.0);
        }
        else {
            float d1 = E2 / 9.0 + 10;
            EXP2 = ceil(EXP2 + d1);
            EXP1 = ceil(EXP1 + d1 / 3.0);
            float d2 = 0.35 * E2;
            EXP2 = ceil(EXP2 + d2);
            EXP1 = ceil(EXP1 + d2 / 3.0);
            float d3 = 0.17 * (d1 + d2);
            EXP2 = ceil(EXP2 + d3);
            EXP1 = ceil(EXP1 + d3 / 3.0);
        }
        HP2 = ceil(HP2 - pow(E2, 3) * 1.0 / pow(2, 23));
        if (E2 % 2 == 0) M2 = ceil(M2 + pow(E2, 2) / 50.0);
        test2(EXP1, EXP2, HP2, M2);
        return EXP2 + HP2 + M2 + EXP1;
    }
    return -999;
}

int traceLuggage(int& HP1, int& EXP1, int& M1, const int& E3){
    //Complete this function to gain point on task 3
    test3(HP1, EXP1, M1);
    if ((E3 >= 0) && (E3 < 1000)) {
        int P1[9] = { 1,3,5,7,9,11,13,15,17 };
        int k1=0;
        for (int i = 0; i < 9; i++) {
            P1[i] = (P1[i] + E3) % 26 + 65;
        }
        for (int i = 0; i < 9; i++)
        {
            if (P1[i] == 80) {
                k1 = i + 1;
                break;
            }
        }
        if (k1 != 0) {
            HP1 = HP1 - 80 * k1 * 2;
            EXP1 = EXP1 + (1000 - 80 * k1) % 101;
            M1 = ceil(M1 - (k1 * E3) / 9.0);
        }
        else M1 = ceil(M1 - (81 * E3) / 9.0);
        int P2[7] = { 2, 3, 5, 7, 11, 13, 17 };
        int s = 0, m = 0, k2=0;
        for (int i = 0; i < 7; i++) {
            P2[i] = (P2[i] + E3) % 26;
            s += P2[i];
        }
        m = ceil(s / 7.0);
        for (int i = 0; i < 7; i++) {
            P2[i] = (P2[i] + s + m) % 26 + 65;
        }
        for (int i = 0; i < 7; i++) {
            if (P2[i] == 80) {
                k2 = i + 1;
                break;
            }
        }
        if (k2 != 0) {
            HP1 = HP1 - 80 * k2 * 2;
            EXP1 = EXP1 + (1000 - 80 * k2) % 101;
            M1 = ceil(M1 - (k2 * E3) / 9.0);
        }
        else M1 = ceil(M1 - (49 * E3) / 9.0);
        int P3[20] = { 4,16,36,64,100,144,196,256,324,400,484,576,676,784,900,1024,1156,1296,1444,1600};
        int max = 0, k3=0;
        for (int i = 0; i < 20; i++) 
            P3[i] = (long int)(P3[i] + pow(E3, 2)) % 113;
 
        for (int i = 0; i < 20; i++)
            if (P3[i] > max) max = P3[i];
        for (int i = 19; i >= 0; i--) {
            P3[i] = (long int) (ceil(((P3[i] + E3)*1.0) / max)) % 26 + 65;
        }
        for (int i = 19; i >= 0; i--) {
            if (P3[i] == 80) {
                k3 = 20 - i;
                break;
            }
        }
        if (k3 != 0) {
            HP1 = HP1 - 80 * k3 * 3;
            EXP1 = EXP1 + (3500 - 80 * k3) % 300;
            M1 = ceil(M1 - (k3 * E3) / 9.0);
        }
        else M1 = ceil(M1 - (400 * E3) / 9.0);
        int P4[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
        for (int i = 0; i < 12; i++) {
            P4[i] = (long int)(P4[i] + (pow(ceil(E3 / 29.0), 3))) % 9;
        }
        int min = P4[0], min_idx = 1, k4 = 0;
        for (int i = 0; i < 12; i++) {
            if (P4[i] < min) {
                min = P4[i];
                min_idx = i + 1;
            }
        } 
        for (int i = 11; i >= 0; i--) {
            P4[i] = (long int)((P4[i] + E3) * ceil(min *1.0/ min_idx)) % 26 + 65;
        }
        for (int i = 11; i >= 0; i--) {
            if (P4[i] == 80) {
                k4 = 12 - i;
                break;
            }
        }
        if (k4 != 0) {
            HP1 = HP1 - 80 * k4 * 4;
            EXP1 = EXP1+(4500 - 80 * k4) % 400;
            M1 = ceil(M1 - (k4 * E3) / 9.0);
        }
        else M1 = ceil(M1 - (144 * E3) / 9.0);
        if ((k1 == 0) && (k2 == 0) && (k3 == 0) && (k4 == 0)) {
            HP1 = HP1 - (59 * E3) % 900;
            EXP1 = EXP1 - (79 * E3) % 300;
            test3(HP1, EXP1, M1);
            return -1;
        }
        else {
            test3(HP1, EXP1, M1);
            return HP1 + EXP1 + M1;
        }
    }
    return -999;
}

////////////////////////////////////////////////
///END OF STUDENT'S ANSWER
////////////////////////////////////////////////
#endif /* studyInPink_h */
