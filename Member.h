#ifndef MEMBER_H
#define MEMBER_H

#include <iostream>
#include <string>

#include <cstdio>
#include <cstring>
using namespace std;

#define MAX_STRING 32
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

string user = "";

class Mem {
private:
    
    char* memID;
    char* memPW;

public:
    Mem(char* id, char* pwd);
    char* getPW();
    char* getID();
    bool login(char* id, char* pwd);
    static void logout();
   
};

class CpMem : public Mem {
private:
    char* cpName; // 회사 이름
    char* cpNum; // 사업자 번호 

public:
    CpMem(char* id, char* pwd, char* name, char* number);

};

class CmMem : public Mem {
private:
    char* cmName;
    char* cmNum; // 주민 번호 

public:
    CmMem(char* id, char* pwd, char* name, char* number);

};
void registerCpMem(char* id, char* pw, char* name, char* number);
void registerCmMem(char* id, char* pw, char* name, char* number);
//----------------------------------------------------------------------
class SignInUI
{
public:
    void startInterface(FILE* out_fp);
    void requestSignIn(FILE* in_fp, FILE* out_fp); // 입력 받음 
};
class SignIn
{
public:
    SignIn(int num, char* id, char* pwd, char* name, char* number);
    void addCpMem(char* id, char* pwd, char* name, char* number);
    void addCmMem(char* id, char* pwd, char* name, char* number);

};
//-------------------------------------------------------------------
class LoginUI
{
public:
    void startInterface(FILE* out_fp);
    void requestLogin(FILE* in_fp, FILE* out_fp);
};
class Login    
{
private:
    Mem mem;
public:
    Login(char* id, char* pwd, FILE* out_fp);
};
//-------------------------------------------------------------------
class LogoutUI
{
public:
    void startInterface(FILE* out_fp);
    void requestLogout(FILE* out_fp);
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
    void requestDrop(FILE* out_fp);
};


class Drop
{
public:
  static void deleteUser();
};


#endif  
