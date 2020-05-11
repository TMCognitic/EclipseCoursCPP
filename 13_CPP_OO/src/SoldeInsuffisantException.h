#pragma once
#include <iostream>
#include <exception>
using namespace std;

class SoldeInsuffisantException : public exception
{
    virtual const char* what() const throw()
    {
        return "Solde Insuffisant!";
    }
} soldeInsuffisantException;
