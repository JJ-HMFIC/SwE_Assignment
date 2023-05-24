#include <cstdio>
#include <cstring>
#include "Member.h"

using namespace std;


#define MAX_STRING 32
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

class EmpInfo {
    private:
        char *cpName;
        char *job;
        char *num;
        char *date;
    public:
        EmpInfo();
        EmpInfo(char *cpName, char *job, char *num, char *date);
        char *getCpName();
        char *getJob();
        char *getNum();
        char *getDate();
};


// 회사 회원

// class CpMem {
//     private:
//         char *company;
//     public:
//         CpMem(char *company);
//         char *getCompany();
// };

// 

class AddEmp {
    public:
        EmpInfo addNewEmp(char *company, char *job, char *num, char *date);
};


class AddEmpUI {
    public:
        void startInterface(FILE *out_fp);
        // EmpInfo createNewEmp(FILE *in_fp, FILE *out_fp, CpMem curMem, AddEmp &addEmp);
        EmpInfo createNewEmp(FILE *in_fp, FILE *out_fp, CpMem curMem, AddEmp &addEmp);
};

class ShowEmp {
    public:
        // EmpInfo *showCompanyEmps(EmpInfo *empInfo, int &empInfoIndex, CpMem &curMem);
        EmpInfo *showCompanyEmps(EmpInfo *empInfo, int &empInfoIndex, CpMem &curMem);
};

class ShowEmpUI {
    public:
        void startInterface(FILE *out_fp);
        // void showMyEmps(FILE *out_fp, EmpInfo *empInfo, int &empInfoIndex, CpMem &curMem, ShowEmp &showEmp);
        void showMyEmps(FILE *out_fp, EmpInfo *empInfo, int &empInfoIndex, CpMem &curMem, ShowEmp &showEmp);
        void displayEmps(FILE *out_fp, int &empInfoIndex, EmpInfo *empInfo);
};

// EmpInfo addEmp(FILE *in_fp, FILE *out_fp, EmpInfo *empInfo, int &empInfoIndex, CpMem &curMem);
EmpInfo addEmp(FILE *in_fp, FILE *out_fp, EmpInfo *empInfo, int &empInfoIndex, CpMem &curMem);

// void showEmps(FILE *out_fp, EmpInfo *empInfo, int &empInfoIndex, CpMem &curMem);
void showEmps(FILE *out_fp, EmpInfo *empInfo, int &empInfoIndex, CpMem &curMem);
