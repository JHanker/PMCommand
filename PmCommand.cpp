#include "PmCommand.h"

#include <iostream>


CPmCommand::CPmCommand()
{
    m_mapExecFunc["TestOne"] = &CPmCommand::TestOne;
    m_mapExecFunc["TestTwo"] = &CPmCommand::TestTwo;
}

CPmCommand::~CPmCommand()
{

}

CPmCommand *CPmCommand::Instance()
{
    static CPmCommand pm;

    return &pm;
}

void CPmCommand::Analy(const std::string & cmd)
{
    m_HeadOpt.clear();
    m_SubCmd.clear();

    std::string::size_type pos;
    pos = cmd.find("/");
    if (cmd.npos != pos)
    {
        std::string::size_type nextPos = cmd.find(" ", pos + 1);
        if (cmd.npos != nextPos)
        {
            m_HeadOpt = cmd.substr(pos + 1, nextPos - (pos + 1));
            m_SubCmd = cmd.substr(nextPos + 1, cmd.size() - (pos + 1));
        }
        else
        {
            m_HeadOpt = cmd.substr(pos + 1, cmd.length() - 1);
        }
    }
}

bool CPmCommand::Exec()
{
    std::map<std::string, FUNC>::iterator ite = m_mapExecFunc.find(m_HeadOpt);
    if (m_mapExecFunc.end() != ite)
    {
        return (this->*ite->second)();
    }

    return false;
}

bool CPmCommand::TestOne()
{
    std::cout << "============Exec=============" << std::endl;
    std::cout << "HeadOpt:  " << m_HeadOpt << std::endl;
    std::cout << "SubCmd:   " << m_SubCmd << std::endl;
    std::cout << "Function: " << __FUNCTION__ << std::endl;

    return true;
}

bool CPmCommand::TestTwo()
{
    std::cout << "============Exec=============" << std::endl;
    std::cout << "HeadOpt:  " << m_HeadOpt << std::endl;
    std::cout << "SubCmd:   " << m_SubCmd << std::endl;
    std::cout << "Function: " << __FUNCTION__ << std::endl;

    return true;
}
