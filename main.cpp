#include <iostream>
#include <PmCommand.h>

using namespace std;

int main()
{
    CPmCommand* pPmCmd = CPmCommand::Instance();

    pPmCmd->Analy("/TestOne");
    pPmCmd->Exec();

    pPmCmd->Analy("/TestTwo Param");
    pPmCmd->Exec();

    return 0;
}
