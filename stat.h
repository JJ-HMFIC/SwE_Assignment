#pragma once
#include "Member.h"
#include "emp.h"
#include "app.h"


void stat(FILE *out_fp, CpMem &cpMem, CmMem &cmMEm, AppInfo *appInfo, int &appInfoIndex, EmpInfo *empInfo, int &empInfoIndex);


class ApplyPrintUI {
    public:
        void startInterface(FILE *out_fp);
        void requestStatics(FILE *out_fp, AppInfo *appInfo, int &appInfoIndex, CmMem &curMem);
        void printStatics(FILE *out_fp, AppInfo *appInfo, int &appInfoIndex);
};

class ApplyPrint {
    public:
        AppInfo *showStatics(AppInfo *appInfo, int &appInfoIndex);
};

class EmpPrintUI {
    public:
        void startInterface(FILE *out_fp);
        void requestStatics(FILE *out_fp, EmpInfo *empInfo, int &empInfoIndex, CpMem &curMem);
        void printStatics(FILE *out_fp, EmpInfo *empInfo, int &empInfoIndex);
};

class EmpPrint {
    public:
        EmpInfo *showStatics(EmpInfo *empInfo, int &empInfoIndex, CpMem &curMem);
};
