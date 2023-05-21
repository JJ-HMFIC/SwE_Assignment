#include <iostream>
#include <string>
#include <unordered_map>
#include "Member.h"
using namespace std;


void Mem::registerMember(MemberType type) 
{
    MemberInfo member;
    string id;
    bool check = true;
    if (type == CpMem) 
    {
        cout << "회사 회원으로 회원가입합니다." << endl;
        cout << "회사 이름을 입력해주세요 : ";
        getline(cin, member.name);
        cout << "사업자 번호를 입력해주세요 : ";
        getline(cin, member.num);
    }
    else
    {
        cout << "개인 회원으로 회원가입합니다." << endl;
        cout << "이름를 입력해주세요 : ";
        getline(cin, member.name);
        cout << "주민 번호를 입력해주세요 : ";
        getline(cin, member.num);

    }
    cout << "사용하고자 하는 ID를 입력해주세요 : ";
    getline(cin, id);
    while (check)
    {
        if (members.find(id) != members.end())
        {
            cout << "해당 아이디는 이미 사용중입니다.\n 다른 아이디를 입력해주세요." << endl;
            cout << "사용하고자 하는 ID를 입력해주세요 : ";
            getline(cin, id);
        }
        else
        {
            cout << "해당 아이디는 사용 가능합니다." << endl;
            check = false;
        }
    }

    cout << "사용하고자 하는 비밀번호를 입력해주세요 :  ";
    getline(cin, member.password);

    members[id] = member;

    cout << "성공적으로 회원가입 되었습니다." << endl;
}
void Mem::removeMember(string id)
{
    if (members.find(id) != members.end()) 
    {
        members.erase(id);

        if (currentUser == id)
        {
            currentUser = "";
        }

        cout << "회원 탈퇴되었습니다." << endl;
    }
    else 
    {
        cout << "회원 정보를 찾을 수 없습니다." << endl;
    }
}
bool Mem::login(string id, string password)
{
    
    if (members.find(id) != members.end() && members[id].password == password)
    {
        currentUser = id;
        cout << "성공적으로 로그인되었습니다." << endl;
        return true;
    }
    else 
    {
        cout << "아이디와 비밀번호가 일치하지 않습니다.\n 다시 시도해 주세요" << endl;
        return false;
    }
}
void Mem::logout()
{
    currentUser = "";
    cout << "로그아웃 되었습니다." << endl;
}