#include "stat.h"

using namespace std;

void stat(FILE *out_fp, CpMem &cpMem, CmMem &cmMem, AppInfo *appInfo, int &appInfoIndex, EmpInfo *empInfo, int &empInfoIndex)
{
    ApplyPrintUI applyPrintUI = ApplyPrintUI();
    ApplyPrint applyPrint = ApplyPrint();
    EmpPrintUI empPrintUI = EmpPrintUI();
    EmpPrint empPrint = EmpPrint();

    if (strcmp(cpMem.getID(), "") == 0)
    {
        applyPrintUI.startInterface(out_fp);
        applyPrintUI.requestStatics(out_fp, appInfo, appInfoIndex, cmMem);
    }
    else
    {
        empPrintUI.startInterface(out_fp);
        empPrintUI.requestStatics(out_fp, empInfo, empInfoIndex, cpMem);
    }
}

void ApplyPrintUI::startInterface(FILE *out_fp)
{
    fprintf(out_fp, "5.1. 지원 정보 통계\n");
}

void ApplyPrintUI::requestStatics(FILE *out_fp, AppInfo *appInfo, int &appInfoIndex, CmMem &curMem)
{
    ApplyPrint applyPrint = ApplyPrint();
    AppInfo *appInfoArray;

    appInfoArray = applyPrint.showStatics(appInfo, appInfoIndex);
    printStatics(out_fp, appInfoArray, appInfoIndex);
}

void ApplyPrintUI::printStatics(FILE *out_fp, AppInfo *appInfo, int &appInfoIndex)
{
    for (int i = 0; i < appInfoIndex; i++)
    {
        if (appInfo[i].getJob() == NULL)
        {
            continue;
        }
        fprintf(out_fp, "> %s 1\n", appInfo[i].getJob());
    }
}

AppInfo *ApplyPrint::showStatics(AppInfo *appInfo, int &appInfoIndex)
{
    AppInfo *appInfoArray = new AppInfo[appInfoIndex];

    for (int i = 0; i < appInfoIndex; i++)
    {
        if (appInfo[i].getJob() == NULL)
        {
            continue;
        }
        appInfoArray[i] = appInfo[i];
    }

    return appInfoArray;
}

void EmpPrintUI::startInterface(FILE *out_fp)
{
    fprintf(out_fp, "5.1. 지원 정보 통계\n");
}

void EmpPrintUI::requestStatics(FILE *out_fp, EmpInfo *empInfo, int &empInfoIndex, CpMem &curMem)
{
    EmpPrint empPrint = EmpPrint();
    EmpInfo *empInfoArray;

    empInfoArray = empPrint.showStatics(empInfo, empInfoIndex, curMem);
    printStatics(out_fp, empInfoArray, empInfoIndex);
}

void EmpPrintUI::printStatics(FILE *out_fp, EmpInfo *empInfo, int &empInfoIndex)
{
    for (int i = 0; i < empInfoIndex; i++)
    {
        if (empInfo[i].getJob() == NULL)
        {
            continue;
        }
        fprintf(out_fp, "> %s %s\n", empInfo[i].getJob(), empInfo[i].getNum());
    }
}

EmpInfo *EmpPrint::showStatics(EmpInfo *empInfo, int &empInfoIndex, CpMem &curMem)
{
    char *cpName = curMem.getName();
    EmpInfo *empInfoArray = new EmpInfo[empInfoIndex];

    for (int i = 0; i < empInfoIndex; i++)
    {
        if (strcmp(empInfo[i].getCpName(), cpName) == 0)
        {
            empInfoArray[i] = empInfo[i];
        }
    }
    return empInfoArray;
}
