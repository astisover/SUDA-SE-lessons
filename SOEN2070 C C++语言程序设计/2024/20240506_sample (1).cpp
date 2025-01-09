
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


double func1(const vector<int>& vec_number)
{
    return 0;
}


struct Fee
{
    int number;      // the number of words
    bool isSuccess;  // the flag of sending state, true: successed, false: failed
};
double func2(const vector<struct Fee>& vec_info)
{

}

struct PatientInfo
{
    string name;     // the patient's name
    double temp;     // the patient's temperature
    bool   isCough;  // the status of cough, true: cough, false: Do not cough
};
int func3(const vector<struct PatientInfo>& vec_patients)
{
    return 0;
}

//----------------------------------------
//param:
//  const vector<struct PatientInfo>& vec_patients: the all patients' information
//  vector<struct PatientInfo>& vec_IdentifyingPatients: the indentifying patients' information
//return: void
//----------------------------------------
void func4(const vector<struct PatientInfo>& vec_patients, vector<struct PatientInfo>& vec_IdentifyingPatients)
{

}


int func5(const vector<int>& v1, const vector<int>& v2)
{

}

//----------------------------------------
//param:
//  const string& sentence: the sendtence
//  const string& word: the word
//  int& index: the start index of first word in sentence
//return: the number of word in sentence
//----------------------------------------
int func6(const string& sentence, const string& word, int& index)
{

   return 0;
}

int func7(const vector<int>& v1)
{

}

void func8(const vector<vector<int>>& matrix, vector<vector<int>>& newMatrix)
{

}

void func9(const vector<vector<int>>& matrix, vector<vector<int>>& newMatrix)
{
    
}

void func10(const vector<vector<int>>& matrix, vector<vector<int>>& newMatrix)
{
    
}

void func11(const vector<vector<int>>& matrix, vector<vector<int>>& newMatrix)
{
    
}

void func12(int n, vector<vector<int>>& primePair)
{
    
}