#include <iostream>
#include <string>
#include <unordered_map>
#include "Member.h"
using namespace std;


class MembershipSystem {
private:
    struct MemberInfo {
        string name;
        string id;
        string password;
    };

    unordered_map<string, MemberInfo> members;
    string currentUser;

public:
    void registerMember(MemberType type) {
        MemberInfo member;

        if (type == CpMem) {
            cout << "Company Registration" << endl;
            cout << "Enter company name: ";
            getline(cin, member.name);
            cout << "Enter business registration number: ";
            getline(cin, member.id);
        }
        else {
            cout << "General Registration" << endl;
            cout << "Enter name: ";
            getline(cin, member.name);
            cout << "Enter resident registration number: ";
            getline(cin, member.id);
        }

        cout << "Enter password: ";
        getline(cin, member.password);

        members[member.id] = member;

        cout << "Registration successful!" << endl;
    }

    void removeMember(string id) {
        if (members.find(id) != members.end()) {
            members.erase(id);

            if (currentUser == id) {
                currentUser = "";
            }

            cout << "Member removed." << endl;
        }
        else {
            cout << "Member not found." << endl;
        }
    }

    bool login(string id, string password) {
        if (members.find(id) != members.end() && members[id].password == password) {
            currentUser = id;
            cout << "Login successful!" << endl;
            return true;
        }
        else {
            cout << "Invalid ID or password. Please try again." << endl;
            return false;
        }
    }

    void logout() {
        currentUser = "";
        cout << "Logged out." << endl;
    }
};

int main() {
    MembershipSystem system;
    int typeChoice;

    // È¸¿ø °¡ÀÔ
    cout << "Membership Registration" << endl;
    cout << "Select member type: " << endl;
    cout << "1. General" << endl;
    cout << "2. Company" << endl;
    cout << "Enter your choice: ";
    cin >> typeChoice;
    cin.ignore();

    if (typeChoice == 1) {
        system.registerMember(CmMem);
    }
    else if (typeChoice == 2) {
        system.registerMember(CpMem);
    }
    else {
        cout << "Invalid choice." << endl;
        return 0;
    }

    // ·Î±×ÀÎ
    string id, password;
    cout << "Membership Login" << endl;
    cout << "Enter ID: ";
    getline(cin, id);
    cout << "Enter password: ";
    getline(cin, password);

    system.login(id, password);

    // ·Î±×¾Æ¿ô
    system.logout();

    // È¸¿ø Å»Åð
    cout << "Membership Withdrawal" << endl;
    cout << "Enter ID: ";
    getline(cin, id);

    system.removeMember(id);

    return 0;
}
