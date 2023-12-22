c++ -std=c++98 -Wall -Wextra -Werror *.cpp
valgrind --leak-check=full ./a.out
# ./a.out
rm a.out