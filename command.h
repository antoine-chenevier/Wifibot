#ifndef COMMAND_H
#define COMMAND_H


class Command
{
public:
    Command(bool is_rotation);
    bool is_rotation;

private:
    virtual bool is_done();
    void update();
};

#endif // COMMAND_H
