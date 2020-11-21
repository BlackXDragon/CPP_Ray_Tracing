#include "../color.h"
#include "iostream"

int main() {
	std::cout << "Black: " << Color() << std::endl;
	std::cout << "White: " << Color(255, 255, 255) << std::endl;
	std::cout << "Blue: " << Color(0, 0, 255) << std::endl;
	std::cout << "Black (hex): " << Color("#000000") << std::endl;
	std::cout << "White (hex): " << Color("#FFFFFF") << std::endl;
	std::cout << "Blue (hex): " << Color("#0000FF") << std::endl;
	return 0;
}