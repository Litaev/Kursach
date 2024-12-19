#ifndef APPDEBUGLOGGER_H
#define APPDEBUGLOGGER_H

#include <QDebug>
#include <QObject>
#include <vector>
#include "Headers/date.h"

class AppDebugLogger{


    std::vector<std::string> debugLog;
    std::string strTime;
    Date dateAndTime;

    void addMessageToLogger(std::string message){
        dateAndTime.setNowDate();
        message += dateAndTime.getDateAndTimeForDebug(dateAndTime);
        debugLog.push_back(message);
    }


public:
    ~AppDebugLogger(){
        qDebug() << "(-----DEBUG LOG-----\n";
        for (auto &debugMessage : debugLog){
            qDebug() << debugMessage;
        }
        qDebug() << "\n-----DEBUG LOG-----)";
        debugLog.clear();
    }

    void newError(std::string errorMessage){
        addMessageToLogger(errorMessage);
        qDebug() << debugLog.back();
    }



};

#endif // APPDEBUGLOGGER_H
