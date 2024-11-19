#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

#define ANSI_COLOR_RESET "\033[0m"
#define ANSI_COLOR_RED "\033[91m"
#define ANSI_COLOR_GREEN "\033[92m"
#define ANSI_COLOR_YELLOW "\033[93m"
#define ANSI_COLOR_BLUE "\033[94m"
#define ANSI_COLOR_MAGENTA "\033[95m"
#define ANSI_COLOR_CYAN "\033[96m"

int main() {
    // Mảng chứa các mã màu sắc
    const string colors[] = {
        ANSI_COLOR_RED,
        ANSI_COLOR_GREEN,
        ANSI_COLOR_YELLOW,
        ANSI_COLOR_BLUE,
        ANSI_COLOR_MAGENTA,
        ANSI_COLOR_CYAN
    };

    const int numColors = sizeof(colors) / sizeof(colors[0]);

    while (true) {
        for (int i = 0; i < numColors; ++i) {
            cout << colors[i];
            cout << "-------------------------------------------------------------------" << endl;
            cout << "|                             _oo0oo_                             |" << endl;
            cout << "|                            o8888888o                            |" << endl;
            cout << "|                            88\" . \"88                            |" << endl;
            cout << "|                            (| -_- |)                            |" << endl;
            cout << "|                            0\\  =  /0                            |" << endl;
            cout << "|                          ___/`---'\\___                          |" << endl;
            cout << "|                        .' \\\\|     |// '.                        |" << endl;
            cout << "|                       / \\\\|||  :  |||// \\                       |" << endl;
            cout << "|                      / _||||| -:- |||||- \\                      |" << endl;
            cout << "|                     |   | \\\\\\  -  /// |   |                     |" << endl;
            cout << "|                     | \\_|  ''\\---/''  |_/ |                     |" << endl;
            cout << "|                     \\  .-\\__  '-'  ___/-. /                     |" << endl;
            cout << "|                   ___'. .'  /--.--\\  `. .'___                   |" << endl;
            cout << "|                .\"\" '<  `.___\\_<|>_/___.' >' \"\".                 |" << endl;
            cout << "|               | | :  `- `.;`\\ _ /`;.`/ - ` : | |                |" << endl;
            cout << "|               \\  \\ `_.   \\_ __\\ /__ _/   .-` /  /               |" << endl;
            cout << "|           =====`-.____`.___ \\_____/___.-`___.-'=====            |" << endl;
            cout << "|                             `=---='                             |" << endl;
            cout << "|                                                                 |" << endl;
            cout << "|           ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~            |" << endl;
            cout << "|                        Phat do qua mon                          |" << endl;
            cout << "|           ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
            }
            }
            }