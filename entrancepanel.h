#ifndef ENTRANCEPANEL_H
#define ENTRANCEPANEL_H

#include <QApplication>

class EntrancePanel
{
public:
    EntrancePanel();
    void printTicket(std::string newLicense, char type);
};

#endif // ENTRANCEPANEL_H
