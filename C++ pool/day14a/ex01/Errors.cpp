/*
** Errors.cpp for B-CPP-300-PAR-3-2-CPPD14A-julien.garsia
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Tue Jan 19 3:01:40 PM 2021 julien.garsia
** Last update Wed Jan 19 9:21:32 PM 2021 julien.garsia
*/

#include "Errors.hpp"

NasaError::NasaError(std::string const &mail, std::string const &component)
{
    _message = mail;
    _component = component;
}

MissionCriticalError::MissionCriticalError(std::string const &message, std::string const &component) : NasaError(message, component)
{
}

LifeCriticalError::LifeCriticalError(std::string const &message, std::string const &component) : NasaError(message, component)
{
}

UserError::UserError(std::string const &message, std::string const &component) : NasaError(message, component)
{
}

CommunicationError::CommunicationError(std::string const &message) : NasaError(message, "CommunicationDevice")
{
}
