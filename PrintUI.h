#ifndef __PRINTUI_H__
#define __PRINTUI_H__


using std::cout;
using std::cin;

class PrintUI
{
public:

	static int PrintMainUI();

	static void PrintClientUI(Manager*);
	static void PrintProductUI(Manager*);
	static void PrintOrderUI(Manager*);
};

#endif