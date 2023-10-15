#include "../includes/Server.hpp"

void gethostname(void)
{
    char hostname[128];
    gethostname(hostname, 128);
    cout << PURPLE << "Hostname: " << hostname << RESET << endl;
}
