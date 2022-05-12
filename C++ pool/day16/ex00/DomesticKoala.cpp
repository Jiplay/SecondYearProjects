/*
** DomesticKoala.cpp for B-CPP-300-PAR-3-2-CPPD16-julien.garsia
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Thu Jan 21 10:21:07 AM 2021 julien.garsia
** Last update Fri Jan 21 12:37:52 PM 2021 julien.garsia
*/

#include "DomesticKoala.hpp"

DomesticKoala::DomesticKoala(KoalaAction &koala)
{
	_action=koala;
	_next = new std::vector<methodPointer_t>;
}

DomesticKoala::~DomesticKoala()
{
}

DomesticKoala::DomesticKoala(const DomesticKoala &domesticKoala)
{
	_action = domesticKoala._action;
	_next = domesticKoala._next;
	_command = domesticKoala._command;
}


DomesticKoala &DomesticKoala::operator=(const DomesticKoala &d)
{
    _action = d._action;
    _command = d._command;
    _next = d._next;

    return *this;
}

void DomesticKoala::doAction(unsigned char command, const std::string &param)
{
	int j = 0;
	for (auto i : _command) {
		if (i == command){
			methodPointer_t toCall;
			toCall = _next->at(j);
			(_action.*toCall)(param);
		}
		j++;
	}
}

void DomesticKoala::learnAction(unsigned char command, DomesticKoala::methodPointer_t action)
{
    _command.push_back(command);
    _next->push_back(action);
}

void DomesticKoala::unlearnAction(unsigned char command)
{
	int j = 0;
	for (auto i : _command) {
		if (i == command){
			_next->erase(_next->begin()+j);
			_command.erase(_command.begin()+j);
		}
		j++;
	}
}

void DomesticKoala::setKoalaAction(KoalaAction &action)
{
	std::vector<unsigned char> cleanChar;

	_action = action;
	auto *clean = new std::vector<methodPointer_t>;
	_next = clean;
	_command = cleanChar;
}
