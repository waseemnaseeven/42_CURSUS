#include "../includes/Server.hpp"

void getAuthentication(Server *Server_class, string buffer) {
    string info(buffer);
    string username, nickname, passwd;
    size_t passwdPos = info.find("PASS");
    size_t userPos = info.find("USER");
    size_t nickPos = info.find("NICK");
    User *tmp = new User();

    if (passwdPos != string::npos) {
        size_t passwdEnd = info.find('\n', passwdPos);
        if (passwdEnd != string::npos) {
            // Retirer les espaces après "PASS"
            passwd = info.substr(passwdPos + 4, passwdEnd - passwdPos - 5);
            passwd.erase(std::remove(passwd.begin(), passwd.end(), ' '), passwd.end());
            cout << "passwd: " << passwd << endl;
        }
    }

    cout << "server passwd:" << Server_class->get_passwd() << endl;
    if (Server_class->get_passwd() != passwd) {
        cout << "Wrong password" << endl;
		// user_disconnection(server);
        return ;
    }

    if (userPos != string::npos) {
        size_t userEnd = info.find('\n', userPos);
        if (userEnd != string::npos) {
            // Retirer les espaces après "USER"
            username = info.substr(userPos + 4, userEnd - userPos - 4);
            username.erase(std::remove(username.begin(), username.end(), ' '), username.end());
        }
    }

    if (nickPos != string::npos) {
        size_t nickEnd = info.find('\n', nickPos);
        if (nickEnd != string::npos) {
            // Retirer les espaces après "NICK"
            nickname = info.substr(nickPos + 4, nickEnd - nickPos - 4);
            nickname.erase(std::remove(nickname.begin(), nickname.end(), ' '), nickname.end());
        }
    }
    tmp->set_username(username);
    tmp->set_nickname(nickname);
}
