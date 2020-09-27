#include <iostream>
#include <windows.h>
using namespace std;
HANDLE questions = GetStdHandle(STD_OUTPUT_HANDLE);

int main()
{
    HWND console = GetConsoleWindow();
    RECT ConsoleRect;
    GetWindowRect(console, &ConsoleRect);
    MoveWindow(console, ConsoleRect.left, ConsoleRect.top, 650, 600, TRUE);

    SetConsoleTextAttribute(questions, 1);
    string WEBHOOK_URL;
    string MESSAGE;
    int AMOUNT;
    int COUNTER = 0;
    cout << "  _   _                |  __    __     _                       _         |\n";
    cout << " | \\ | |               | / / /\\ \\ \\___| |__   /\\  /\\___   ___ | | __     |\n";
    cout << " |  \\| | ___ ____      | \\ \\/  \\/ / _ \\ '_ \\ / /_/ / _ \\ / _ \\| |/ /     |\n";
    cout << " | . ` |/ _ \ \_  /      |  \\  /\\  /  __/ |_) / __  / (_) | (_) |   <      |\n";
    cout << " | |\\  |  __// /       |   \\/  \\/ \\___|_.__/\\/ /_/ \\___/ \\___/|_|\\_\\     |\n";
    cout << " |_| \\_|\\___/___|      |                                                 |\n";
    cout << "_______________________|_________________________________________________|\n\n";

    SetConsoleTextAttribute(questions, 5); cout << "Enter Webhook url: ";           SetConsoleTextAttribute(questions, 3); cin >> WEBHOOK_URL;
    SetConsoleTextAttribute(questions, 5); cout << "\nEnter Message: ";             SetConsoleTextAttribute(questions, 3); cin >> MESSAGE;
    SetConsoleTextAttribute(questions, 5); cout << "\nEnter Amount Of Messages: ";  SetConsoleTextAttribute(questions, 3); cin >> AMOUNT;
    ::ShowWindow(::GetConsoleWindow(), HIDE_WINDOW);

    string curl = "curl -X POST -H ";
    string content = "\"Content-Type: application/json\" ";
    string d = "-d ";
    string info = "\"{\\\"content\\\":\\\"";
    string end = "\\\"}\"";
    string FINISH = curl + content + d + info + MESSAGE + end + " " + WEBHOOK_URL;
    COUNTER++;

    while (AMOUNT >= COUNTER) {
        system(FINISH.c_str());
        COUNTER++;
        Sleep(103);
    }

}
