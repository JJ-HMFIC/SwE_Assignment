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
        cout << "ȸ�� ȸ������ ȸ�������մϴ�." << endl;
        cout << "ȸ�� �̸��� �Է����ּ��� : ";
        getline(cin, member.name);
        cout << "����� ��ȣ�� �Է����ּ��� : ";
        getline(cin, member.num);
    }
    else
    {
        cout << "���� ȸ������ ȸ�������մϴ�." << endl;
        cout << "�̸��� �Է����ּ��� : ";
        getline(cin, member.name);
        cout << "�ֹ� ��ȣ�� �Է����ּ��� : ";
        getline(cin, member.num);

    }
    cout << "����ϰ��� �ϴ� ID�� �Է����ּ��� : ";
    getline(cin, id);
    while (check)
    {
        if (members.find(id) != members.end())
        {
            cout << "�ش� ���̵�� �̹� ������Դϴ�.\n �ٸ� ���̵� �Է����ּ���." << endl;
            cout << "����ϰ��� �ϴ� ID�� �Է����ּ��� : ";
            getline(cin, id);
        }
        else
        {
            cout << "�ش� ���̵�� ��� �����մϴ�." << endl;
            check = false;
        }
    }

    cout << "����ϰ��� �ϴ� ��й�ȣ�� �Է����ּ��� :  ";
    getline(cin, member.password);

    members[id] = member;

    cout << "���������� ȸ������ �Ǿ����ϴ�." << endl;
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

        cout << "ȸ�� Ż��Ǿ����ϴ�." << endl;
    }
    else 
    {
        cout << "ȸ�� ������ ã�� �� �����ϴ�." << endl;
    }
}
bool Mem::login(string id, string password)
{
    
    if (members.find(id) != members.end() && members[id].password == password)
    {
        currentUser = id;
        cout << "���������� �α��εǾ����ϴ�." << endl;
        return true;
    }
    else 
    {
        cout << "���̵�� ��й�ȣ�� ��ġ���� �ʽ��ϴ�.\n �ٽ� �õ��� �ּ���" << endl;
        return false;
    }
}
void Mem::logout()
{
    currentUser = "";
    cout << "�α׾ƿ� �Ǿ����ϴ�." << endl;
}