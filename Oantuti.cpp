#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int main() {
    srand(time(0));  // khởi tạo bộ sinh số ngẫu nhiên
    std::string choices[3] = {"Đá", "Giấy", "Kéo"};
    int computer_choice = rand() % 3; // máy tính chọn một trong ba lựa chọn

    std::cout << "Chào mừng bạn đến với trò chơi Đá, Giấy, Kéo!\n";
    std::cout << "Hãy nhập 0 cho Đá, 1 cho Giấy, hoặc 2 cho Kéo:\n ";
    
    int player_choice;
    std::cin >> player_choice;

    std::cout << "Bạn đã chọn: " << choices[player_choice] << "\n";
    std::cout << "Máy tính đã chọn: " << choices[computer_choice] << "\n";

    if (player_choice == computer_choice) {
        \
        std::cout << "Hòa!\n";
    } else if ((player_choice + 1) % 3 == computer_choice) {
        std::cout << "Bạn thua!\n";
    } else {
        std::cout << "Bạn thắng!"<<endl;
    }

    return 0;
}
