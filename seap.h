#pragma once
#include "emp.h"
#include "Member.h"
#include "app.h"

using namespace std;

#define MAX_STRING 32
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

class ViewEmployUI {
public:
	void searchEmploy(FILE* in_fp, FILE* out_fp, EmpInfo* empInfo, int& empInfoIndex);
};

class ViewEmploy {
public:
	void showEmploy(FILE* in_fp, FILE* out_fp, int& empInfoIndex, const char* cname, EmpInfo* myEmpInfo);
};




class ApplyEmploy {
public:
	AppInfo addNewMember(char* cmpname, char* task, char* ssn, char* num, char* date, CmMem &curMem);
};

class ApplyEmployUI {
public:
	AppInfo selectApply(FILE* in_fp, FILE* out_fp, EmpInfo* empInfo, ApplyEmploy& applyEmp, int& empInfoIndex, int& applyInfoIndex, CmMem &curMem);
};


void viewEmp(FILE* in_fp, FILE* out_fp, EmpInfo* empInfo, int& empInfoIndex);
AppInfo applyEmp(FILE* in_fp, FILE* out_fp, EmpInfo* empInfo, int& empInfoIndex, int& applyInfoIndex, CmMem &curMem);
