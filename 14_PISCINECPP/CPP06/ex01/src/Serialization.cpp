#include "includes/Serialization.hpp"

uintptr_t Serializer::serialize(Data* ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
    return reinterpret_cast<Data*>(raw);
}

void	draw_tab(Data* deseria, Data* ptr, bool flag)
{
	std::cout << "****************************************" << std::endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 8; j++) {
            if (j == 0) {
                if (i == 0 && j == 0)
					std::cout << "\tData: " << ptr << " ";
                else if (i == 1)
					std::cout << "\tDeseria: " << deseria << " ";
                else if (i == 2) {
                    std::cout << "\tStatus: ";
                    if (flag)
                        std::cout << BOLDGREEN << "Success ✅ " << RESET;
                    else
                        std::cout << BOLDRED << "Failed ❌ " << RESET;
                }
            }
        }
        std::cout << std::endl;
    }
    std::cout << "****************************************" << std::endl;
}
