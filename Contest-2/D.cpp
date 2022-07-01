#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

enum Code {
    REGISTER,
    LOGIN,
    LOGOUT,
};

Code convert(string inString)
{
    if (inString == "register") return REGISTER;
    if (inString == "login") return LOGIN;
    if (inString == "logout") return LOGOUT;
}

int main(void)
{
    map<string, string> data;
    set<string> logged;

    vector<string> logs;

    string command, login, password;
    while (cin >> command)
    {
        cin >> login;
        switch (convert(command)) {
            case REGISTER:
                cin >> password;
                if (data.count(login) == 0) {
                    data[login] = password;
                    logs.push_back("account created");
                }
                else {
                    logs.push_back("login already in use");
                }
                break;
            case LOGIN:
                cin >> password;
                if (data.count(login) == 0 || data[login] != password) {
                    logs.push_back("wrong account info");
                }
                else if (logged.count(login) != 0) {
                    logs.push_back("already logged in");
                }
                else {
                    logged.insert(login);
                    logs.push_back("logged in");
                }
                break;
            case LOGOUT:
                if (logged.count(login) == 0 || data.count(login) == 0) {
                    logs.push_back("incorrect operation");
                }
                else {
                    logged.erase(login);
                    logs.push_back("logged out");
                }
                break;
        }
    }

    for (int i = 0; i < logs.size(); i++)
        cout << logs[i] << endl;
}