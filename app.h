#pragma once
#include <cstdio>
#include <cstring>
#include "Member.h"

using namespace std;

#define MAX_STRING 32

class AppInfo {
private:
    char* memNum;
    char* company;
    char* ssn;
    char* job;
    char* num;
    char* date;
public:
    AppInfo();
    AppInfo(char* memNum, char* company, char* ssn, char* job, char* num, char* date);
    char* getMemNum();
    char* getCompany();
    char* getSsn();
    char* getJob();
    char* getNum();
    char* getDate();
};


class ShowApp {
public:
    AppInfo* showCompanyApps(AppInfo* appInfo, int& appInfoIndex, CmMem& curMem);
};

class ShowAppUI {
public:
    void startInterface(FILE* out_fp);
    void showMyApps(FILE* out_fp, AppInfo* appInfo, int& appInfoIndex, CmMem& curMem, ShowApp& showApp);
    void displayApps(FILE* out_fp, int& appInfoIndex, AppInfo* appInfo);
};

class CancelApplyInfo {
public:
    void cancelApplyInfo(FILE* out_fp, AppInfo* appInfo, int& appInfoIndex, CmMem& curMem, char* ssn);
};

class CancelApplyInfoUI {
public:
    void startInterface(FILE* out_fp);
    void cancelApplyInfo(FILE* in_fp, FILE* out_fp, AppInfo* appInfo, int& appInfoIndex, CmMem& curMem, CancelApplyInfo& cancelApplyInfo);
};

void showApps(FILE* out_fp, AppInfo* appInfo, int& appInfoIndex, CmMem& curMem);
void cancelApp(FILE* in_fp, FILE* out_fp, AppInfo* appInfo, int& appInfoIndex, CmMem& curMem);
