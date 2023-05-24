#pragma once
#include <cstdio>
#include <cstring>
#include "Member.h"

using namespace std;

#define MAX_STRING 32

class AppInfo {
private:
    char* company;
    char* job;
    int num;
    char* date;
public:
    AppInfo();
    AppInfo(char* company, char* job, int num, char* date);
    char* getCompany();
    char* getJob();
    int getNum();
    char* getDate();
};

// class CmMem {
// private:
//     char* company;
// public:
//     CmMem(char* company);
//     char* getCompany();
// };

class AddApp {
public:
    AppInfo addNewApp(char* company, char* job, int num, char* date);
};

class AddAppUI {
public:
    void startInterface(FILE* out_fp);
    AppInfo createNewApp(FILE* in_fp, FILE* out_fp, CmMem curMem, AddApp& addApp);
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

AppInfo addApp(FILE* in_fp, FILE* out_fp, AppInfo* appInfo, int& appInfoIndex, CmMem& curMem);
void showApps(FILE* out_fp, AppInfo* appInfo, int& appInfoIndex, CmMem& curMem);
