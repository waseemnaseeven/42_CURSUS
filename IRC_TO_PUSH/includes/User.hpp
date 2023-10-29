#ifndef USER_HPP
#define USER_HPP

#include "../includes/Server.hpp"

using namespace std;

class Server;
class Channel;

class User {
	private:
		string _username;
		string _realname;
		string _nickname;
		string _messages;
		int _fd;
		bool _isOperator;
		bool _isAuthentified;
		bool _hasNickname;
		bool _hasUsername;
		bool _hasPassword;

		vector<Channel *> _channels;

	public:
		User();
		User(int fd);
		~User();
		User(const User& src);
		User& operator=(const User& src);

	public:
		/* ********** GETTERS ********** */
		string get_username() const;
		string get_nickname() const;
		string get_realname() const;
		int get_fd() const;
		string get_messages() const;
		bool get_isOperator() const;
		bool get_isAuthentified() const;
		bool get_hasNickname() const;
		bool get_hasUsername() const;
		bool get_hasPassword() const;
		Channel *get_channel(const string& channel_name) const;

		/* ********** SETTERS ********** */
		void set_username(const string& username);
		void set_nickname(string nickname);
		void set_realname(const string& realname);
		void set_fd(int fd);
		void set_messages(const string& messages);
		void set_isOperator(bool isOperator);
		void set_isAuthentified(bool isAuthentified);
		void set_hasNickname(bool hasNickname);
		void set_hasUsername(bool hasUsername);
		void set_hasPassword(bool hasPassword);

		/* ********** USER METHODS ********** */
		void add_channel(Channel *channel);
		bool remove_channel(const string& channel_name);
		vector<pair<string, string> > splitBuffer(const string& buffer);

};

#endif // USER_HPP
