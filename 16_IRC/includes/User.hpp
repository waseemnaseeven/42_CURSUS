#ifndef USER_HPP
#define USER_HPP

#include "includes/Server.hpp"

class User {
	private:
		string _username;
		string _nickname;
		string _ip; // ?
		string _messages;
		bool isOperator;
		
	public:
		User();
		~User();
		User(const User& src);
		User& operator=(const User& src);
	
	/* ********** GETTERS ********** */
	string get_username() const;
	string get_nickname() const;
	string get_ip() const;
	string get_messages() const;
	
	/* ********** SETTERS ********** */
	void set_username(const string& username);
	void set_nickname(const string& nickname);
	void set_ip(const string& ip);
	void set_messages(const string& messages);

	/* ********** USER METHODS ********** */
	void send_message(const string& message);
	void receive_message(const string& message);

};

#endif // USER_HPP
