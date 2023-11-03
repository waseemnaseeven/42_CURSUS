#include "../includes/Server.hpp"

void    Hello_IRC(t_serv *server)
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
	welcome.append("You need to login so you can start chatting, type HELP for more info\r\n");
	welcome.append(RESET);
    return (welcome);
}