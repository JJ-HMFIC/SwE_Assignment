#ifndef MEMBER_H
#define MEMBER_H

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

enum MemberType {
    CpMem = 1,
    CmMem
};

class Mem {
private:
    //string memberID;
    //string memberPW;

    struct MemberInfo {
        string num;
        string name;
        string password;
    };

    unordered_map<string, MemberInfo> members; // 회사이름 or 개인이름 / 구조체(번호,id,pw)
    string currentUser;

public:
    //Mem(string id, string pwd) :memberID(id), memberPW(pwd) {};

    //virtual void showInfo() = 0; // 순수 가상 함수

    void registerMember(MemberType type);
    void removeMember(string id);
    bool login(string id, string password);
    void logout();
};

/*class CpMem : public Mem {
private:
    string companyName; // 회사 이름
    string companyNum; // 사업자 번호 

public:
    CpMem(string id, string pwd, string name, string number)
        :Mem(id, pwd), companyName(name), companyNum(number) {};

    //void showInfo();
};

class CmMem : public Mem {
private:
    string memberName;
    string memberNum; // 주민 번호 

public:
    CmMem(string id, string pwd, string memberName, string number)
        :Mem(id, pwd), memberName(memberName), memberNum(number) {};

    //void showInfo();
};*/

#endif  // MEMBERSHIP_H
