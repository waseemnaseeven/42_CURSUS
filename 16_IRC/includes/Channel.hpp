#ifndef CHANNEL_HPP
#define CHANNEL_HPP

#include "../includes/Server.hpp"
#include "../includes/User.hpp"

class Server;
class User;

class Channel {
	private:
		string _name;
		string _topic;
		string _password; // optional
		vector<User*> _users;
		vector<User*> _operators;

	public:
		Channel();
		~Channel();
		Channel(const Channel& src);
		Channel& operator=(const Channel& src);


	/* ********** GETTERS ********** */
	string get_name() const;
	string get_topic() const;
	string get_password() const;
	vector<User> get_users() const;
	vector<User> get_operators() const;

	/* ********** SETTERS ********** */
	void set_name(const string& name);
	void set_topic(const string& topic);
	void set_password(const string& password);
	void set_users(const vector<User>& users);
	void set_operators(const vector<User>& operators);

	/* ********** CHANNEL METHODS ********** */
	void add_user(User user);
	void remove_user(User user);
	void add_operator(User user);
	void remove_operator(User user);

};

#endif // CHANNEL_HPP
