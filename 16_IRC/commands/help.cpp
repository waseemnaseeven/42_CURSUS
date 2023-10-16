#include "../includes/Server.hpp"

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

