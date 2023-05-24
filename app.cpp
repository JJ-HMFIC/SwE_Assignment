#include "app.h"

using namespace std;

// CmMem
// CmMem::CmMem(char* company) {
//     this->company = company;
// }

// char* CmMem::getCompany() {
//     return company;
// }

// AppInfo
AppInfo::AppInfo() {
    this->company = (char*)"";
    this->job = (char*)"";
    this->num = 0;
    this->date = (char*)"";
}

AppInfo::AppInfo(char* company, char* job, int num, char* date) {
    this->company = company;
    this->job = job;
    this->num = num;
    this->date = date;
}

char* AppInfo::getCompany() {
    return company;
}

char* AppInfo::getJob() {
    return job;
}

int AppInfo::getNum() {
    return num;
}

char* AppInfo::getDate() {
    return date;
}

// AddApp
AppInfo AddApp::addNewApp(char* company, char* job, int num, char* date) {
    return AppInfo(company, job, num, date);
}

// AddAppUI
void AddAppUI::startInterface(FILE* out_fp) {
    fprintf(out_fp, "4.1. aldifhalifh\n");
}

AppInfo AddAppUI::createNewApp(FILE* in_fp, FILE* out_fp, CmMem curMem, AddApp& addApp) {
    char* company = new char[MAX_STRING];
    char* job = new char[MAX_STRING];
    char* date = new char[MAX_STRING];
    int num;

    fscanf(in_fp, "%s %s %d %s", company, job, &num, date);
    fprintf(out_fp, "> %s %s %d %s\n", company, job, num, date);
    return addApp.addNewApp(company, job, num, date);
}

// ShowApp
AppInfo* ShowApp::showCompanyApps(AppInfo* appInfo, int& appInfoIndex, CmMem& curMem) {
    char* company = curMem.getName();
    AppInfo* myAppInfo = new AppInfo[appInfoIndex];

    for (int i = 0; i < appInfoIndex; i++) {
        if (strcmp(appInfo[i].getCompany(), company) == 0) {
            myAppInfo[i] = appInfo[i];
        }
    }
    return myAppInfo;
}

// ShowAppUI
void ShowAppUI::startInterface(FILE* out_fp) {
    fprintf(out_fp, "4.2. asdfsadsfdf\n");
}

void ShowAppUI::showMyApps(FILE* out_fp, AppInfo* appInfo, int& appInfoIndex, CmMem& curMem, ShowApp& showApp) {
    AppInfo* appInfoArray = showApp.showCompanyApps(appInfo, appInfoIndex, curMem);
    displayApps(out_fp, appInfoIndex, appInfoArray);
}

void ShowAppUI::displayApps(FILE* out_fp, int& appInfoIndex, AppInfo* appInfo) {
    for (int i = 0; i < appInfoIndex; i++) {
        if (appInfo[i].getCompany()[0] == '\0') {
            break;
        }
        fprintf(out_fp, "> %s %s %d %s\n", appInfo[i].getCompany(), appInfo[i].getJob(), appInfo[i].getNum(), appInfo[i].getDate());
    }
}
