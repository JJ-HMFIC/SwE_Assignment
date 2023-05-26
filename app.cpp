#include "app.h"

using namespace std;

// AppInfo
AppInfo::AppInfo()
{
    this->memNum = (char *)"";
    this->company = (char *)"";
    this->ssn = (char *)"";
    this->job = (char *)"";
    this->num = (char *)"";
    this->date = (char *)"";
}

AppInfo::AppInfo(char *memNum, char *company, char *ssn, char *job, char *num, char *date)
{
    this->memNum = memNum;
    this->company = company;
    this->ssn = ssn;
    this->job = job;
    this->num = num;
    this->date = date;
}

char *AppInfo::getMemNum()
{
    return memNum;
}

char *AppInfo::getCompany()
{
    return company;
}

char *AppInfo::getSsn()
{
    return ssn;
}

char *AppInfo::getJob()
{
    return job;
}

char *AppInfo::getNum()
{
    return num;
}

char *AppInfo::getDate()
{
    return date;
}

// ShowApp
AppInfo *ShowApp::showCompanyApps(AppInfo *appInfo, int &appInfoIndex, CmMem &curMem)
{
    char *memID = curMem.getID();
    AppInfo *myAppInfo = new AppInfo[appInfoIndex];

    for (int i = 0; i < appInfoIndex; i++)
    {
        if (strcmp(appInfo[i].getMemNum(), memID) == 0)
        {
            myAppInfo[i] = appInfo[i];
        }
    }
    return myAppInfo;
}

// ShowAppUI
void ShowAppUI::startInterface(FILE *out_fp)
{
    fprintf(out_fp, "4.3. 지원 정보 조회\n");
}

void ShowAppUI::showMyApps(FILE *out_fp, AppInfo *appInfo, int &appInfoIndex, CmMem &curMem, ShowApp &showApp)
{
    AppInfo *appInfoArray = showApp.showCompanyApps(appInfo, appInfoIndex, curMem);
    displayApps(out_fp, appInfoIndex, appInfoArray);
}

void ShowAppUI::displayApps(FILE *out_fp, int &appInfoIndex, AppInfo *appInfo)
{
    for (int i = 0; i < appInfoIndex; i++)
    {
        if (appInfo[i].getCompany()[0] != '\0')
        {
            fprintf(out_fp, "> %s %s %s %s %s\n", appInfo[i].getCompany(), appInfo[i].getSsn(), appInfo[i].getJob(), appInfo[i].getNum(), appInfo[i].getDate());
        }
    }
}

void showApps(FILE* out_fp, AppInfo* appInfo, int& appInfoIndex, CmMem& curMem)
{
    ShowAppUI showAppUI = ShowAppUI();
    ShowApp showApp = ShowApp();

    showAppUI.startInterface(out_fp);
    showAppUI.showMyApps(out_fp, appInfo, appInfoIndex, curMem, showApp);
}

// cancel
void cancelApp(FILE *in_fp, FILE *out_fp, AppInfo *appInfo, int &appInfoIndex, CmMem &curMem)
{
    CancelApplyInfoUI cancelApplyInfoUI = CancelApplyInfoUI();
    CancelApplyInfo cancelApplyInfo = CancelApplyInfo();

    cancelApplyInfoUI.startInterface(out_fp);
    cancelApplyInfoUI.cancelApplyInfo(in_fp, out_fp, appInfo, appInfoIndex, curMem, cancelApplyInfo);
}

void CancelApplyInfoUI::startInterface(FILE *out_fp)
{
    fprintf(out_fp, "4.4. 지원 정보 취소\n");
}

void CancelApplyInfoUI::cancelApplyInfo(FILE *in_fp, FILE *out_fp, AppInfo *appInfo, int &appInfoIndex, CmMem &curMem, CancelApplyInfo &cancelApplyInfo)
{
    char *ssn = new char[MAX_STRING];
    fscanf(in_fp, "%s", ssn);

    cancelApplyInfo.cancelApplyInfo(out_fp, appInfo, appInfoIndex, curMem, ssn);
}

void CancelApplyInfo::cancelApplyInfo(FILE *out_fp, AppInfo *appInfo, int &appInfoIndex, CmMem &curMem, char *ssn)
{

    for (int i = 0; i < appInfoIndex; i++)
    {
        if (strcmp(appInfo[i].getSsn(), ssn) == 0)
        {
            fprintf(out_fp, "> %s %s %s\n", appInfo[i].getCompany(), appInfo[i].getSsn(), appInfo[i].getJob());
            appInfo[i] = AppInfo();
            break;
        }
    }
}
