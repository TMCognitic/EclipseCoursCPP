#pragma once
#include <string>
#include <functional>

class Banque;

using namespace std;

class NotifyHandler
{
    using Func = std::function<void(const string&)>;
private:
     Func _function = nullptr;
protected:
    void Raise(const string& numero);

public:
    void Register(Func function);
    void Unregister(Func function);
};



