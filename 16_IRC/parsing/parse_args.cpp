#include "../includes/IRC.hpp"

bool valid_pwd(const string& pwd)
{
    if (pwd.empty() || pwd.size() < 1)
        return false;
    return true;
}

bool valid_port(const string& port)
{
    if (port.empty())
        return false;
    int p = atoi(port.c_str());

    return (p >= 1024 && p <= 49151);
}

bool parsing(string& port, string& pwd)
{
	if (!valid_port(port) || !valid_pwd(pwd))
		return false;
	return true;
}

