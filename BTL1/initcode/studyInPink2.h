/*
* Ho Chi Minh City University of Technology
* Faculty of Computer Science and Engineering
* Initial code for Assignment 1
* Programming Fundamentals Spring 2022
* Author: Vu Van Tien
* Date: 10.02.2022
*/

//The library here is concretely set, students are not allowed to include any other libraries.
#ifndef studyInPink_h
#define studyInPink_h

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

////////////////////////////////////////////////////////////////////////
///STUDENT'S ANSWER BEGINS HERE
///Complete the following functions
///DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////

string notebook1(string ntb1) {
    // Complete this function to gain point
    ifstream file1(ntb1);
    string d1;
    int d2[100000];
    file1 >> d1;
    if (d1[11] >= 48 && d1[11] <= 57 && d1[12] >= 48 && d1[12] <= 57 && d1[13] >= 48 && d1[13] <= 57) {
        int n1 = (int(d1[11])-48) * 100 + (int(d1[12])-48) * 10 + int(d1[13])-48;
        int i = 0;
        while (!file1.eof()) {
            file1 >> d2[i];
            i++;
        }
        if (i < n1 || n1 < 1 || n1>999) {
            file1.close();
            return "0000000000";
        }
        string d3="0000000000";
        for (int j = 0; j < n1; j++) {
            if (d2[j] == 0) {
                d3[0]++;
                if (d3[0] == ':') d3[0] -= 10;
            }
            if (d2[j] == 1) {
                d3[1]++;
                if (d3[1] == ':') d3[1] -= 10;
            }
            if (d2[j] == 2) {
                d3[2]++;
                if (d3[2] == ':') d3[2] -= 10;
            }
            if (d2[j] == 3) {
                d3[3]++;
                if (d3[3] == ':') d3[3] -= 10;
            }
            if (d2[j] == 4) {
                d3[4]++;
                if (d3[4] == ':') d3[4] -= 10;
            }
            if (d2[j] == 5) {
                d3[5]++;
                if (d3[5] == ':') d3[5] -= 10;
            }
            if (d2[j] == 6) {
                d3[6]++;
                if (d3[6] == ':') d3[6] -= 10;
            }
            if (d2[j] == 7) {
                d3[7]++;
                if (d3[7] == ':') d3[7] -= 10;
            }
            if (d2[j] == 8) {
                d3[8]++;
                if (d3[8] == ':') d3[8] -= 10;
            }
            if (d2[j] == 9) {
                d3[9]++;
                if (d3[9] == ':') d3[9] -= 10;
            }
        }
        file1.close();
        return d3;
    }
    file1.close();
    return "0000000000";
}

string notebook2(string ntb2) {
    // Complete this function to gain point
    ifstream file2(ntb2);
    string d1;
    file2 >> d1;
    if (d1.length() == 5 && d1[0] >= 48 && d1[0] <= 57 && d1[1] >= 48 && d1[1] <= 57 && d1[2] >= 48 && d1[2] <= 57 && d1[3] >= 48 && d1[3] <= 57 && d1[4] >= 48 && d1[4] <= 57) {
        int n2 = (int(d1[0]) - 48) * 10000 + (int(d1[1]) - 48) * 1000 + (int(d1[2]) - 48)*100+ (int(d1[3]) - 48) * 10+ int(d1[4]) - 48;
        if (n2 < 5 || n2>100) {
            file2.close();
            return "1111111111";
        }
        int i = 0;
        int cntP = 0;
        string d2[10000];
        while (!file2.eof()) {
            file2 >> d2[i];
            i++;
        }
        string pink = "pink";
        string Pink = "Pink";
        for (int j = 0; j < i; j++) {
            int m = 0;
            int n = 0;
            int l = d2[j].length();
            while (m < l) {
                if (d2[j][m] == pink[n]) {
                    n++;
                    if (pink[n] == '\0') {
                        m = m - 2;
                        n = 0;
                        cntP++;
                    }
                }
                m++;
            }
        }
        for (int j = 0; j < i; j++) {
            int m = 0;
            int n = 0;
            int l = d2[j].length();
            while (m < l) {
                if (d2[j][m] == Pink[n]) {
                    n++;
                    if (Pink[n] == '\0') {
                        m = m - 2;
                        n = 0;
                        cntP++;
                    }
                }
                m++;
            }
        }
        if (cntP < 10000) cntP = cntP * cntP;
        if (cntP < 10) cntP = cntP * 1000000000 + 999999999;
        else if (cntP < 100) cntP = cntP * 100000000 + 99999999;
        else if (cntP < 1000) cntP = cntP * 10000000 + 9999999;
        else if (cntP < 10000) cntP = cntP * 1000000 + 999999;
        else if (cntP < 100000) cntP = cntP * 100000 + 99999;
        else if (cntP < 1000000) cntP = cntP * 10000 + 9999;
        else if (cntP < 10000000) cntP = cntP * 1000 + 999;
        else if (cntP < 100000000) cntP = cntP * 100 + 99;
        else if (cntP < 1000000000) cntP = cntP * 10 + 9;
        else cntP = cntP;
        string cntP1="";
        cntP1=to_string(cntP);
        return cntP1;
    }
    file2.close();
    return "1111111111";
}
bool ktsnt(int a) {
    int count = 0;
    if (a >= 2) {
        for (int i = 1; i < a; i++) {
            if (a % i == 0) count++;
        }
        if (count == 1) return 1;
    }
    return 0;
}
int sfb(int n)
{
    if (n == 1 || n == 0 || n == 2 || n == 3) return n;
    return sfb(n - 2) + sfb(n - 1);
}
bool ktsfb(int a) {
    int i=0;
    while (sfb(i) <= a) {
        if (sfb(i) == a) return 1;
        i++;
    }
    return 0;
}
string notebook3(string ntb3) {
    // Complete this function to gain point
    ifstream file3(ntb3);
    int arr[10][10];
    string temp;
    int i = 0;
    while (!file3.eof()) {
        int j = 0;
        getline(file3, temp);
        int end = 0;
        int len = 0;
        int start = 0;
        string sub;
        while (1) {
            end = temp.find('|');
            len = end - start;
            sub = temp.substr(start, len);
            arr[i][j] = stoi(sub)>0?stoi(sub):-stoi(sub);
            //cout << arr[i][j] << " ";
            temp = temp.substr(end + 1, temp.length() - len - 1);
            j++;
            if (j == 10) break;
        }
        //cout << endl;
        i++;
    }
    for (int i = 0; i < 9; i++) {
        if (!ktsnt(arr[i][i + 1])) {
            while (1) {
                arr[i][i + 1]++;
                if (ktsnt(arr[i][i + 1])) break;
            }
        }
    }
    
    for (int i = 1; i <= 9; i++) {
        if (!ktsfb(!arr[i][i - 1])) {
            while (1) {
                arr[i][i - 1]++;
                if (ktsfb(arr[i][i - 1])) break;
            }
        }
    }
    
    for (int i = 0; i < 10; i++) {
        for (int j = 7; j < 10; j++) {
            for (int k = j + 1; k < 10; k++) {
                if (arr[i][j] > arr[i][k]) {
                    int temp = arr[i][j];
                    arr[i][j] = arr[i][k];
                    arr[i][k] = temp;
                }
            
            }
        }
    }

    double kq=0;
    for (int i = 0; i < 10; i++) {
        int max = arr[i][0];
        int maxid = 0;
        for (int j = 0; j < 10; j++) {
            if (arr[i][j] >= max) {
                max = arr[i][j];
                maxid = j;
                
            }
        }
        kq = kq * 10 + maxid;
    }
    string kq1="";
    kq1 = to_string(kq);
    kq1 = kq1.substr(0, 10);
    file3.close();
    return kq1;
}
string g(string p1, string p2) {
    string p="0000000000";
    int du = 0;
    for (int i = 0; i < 10; i++) {
        int a;
        //cout << (int)p1[i]-48 + (int)p2[i] -48<< endl;
        a = (int)p1[i]-48+(int)p2[i]-48 + du;
        if (a > 9) {
            du = 1;
            a = a - 10;
        }
        else du = 0;
        p[i] =(char)a+48;
    }
    return p;
}
string generateListPasswords(string pwd1, string pwd2, string pwd3) {
    // Complete this function to gain point
    string kq[18];
    string kq1 = "";
    kq[0] = pwd1;
    kq[1] = ';';
    kq[2] = pwd2;
    kq[3] = ';';
    kq[4] = pwd3;
    kq[5] = ';';
    kq[6] = g(pwd1, pwd2);
    kq[7] = ';';
    kq[8] = g(pwd1, pwd3);
    kq[9] = ';';
    kq[10] = g(pwd2, pwd3);
    kq[11] = ';';
    kq[12] = g(g(pwd1, pwd2), pwd3);
    kq[13] = ';';
    kq[14] = g(pwd1, g(pwd2, pwd3));
    kq[15] = ';';
    kq[16] = g(g(pwd1, pwd2), g(pwd1, pwd3));
    kq[17] = '\0';
    for (int i = 0; i < 17; i++) {
        kq1 = kq1 + kq[i];
    }
    return kq1;
}

bool chaseTaxi(
    int arr[100][100],
    string points,
    string moves,
    string & outTimes,
    string & outCatchUps
) {
    // Complete this function to gain point
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            arr[i][j] = -9;
        }
    }
    arr[0][0] = 0;
    int a = 0, b = 0;
    for (int i = 0; i < moves.length(); i++) {
        if (moves[i] == 'U' && a > 0) {
            arr[a - 1][b] = arr[a][b] + 9;
            a--;
        }
        else if (moves[i] == 'D' && a < 99) {
            arr[a + 1][b] = arr[a][b] + 9;
            a++;
        }
        else if (moves[i] == 'L' && b > 0) {
            arr[a][b - 1] = arr[a][b] + 9;
            b--;
        }
        else if (moves[i] == 'R' && b < 99) {
            arr[a][b + 1] = arr[a][b] + 9;
            b++;
        }
        else continue;
    }
    /*for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << arr[i][j]<<" ";
        }
        cout << endl;
    }*/
    string point[10000];
    int i = 0;
    int end = 0;
    int len = 0;
    int start = 0;
    int count = 0;
    for (int j = 0; j < points.length(); j++) {
        if (points[j] == ',') count++;
    }
    while (1) {
        end = points.find('-');
        len = end - start;
        point[i] = points.substr(start, len);
        points = points.substr(end + 1, points.length() - len - 1);
        i++;
        if (i==count) break;
    }
    int p[100000];
    int m = 0;
    for (int j = 0; j < i; j++) {
        //cout << point[j] << endl;

        for (int k = 0; k < point[j].length(); k++) {
            if (point[j][k] == ',') {
                p[m] = stoi(point[j].substr(1, k - 1));
                p[m + 1] =stoi( point[j].substr(k + 1, point[j].length() - k -2));
                m += 2;
            }
        }

    }
    int x[10000];
    int y[10000];
    int z = 0;
    int t = 0;
    for (int n = 0; n < m; n++) {
        //cout << p[n]<<endl;
        if (n % 2 == 0) {
            x[z] = p[n];
            z++;
        }
        else if (n % 2 != 0) {
            y[t] = p[n];
            t++;
        }
    }
    
    int time[10000];
    time[0] = (x[0] + y[0])*14;
    int sl = 1;
    for (int k = 0; k < z-1; k++) {
        //cout << x[k] << y[k] << endl;
        time[k + 1] = time[k]+(abs(x[k] - x[k + 1]) + abs(y[k] - y[k + 1])) * 14;
        sl++;
    }
    bool check=0;
    for (int h = 0; h < sl; h++) {
        /*cout << time[h] << endl;
        cout << arr[1][1] << endl;*/
        if (time[h] <= arr[x[h]][y[h]] && arr[x[h]][y[h]] != -9) {
            if (h == sl - 1) {
                outTimes = outTimes + to_string(time[h]);
                outCatchUps = outCatchUps + "Y";
            }
            else {
                outTimes = outTimes + to_string(time[h]) + ";";
                outCatchUps = outCatchUps + "Y;";
            }
            check = 1;
            continue;
            
        }
        if (check == 0) {
            if (h == sl - 1) {
                outTimes = outTimes + to_string(time[h]);
                outCatchUps = outCatchUps + "N";
            }
            else {
                outTimes = outTimes + to_string(time[h]) + ";";
                outCatchUps = outCatchUps + "N;";
            }
        }
        else {
            if (h == sl - 1) {
                outTimes = outTimes + "-";
                outCatchUps = outCatchUps + "-";
            }
            else {
                outTimes = outTimes + "-;";
                outCatchUps = outCatchUps + "-;";
            }
        }
    }
    /*outTimes[outTimes.length() - 1] = '\0';
    outCatchUps[outCatchUps.length() - 1] = '\0';
    outTimes[outTimes.length()-2] = '\0';
    outCatchUps[outCatchUps.length()-2] = '\0';*/
    /*cout << outTimes << endl;
    cout << outCatchUps << endl;*/
    for (int h = 0; h < sl; h++) {
        /*cout << time[h] << endl;
        cout << arr[1][1] << endl;*/
        if (time[h] <= arr[x[h]][y[h]] && arr[x[h]][y[h]] != -9) {
            return true;
        }
    }
    
    return false;
}

string enterLaptop(string tag, string message) {
    // Complete this function to gain point
    ifstream file4(tag);
    string tieude1;
    file4 >> tieude1;
    string email;
    file4 >> email;
    string tieude2;
    file4 >> tieude2;
    string n3;
    file4 >> n3;
    int n33;
    n33 = stoi(n3);
    /*cout << tieude1 << endl;
    cout << tieude2 << endl;
    cout <<email << endl;
    cout << n3 << endl;
    cout << n33 << endl;*/
    string pwdL;
    for (int i = 0; i < n33; i++) {
        pwdL = pwdL + message;
    }
    string enter;
    enter = enter + email + ";" + pwdL;
    file4.close();
    return enter;
}

////////////////////////////////////////////////
///END OF STUDENT'S ANSWER
////////////////////////////////////////////////
#endif /* studyInPink_h */
