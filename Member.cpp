#include "Member.h"

using namespace std;

Mem::Mem(char *id, char *pw)
{
    memID = id;
    memPW = pw;
}
Mem::Mem()
{
    memID = (char *)"";
    memPW = (char *)"";
}
char *Mem::getPW()
{
    return memPW;
}
char *Mem::getID()
{
    return memID;
}

void registerCpMem(char *id, char *pw, char *name, char *number)
{
    CpMem *cpMem = new CpMem(id, pw, name, number);
}
void registerCmMem(char *id, char *pw, char *name, char *number)
{
    CmMem *cmMem = new CmMem(id, pw, name, number);
}

CpMem::CpMem(char *id, char *pwd, char *name, char *number)
    : Mem(id, pwd), cpName(name), cpNum(number){};

CpMem::CpMem()
{
    cpName = (char *)"";
    cpNum = (char *)"";
}

char *CpMem::getName()
{
    return cpName;
}

char *CpMem::getNum()
{
    return cpNum;
}

CmMem::CmMem(char *id, char *pwd, char *name, char *number)
    : Mem(id, pwd), cmName(name), cmNum(number){};

CmMem::CmMem()
{
    cmName = (char *)"";
    cmNum = (char *)"";
}

char *CmMem::getName()
{
    return cmName;
}

//  SignIn

void signIn(int type, FILE *in_fp, FILE *out_fp, CpMem *cpMems, CmMem *cmMems, int &cpMemIndex, int &cmMemIndex)
{
    SignInUI signinui;
    SignIn signinClass;

    signinui.startInterface(out_fp);
    signinui.requestSignIn(type, in_fp, out_fp, signinClass, cpMems, cmMems, cpMemIndex, cmMemIndex);
}

void SignInUI::startInterface(FILE *out_fp)
{
    fprintf(out_fp, "1.1. 회원 가입\n");
}

void SignInUI::requestSignIn(int type, FILE *in_fp, FILE *out_fp, SignIn &signinClass, CpMem *cpMems, CmMem *cmMems, int &cpMemIndex, int &cmMemIndex)
{

    char *name = new char[MAX_STRING];
    char *num = new char[MAX_STRING];
    char *ID = new char[MAX_STRING];
    char *PW = new char[MAX_STRING];

    fscanf(in_fp, "%s %s %s %s", name, num, ID, PW);
    fprintf(out_fp, "> %d %s %s %s %s\n", type, name, num, ID, PW);
    signinClass.signin(type, ID, PW, name, num, cpMems, cmMems, cpMemIndex, cmMemIndex);
}

void SignIn::signin(int num, char *id, char *pwd, char *name, char *number, CpMem *cpMems, CmMem *cmMems, int &cpMemIndex, int &cmMemIndex)
{
    if (num == 1)
        cpMems[cpMemIndex++] = addCpMem(id, pwd, name, number);
    else
        cmMems[cmMemIndex++] = addCmMem(id, pwd, name, number);
}
CpMem SignIn::addCpMem(char *id, char *pwd, char *name, char *number)
{
    return CpMem(id, pwd, name, number);
}
CmMem SignIn::addCmMem(char *id, char *pwd, char *name, char *number)
{
    return CmMem(id, pwd, name, number);
}


void login(FILE *in_fp, FILE *out_fp, CpMem *cpMems, CmMem *cmMems, CpMem &curCpMem, CmMem &curCmMem, int &cpMemIndex, int &cmMemIndex)
{
    LoginUI loginui;
    Login loginClass;

    loginui.startInterface(out_fp);
    return loginui.requestLogin(in_fp, out_fp, loginClass, cpMems, cmMems, curCpMem, curCmMem, cpMemIndex, cmMemIndex);
}

void LoginUI::startInterface(FILE *out_fp)
{
    fprintf(out_fp, "2.1. 로그인 \n");
}

void LoginUI::requestLogin(FILE *in_fp, FILE *out_fp, Login login, CpMem *cpMems, CmMem *cmMems, CpMem &curCpMem, CmMem &curCmMem, int &cpMemIndex, int &cmMemIndex)
{
    char *ID = new char[MAX_STRING];
    char *PW = new char[MAX_STRING];
    fscanf(in_fp, "%s %s\n", ID, PW);
    login.login(ID, PW, out_fp, cpMems, cmMems, curCpMem, curCmMem, cpMemIndex, cmMemIndex);
}

void Login::login(char *id, char *pwd, FILE *out_fp, CpMem *cpMems, CmMem *cmMems, CpMem &curCpMem, CmMem &curCmMem, int &cpMemIndex, int &cmMemIndex) // 수정 필요
{
    for (int i = 0; i < cpMemIndex; i++)
    {
        if (cpMems[i].login(id, pwd))
        {
            fprintf(out_fp, "> %s %s\n", id, pwd);
            curCpMem = cpMems[i];
            return;
        }
    }
    for (int i = 0; i < cmMemIndex; i++)
    {
        if (cmMems[i].login(id, pwd))
        {
            fprintf(out_fp, "> %s %s\n", id, pwd);
            curCmMem = cmMems[i];
            return;
        }
    }
}
bool Mem::login(char *id, char *pwd)
{
    if (strcmp(id, memID) == 0 && strcmp(pwd, memPW) == 0)

    {
        return true;
    }
    else
        return false;
}


void logout(FILE *out_fp, CpMem &curCpMem, CmMem &curCmMem)
{
    LogoutUI logoutui;

    logoutui.startInterface(out_fp);
    logoutui.requestLogout(out_fp, curCpMem, curCmMem);
}

void LogoutUI::startInterface(FILE *out_fp)
{
    fprintf(out_fp, "2.2.로그아웃 \n");
}
void LogoutUI::requestLogout(FILE *out_fp, CpMem &curCpMem, CmMem &curCmMem)
{
    char *id;
    if (curCpMem.getName()[0] != '\0')
    {
        id = curCpMem.getID();
        curCpMem = CpMem();
    }
    else
    {
        id = curCmMem.getID();
        curCmMem = CmMem();
    }
    fprintf(out_fp, "> %s\n", id);
    Logout();
}
Logout::Logout()
{
    Mem::logout();
}
void Mem::logout()
{
}


void DropUI::startInterface(FILE *out_fp)
{
    fprintf(out_fp, "1.2. 회원탈퇴 \n");
}
void DropUI::requestDrop(FILE *out_fp, Mem curMem)
{
    fprintf(out_fp, "> %s", curMem.getID());
    Drop::deleteUser();
}
void Drop::deleteUser()
{
}
