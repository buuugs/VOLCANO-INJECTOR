#include "ManualMap.h"
#include "LoadLibrary.h"

enum InjectionType : int
{
    ManualMap,
    loadLibrary
};

InjectionType InjectionMethod;
string proccessname;
string dllname;

#include <Windows.h>

void HideConsole()
{
    ::ShowWindow(::GetConsoleWindow(), SW_HIDE);
}

void ShowConsole()
{
    ::ShowWindow(::GetConsoleWindow(), SW_SHOW);
}

bool IsConsoleVisible()
{
    return ::IsWindowVisible(::GetConsoleWindow()) != FALSE;
}
int main(int argc, char **argv)
{
 
    HideConsole();
    string InjectionMethodTemp;

   // getline(cin, InjectionMethodTemp);
    if (InjectionMethodTemp.empty()) InjectionMethod = ManualMap;
   // else InjectionMethod = loadLibrary;

   // printf("Please input proccess you want inject to (press Enter for csgo.exe)\n");

  //  getline(cin, proccessname);
    if (proccessname.empty()) proccessname = "csgo.exe";

	if (argc == 1)
	{
		
	}
	else if (argc == 2) dllname = argv[1];
    if (dllname.empty()) dllname = "loadbin.dll";

    switch (InjectionMethod)
    {
    case ManualMap:
        manual_map->manualmapmain(proccessname.c_str(), dllname.c_str(), argc);
        break;
    case loadLibrary:
        load_library->loadlibrarymain(proccessname.c_str(), dllname.c_str(), argc);
        break;
    }
   
}

