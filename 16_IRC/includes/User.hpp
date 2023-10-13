#ifndef USER_HPP
#define USER_HPP

#include "../includes/Server.hpp"

using namespace std;

class Server;
class Channel;

class User {
	private:
		string _username;
		string _nickname;
		string _messages;
		int _fd;
		int _id;
		bool _isOperator;
		bool _isAuthentified;
		bool _hasNickname;
		bool _hasUsername;

		// t_serv *server;

	public:
		User();
		User(int fd, int id);
		~User();
		User(const User& src);
		User& operator=(const User& src);
	public:
		/* ********** GETTERS ********** */
		string get_username() const;
		string get_nickname() const;
		int get_fd() const;
		int get_id() const;
		string get_messages() const;
		bool get_isOperator() const;
		bool get_isAuthentified() const;
		bool get_hasNickname() const;
		bool get_hasUsername() const;

		/* ********** SETTERS ********** */
		void set_username(const string& username);
		void set_nickname(const string& nickname);
		void set_fd(int fd);
		void set_id(int id);
		void set_messages(const string& messages);
		void set_isOperator(bool isOperator);
		void set_isAuthentified(bool isAuthentified);
		void set_hasNickname(bool hasNickname);
		void set_hasUsername(bool hasUsername);

		/* ********** USER METHODS ********** */
		void send_message(const string& message);
		void receive_message(const string& message);

};

#endif // USER_HPP
