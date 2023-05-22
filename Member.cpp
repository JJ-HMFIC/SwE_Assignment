#include "Member.h"
using namespace std;

Mem::Mem(char* id, char* pw)
{
    memID = id;
    memPW = pw;
}
char* Mem::getPW()
{
    return memPW;
}
char* Mem::getID()
{
    return memID;
}

void registerCpMem(char* id, char*pw, char* name, char*number)
{
    CpMem* cpMem = new CpMem(id, pw, name, number);
}
void registerCmMem(char* id, char* pw, char* name, char* number)
{
    CmMem* cmMem = new CmMem(id, pw, name, number);
}

CpMem::CpMem(char* id, char* pwd, char* name, char* number)
    : Mem(id, pwd), cpName(name), cpNum(number) {};

CmMem::CmMem(char* id, char* pwd, char* name, char* number)
    :Mem(id, pwd), cmName(name), cmNum(number) {};


void SignInUI::startInterface(FILE* out_fp)
{
    fprintf(out_fp, "1.1. 회원 가입\n");
} // 처음 시작 

void SignInUI::requestSignIn(FILE* in_fp, FILE* out_fp)
{

    int type;
    char* name = new char[MAX_STRING];
    char* num = new char[MAX_STRING];
    char* ID = new char[MAX_STRING];
    char* PW = new char[MAX_STRING];
    
    fscanf(in_fp, "%d %s %s %s %s",  &type, name, num, ID, PW); // 읽기 
    fprintf(out_fp, "> %d %s %s %s %s", type, name, num, ID, PW); 
    SignIn(type, ID ,PW, name, num);
         
}

SignIn::SignIn(int num, char* id, char* pwd, char* name, char* number)
{
    if (num == 1)
        addCpMem(id, pwd, name, number);
    else
        addCmMem(id, pwd, name, number);

}
void SignIn::addCpMem(char* id, char* pwd, char* name, char* number)
{
     CpMem(id, pwd, name, number);
}
void SignIn::addCmMem(char* id, char* pwd, char* name, char* number)
{
     CmMem(id, pwd, name, number);
}
//-------------------------------------------------------------------
void LoginUI::startInterface(FILE* out_fp)
{
    fprintf(out_fp, "2.1. 로그인 \n");
} // 처음 시작
void LoginUI::requestLogin(FILE* in_fp, FILE* out_fp)
{
    char* ID = new char[MAX_STRING];
    char* PW = new char[MAX_STRING];
    fscanf(in_fp, "%s %s", ID, PW); 
   //fprintf(out_fp, ">%s %s",ID, PW); // 틀렸을 때 감안해서 위치 변경 가능 
    Login(ID,PW,out_fp);

}

Login::Login(char* id, char* pwd, FILE* out_fp) // 수정 필요 
{
    
    if (mem.login(id, pwd))
        fprintf(out_fp, "> %s %s", id, pwd);

}
bool Mem::login(char* id, char* pwd)
{
    if (strcmp(id, memID) == 0 && strcmp(pwd, memPW) == 0)

    {
        user = id;
        return true;
    }
    else
        return false;
}
//-------------------------------------------------------------------
void LogoutUI::startInterface(FILE* out_fp)
{
    fprintf(out_fp, "2.2.로그아웃 \n");
}
void LogoutUI::requestLogout(FILE* out_fp)
{
    fprintf(out_fp, "> %s", user);
    Logout();
}
Logout::Logout()
{
    Mem::logout();
}
void Mem::logout()
{
    user = "";
}
//------------------------------------------------------------------
void DropUI::startInterface(FILE* out_fp)
{
    fprintf(out_fp, "1.2. 회원탈퇴 \n");
}
void DropUI::requestDrop(FILE* out_fp)
{
    fprintf(out_fp, "> %s", user);
    Drop::deleteUser();
}
void Drop::deleteUser()
{
    // 소멸자 써야하는데 how? 
}
