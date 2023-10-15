#include "../includes/Server.hpp"

void Hello_IRC(t_serv *server)
{
	string welcome = welcome_msg();
	send(server->new_fd, welcome.c_str(), welcome.size(), 0);
}

string  welcome_msg()
{
    std::string welcome = BOLDMAGENTA;
	welcome.append("██╗    ██╗███████╗██╗      ██████╗ ██████╗ ███╗   ███╗███████╗\r\n");
	welcome.append("██║    ██║██╔════╝██║     ██╔════╝██╔═══██╗████╗ ████║██╔════╝\r\n");
	welcome.append("██║ █╗ ██║█████╗  ██║     ██║     ██║   ██║██╔████╔██║█████╗\r\n");
	welcome.append("██║███╗██║██╔══╝  ██║     ██║     ██║   ██║██║╚██╔╝██║██╔══╝\r\n");
	welcome.append("╚███╔███╔╝███████╗███████╗╚██████╗╚██████╔╝██║ ╚═╝ ██║███████╗\r\n");
	welcome.append(" ╚══╝╚══╝ ╚══════╝╚══════╝ ╚═════╝ ╚═════╝ ╚═╝     ╚═╝╚══════╝\r\n");
	welcome.append("\r\n");
    welcome.append(BOLDBLUE);
	welcome.append("You need to login so you can start chatting\r\n");
	welcome.append(RESET);
    return (welcome);
}

string    printHelpInfo()
{
    string help;

    help.append("STEP 1: PASS\r\n");
    help.append("Use PASS command to set a password. e.g: PASS [server passwd]\r\n\n");
    help.append("STEP 2 : USER\r\n");
    help.append("Use USER command to set a username. e.g: USER [your login]\r\n\n");
    help.append("STEP 3 : NICK\r\n");
    help.append("Use NICK command to set a nickname. e.g: NICK [your nickname]\r\n\n");
    return help;
}
