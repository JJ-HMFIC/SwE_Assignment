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

    unordered_map<string, MemberInfo> members; // ȸ���̸� or �����̸� / ����ü(��ȣ,id,pw)
    string currentUser;

public:
    //Mem(string id, string pwd) :memberID(id), memberPW(pwd) {};

    //virtual void showInfo() = 0; // ���� ���� �Լ�

    void registerMember(MemberType type);
    void removeMember(string id);
    bool login(string id, string password);
    void logout();
};

/*class CpMem : public Mem {
private:
    string companyName; // ȸ�� �̸�
    string companyNum; // ����� ��ȣ 

public:
    CpMem(string id, string pwd, string name, string number)
        :Mem(id, pwd), companyName(name), companyNum(number) {};

    //void showInfo();
};

class CmMem : public Mem {
private:
    string memberName;
    string memberNum; // �ֹ� ��ȣ 

public:
    CmMem(string id, string pwd, string memberName, string number)
        :Mem(id, pwd), memberName(memberName), memberNum(number) {};

    //void showInfo();
};*/

#endif  // MEMBERSHIP_H
