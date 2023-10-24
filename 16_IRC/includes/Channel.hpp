#ifndef CHANNEL_HPP
#define CHANNEL_HPP

#include "../includes/Server.hpp"
#include "../includes/User.hpp"

using namespace std;

class User;

class Channel {
	private:
		string		_channel_name;
		int			_fd_creator;
		string		_topic;
		string		_key_channel; // mdp du channel
		int			_max_channels; // maximum channels users can join
		vector<int>	_fds_users;
		vector<int>	_fds_operators;
		vector<int>	_fds_invited;
		vector<int>	_fds_kicked;
		bool 		_is_invite_only;
		bool 		_is_topic_set;
		int			_max_users; // max users in channel
		bool		_has_user_limit;

	public:
		Channel();
		Channel(string name, int fd);
		~Channel();
		Channel(const Channel& src);
		Channel& operator=(const Channel& src);


	/* ********** GETTERS ********** */
	string 	get_channel_name() const;
	string 	get_topic() const;
	string 	get_key_channel() const;
	int 	get_max_channels() const;
	vector<int>	get_users() const;
	vector<int>	get_operators() const;
	bool	get_is_invite_only() const;
	bool	get_is_topic_set() const;
	int		get_max_users() const;
	bool	get_has_user_limit() const;

	/* ********** SETTERS ********** */
	void	set_channel_name(string name);
	void	set_topic(const string& topic);
	void	unset_topic();
	void	set_key_channel(const string& key_channel);
	void	set_max_channels(int max_channels);
	void	set_invite_only(bool mode);
	void	set_max_users(int max_users);
	void	set_has_user_limit(bool mode);

	/* ********** CHANNEL METHODS ********** */
	bool	is_user(int fd_user);
	bool	is_op(int fd_user);
	bool	is_invited(int fd_user);
	void	broadcast(string message, int fd_emitter);
	void	add_user(int fd_user);
	void	kick_user(int fd_user);
	void	part(int fd_user);
};

#endif // CHANNEL_HPP
