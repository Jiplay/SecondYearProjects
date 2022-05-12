/* 
        I'm the header father fuckers
*/

#include <stdlib.h>
#include "error.hpp"


PlazzaError::PlazzaError(std::string const &m, std::string const &c)
{
    _msg = m;
    _cmp = c;
}

ReceptionError::ReceptionError(std::string const &m, std::string const &c) : PlazzaError(m, c)
{

}

ProcessError::ProcessError(std::string const &m, std::string const &c) : PlazzaError(m, c)
{

}



