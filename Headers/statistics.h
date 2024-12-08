#ifndef STATISTICS_H
#define STATISTICS_H

#include "event.h"
#include "enums.h"
class Statistics : public QObject{
    Q_OBJECT
    int carMoneySpent;
    int serviceMoney;
    int fuelMoney;
    int otherMoney;
    int serviceMaintanceMoney;
    int serviceRepairMoney;
    int serviceTuningMoney;
    int serviceDetailMoney;
    int serviceDiagnosticsMoney;
    int serviceTireFittingMoney;
    int serviceOtherMoney;

public:
    void updateMoney(std::vector<std::shared_ptr<Event>> *eventList){
        carMoneySpent = 0;
        serviceMoney = 0;
        fuelMoney = 0;
        otherMoney = 0;
        serviceMaintanceMoney = 0;
        serviceRepairMoney = 0;
        serviceTuningMoney = 0;
        serviceDetailMoney = 0;
        serviceDiagnosticsMoney = 0;
        serviceTireFittingMoney = 0;
        serviceOtherMoney = 0;

        int eventMoney;
        for (auto &event : *eventList){
            eventMoney = event->getMoneyValue();
            carMoneySpent += eventMoney;
            if (event->getEventType() == CONSUMPTION_NAME::SERVICE){
                serviceMoney += eventMoney;
                switch (event->getServiceType()) {
                    case SERVICE_NAME::MAINTENANCE:
                        serviceMaintanceMoney += eventMoney;
                        break;
                    case SERVICE_NAME::REPAIR:
                        serviceRepairMoney += eventMoney;
                        break;
                    case SERVICE_NAME::TUNING:
                        serviceTuningMoney += eventMoney;
                        break;
                    case SERVICE_NAME::DETAIL:
                        serviceDetailMoney += eventMoney;
                        break;
                    case SERVICE_NAME::DIAGNOSTICS:
                        serviceDiagnosticsMoney += eventMoney;
                        break;
                    case SERVICE_NAME::TIRE_FITTING:
                        serviceTireFittingMoney += eventMoney;
                        break;
                    case SERVICE_NAME::OTHER_SERVICE:
                        serviceOtherMoney += eventMoney;
                        break;
                    default:
                        break;
                }
            }
            else if (event->getEventType() == CONSUMPTION_NAME::REFUELING){
                fuelMoney += eventMoney;
            }
            else if (event->getEventType() == CONSUMPTION_NAME::OTHER_CONSUMPTION){
                otherMoney += eventMoney;
            }
        }

    }

    Q_INVOKABLE int getCarMoneySpent() const;
    void setCarMoneySpent(int newCarMoneySpent);
    Q_INVOKABLE int getServiceMoney() const;
    void setServiceMoney(int newServiceMoney);
    Q_INVOKABLE int getFuelMoney() const;
    void setFuelMoney(int newFuelMoney);
    Q_INVOKABLE int getOtherMoney() const;
    void setOtherMoney(int newOtherMoney);
    Q_INVOKABLE int getServiceMaintanceMoney() const;
    void setServiceMaintanceMoney(int newServiceMaintanceMoney);
    Q_INVOKABLE int getServiceRepairMoney() const;
    void setServiceRepairMoney(int newServiceRepairMoney);
    Q_INVOKABLE int getServiceTuningMoney() const;
    void setServiceTuningMoney(int newServiceTuningMoney);
    Q_INVOKABLE int getServiceDetailMoney() const;
    void setServiceDetailMoney(int newServiceDetailMoney);
    Q_INVOKABLE int getServiceDiagnosticsMoney() const;
    void setServiceDiagnosticsMoney(int newServiceDiagnosticsMoney);
    Q_INVOKABLE int getServiceTireFittingMoney() const;
    void setServiceTireFittingMoney(int newServiceTireFittingMoney);
    Q_INVOKABLE int getServiceOtherMoney() const;
    void setServiceOtherMoney(int newServiceOtherMoney);
};

#endif // STATISTICS_H
