#ifndef MEMBER_H
#define MEMBER_H

#include <string>

#include <cstdio>
#include <cstring>
using namespace std;

#define MAX_STRING 32
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"


class Mem {
private:
    
    char* memID;
    char* memPW;

public:
    Mem();
    Mem(char* id, char* pwd);
    char* getPW();
    char* getID();
    bool login(char* id, char* pwd);
    static void logout();
};

class CpMem : public Mem {
private:
    char* cpName;
    char* cpNum;

public:
    CpMem();
    CpMem(char* id, char* pwd, char* name, char* number);
    char *getName();
    char *getNum();
};

class CmMem : public Mem {
private:
    char* cmName;
    char* cmNum;

public:
    CmMem();
    CmMem(char* id, char* pwd, char* name, char* number);
    char *getName();
};
void registerCpMem(char* id, char* pw, char* name, char* number);
void registerCmMem(char* id, char* pw, char* name, char* number);


void signIn(int type, FILE* in_fp, FILE* out_fp, CpMem* cpMems, CmMem* cmMems, int& cpMemIndex, int& cmMemIndex);

class SignIn
{
public:
    void signin(int num, char *id, char *pwd, char *name, char *number, CpMem *cpMems, CmMem *cmMems, int &cpMemIndex, int &cmMemIndex);
    CpMem addCpMem(char* id, char* pwd, char* name, char* number);
    CmMem addCmMem(char* id, char* pwd, char* name, char* number);

};

class SignInUI
{
public:
    void startInterface(FILE* out_fp);
    void requestSignIn(int type, FILE *in_fp, FILE *out_fp, SignIn &signinClass, CpMem *cpMems, CmMem *cmMems, int &cpMemIndex, int &cmMemIndex); // 입력 받음 
};
//-------------------------------------------------------------------

void login(FILE *in_fp, FILE *out_fp, CpMem *cpMems, CmMem *cmMems, CpMem &curCpMem, CmMem &curCmMem, int &cpMemIndex, int &cmMemIndex);


class Login    
{
public:
    void login(char *id, char *pwd, FILE *out_fp, CpMem *cpMems, CmMem *cmMems, CpMem &curCpMem, CmMem &curCmMem, int &cpMemIndex, int &cmMemIndex);
};
class LoginUI
{
public:
    void startInterface(FILE* out_fp);
    void requestLogin(FILE *in_fp, FILE *out_fp, Login login, CpMem *cpMems, CmMem *cmMems, CpMem &curCpMem, CmMem &curCmMem, int &cpMemIndex, int &cmMemIndex);
};
//-------------------------------------------------------------------

void logout(FILE *out_fp, CpMem &curCpMem, CmMem &curCmMem);

class LogoutUI
{
public:
    void startInterface(FILE* out_fp);
    void requestLogout(FILE* out_fp, CpMem &curCpMem, CmMem &curCmMem);
};
class Logout
{
public:
    Logout();
};
//---------------------------------------------------------------------
class DropUI
{
public:
    void startInterface(FILE* out_fp);
    void requestDrop(FILE* out_fp, Mem curMem);
};


class Drop
{
public:
  static void deleteUser();
};


#endif  
