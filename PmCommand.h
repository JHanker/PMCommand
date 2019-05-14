#ifndef PMCOMMAND_H
#define PMCOMMAND_H


#include <string>
#include <map>


class CPmCommand
{
public:
    static CPmCommand* Instance();

    //解析
    void Analy(const std::string & cmd);
    //执行
    bool Exec();

private:
    bool TestOne();
    bool TestTwo();

private:
    CPmCommand();
    ~CPmCommand();

private:
    typedef bool (CPmCommand:: * FUNC)();

    std::string m_HeadOpt;
    std::string m_SubCmd;
    std::map<std::string, FUNC> m_mapExecFunc;
};


#endif // PMCOMMAND_H
