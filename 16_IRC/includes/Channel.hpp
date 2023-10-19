#ifndef CHANNEL_HPP
#define CHANNEL_HPP

#include "../includes/Server.hpp"
#include "../includes/User.hpp"

using namespace std;

class User;

class Channel {
	private:
		string	_channel_name;
		int		_fd_creator;

		string	_topic;
		string	_key_channel; // mdp du channel
		int		_max_channels; // maximum channels users can join


	public:
		Channel();
		Channel(string name, int fd);
		~Channel();
		Channel(const Channel& src);
		Channel& operator=(const Channel& src);


	/* ********** GETTERS ********** */
	string get_channel_name() const;
	string get_topic() const;
	string get_key_channel() const;
	int get_max_channels() const;

	/* ********** SETTERS ********** */
	void set_channel_name(string name);
	void set_topic(const string& topic);
	void set_key_channel(const string& key_channel);
	void set_max_channels(int max_channels);

	/* ********** CHANNEL METHODS ********** */

};

#endif // CHANNEL_HPP
