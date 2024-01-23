#include <iostream>
#include <locale.h>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

void ortbul(float nots[], float notlar, float credit) {
    cout << "WHAT IS PASS GRADE FOR THIS COURSE?" << endl;
  
    float gecmenot;
    cin >> gecmenot;
    float genelort = 0;
    for (int i = 0; i < notlar; i++) {
        genelort = genelort + nots[i];
    }
    float genel = genelort/credit;
    cout << "GPA:" << genel << endl;
    cout << "Grade: " << genelort << endl;
    
    if (genelort >= gecmenot) {
        cout << "PASS." << endl;
    }
    else {
        cout << "FAIL" << endl;
    }
}

void getname(string name) {
    cout << "Grades for " << name << " course" << endl;
}

int main() {
    setlocale(LC_ALL, "Turkish");
    cout << "***WELCOME TO GPA CALCULATOR***" << endl;
    cout << "Input the course number: ";
    int dersSayisi;
    cin >> dersSayisi;

    string* dersAdlari = new string[dersSayisi];
    vector<string> secilenDersAdlari;

    for (int i = 0; i < dersSayisi; ++i) {
        cout << i + 1 << "-" << "Course Name: ";
        cin >> dersAdlari[i];
    }

    cout << "**COURSE NAMES**\n";
    for (int i = 0; i < dersSayisi; ++i) {
        cout << i + 1 << "-" << dersAdlari[i] << endl;
    }

    srand(static_cast<unsigned int>(time(0)));

    for (int i = 0; i < dersSayisi; i++) {
        int randomDersIndex;
        do {
            randomDersIndex = rand() % dersSayisi;
        } while (find(secilenDersAdlari.begin(), secilenDersAdlari.end(), dersAdlari[randomDersIndex]) != secilenDersAdlari.end());

        secilenDersAdlari.push_back(dersAdlari[randomDersIndex]);
        getname(dersAdlari[randomDersIndex]);

        cout << "How many different grade you will input ? (QUIZ, MIDTERM, FINAL, ATTENDANCE..) : ";
        float notlar;
        cin >> notlar;
        float credit;
        cout << "Input the credit number of this course." << endl;
        cin >> credit;
        float* notsayi = new float[notlar];

        cout << "Input the grades:" << endl;
        for (int j = 0; j < notlar; j++) {
            cout << j + 1 << ". Grade:  ";
            cin >> notsayi[j];
            cout << "IF THIS GRADE HAS TO BE WEIGHTED, INPUT THE WEIGHT(as %).IF ALL HAVE SAME WEIGHT, INPUT 0." << endl;
            float weight;
            cin >> weight;
            notsayi[j] = notsayi[j] * (weight/100);  
        }
        ortbul(notsayi, notlar, credit);
        delete[] notsayi;
    }
   
    delete[] dersAdlari;
   
    return 0;
}
