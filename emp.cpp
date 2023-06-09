#include "emp.h"

using namespace std;


EmpInfo::EmpInfo(){
    this->cpName = (char *)"";
    this->ssn = (char *)"";
    this->job = (char *)"";
    this->num = (char *)"";
    this->date = (char *)"";
}

EmpInfo::EmpInfo(char *cpName, char *ssn, char *job, char *num, char *date) {
    this->cpName = cpName;
    this->ssn = ssn;
    this->job = job;
    this->num = num;
    this->date = date;
}

char *EmpInfo::getCpName() {
    return cpName;
}

char *EmpInfo::getSsn() {
    return ssn;
}

char *EmpInfo::getJob() {
    return job;
}

char *EmpInfo::getNum() {
    return num;
}

char *EmpInfo::getDate() {
    return date;
}


//


void addEmp(FILE *in_fp, FILE *out_fp, EmpInfo *empInfo, int &empInfoIndex, CpMem &curMem) {
    AddEmpUI addEmpUI = AddEmpUI();
    AddEmp addEmp = AddEmp();
    EmpInfo newEmp;

    addEmpUI.startInterface(out_fp);
    empInfo[empInfoIndex++] = addEmpUI.createNewEmp(in_fp, out_fp, curMem, addEmp);
}

void showEmps(FILE *out_fp, EmpInfo *empInfo, int &empInfoIndex, CpMem &curMem) {
    ShowEmpUI showEmpUI = ShowEmpUI();
    ShowEmp showEmp = ShowEmp();

    showEmpUI.startInterface(out_fp);
    showEmpUI.showMyEmps(out_fp, empInfo, empInfoIndex, curMem, showEmp);
}

void AddEmpUI::startInterface(FILE *out_fp) {
    fprintf(out_fp, "3.1. 채용 정보 등록\n");
}

EmpInfo AddEmpUI::createNewEmp(FILE *in_fp, FILE *out_fp, CpMem curMem, AddEmp &addEmp) {
    char *cpName = curMem.getName();
    char *ssn = curMem.getNum();
    char *job = new char[MAX_STRING];
    char *date = new char[MAX_STRING];
    char *num = new char[MAX_STRING];

    fscanf(in_fp, "%s %s %s", job, num, date);
    fprintf(out_fp, "> %s %s %s\n", job, num, date);
    return addEmp.addNewEmp(cpName, ssn, job, num, date);
}

EmpInfo AddEmp::addNewEmp(char *cpName, char *ssn, char *job, char *num, char *date) {
    return EmpInfo(cpName, ssn, job, num, date);
}

void ShowEmpUI::startInterface(FILE *out_fp) {
    fprintf(out_fp, "3.2. 등록된 채용 정보 조회\n");
}


void ShowEmpUI::showMyEmps(FILE *out_fp, EmpInfo *empInfo, int &empInfoIndex, CpMem &curMem, ShowEmp &showEmp)
{
    EmpInfo *empInfoArray;

    empInfoArray = showEmp.showCompanyEmps(empInfo, empInfoIndex, curMem);
    displayEmps(out_fp, empInfoIndex, empInfoArray);
}

EmpInfo *ShowEmp::showCompanyEmps(EmpInfo *empInfo, int &empInfoIndex, CpMem &curMem) {
    char *cpName = curMem.getName();
    EmpInfo *myEmpInfo = new EmpInfo[empInfoIndex];

    for (int i = 0; i < empInfoIndex; i++) {
        if (strcmp(empInfo[i].getCpName(), cpName) == 0) {
            myEmpInfo[i] = empInfo[i];
        }
    }
    return myEmpInfo;
}

void ShowEmpUI::displayEmps(FILE *out_fp, int &empInfoIndex, EmpInfo *empInfo) {
    for (int i = 0; i < empInfoIndex; i++) {
        if (empInfo[i].getCpName()[0] == '\0') {
            continue;
        }
        fprintf(out_fp, "> %s %s %s\n", empInfo[i].getJob(), empInfo[i].getNum(), empInfo[i].getDate());
    }
}
