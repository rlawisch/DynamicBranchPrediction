#ifndef PROGRAMCOUNTER_H
#define PROGRAMCOUNTER_H


class ProgramCounter
{
public:
    // avoid replication of an object
    ProgramCounter(const ProgramCounter&) = delete;
    static ProgramCounter& GetInstance();

    // utility functions to retrieve and modify pc
    int Get();
    void Add(int x);
    void Set(int x);

private:
    // private constructor to ensure singleton
    ProgramCounter();
    static ProgramCounter pc_instance;
    int pc;
};

ProgramCounter ProgramCounter::pc_instance;
#endif // PROGRAMCOUNTER_H
