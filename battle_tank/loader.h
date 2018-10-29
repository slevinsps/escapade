#ifndef LOADER_H
#define LOADER_H

#include "socket.h"

class Loader
{
public:
    Loader();
    ~Loader();
protected:
    // Возвращают код ошибки
    // Переводит объект типа Loader в std::string
    // который посылается внутри socket
    virtual int load(Socket socket) = 0;
    virtual int send(Socket socket) = 0;
};

#endif // LOADER_H
