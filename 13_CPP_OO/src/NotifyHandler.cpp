#include "NotifyHandler.h"

void NotifyHandler::Raise(const string& numero)
{
    if (_function)
        _function(numero);
}

void NotifyHandler::Register(Func function)
{
    _function = function;
}

void NotifyHandler::Unregister(Func function)
{
    _function = nullptr;
}