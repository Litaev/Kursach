#ifndef STATISTICS_H
#define STATISTICS_H

#include "event.h"
#include "enums.h"


class Statistics{
    float carMoneySpent;
    float serviceMoney;
    float fuelMoney;
    float otherMoney;
    float serviceMaintenanceMoney;
    float serviceRepairMoney;
    float serviceTuningMoney;
    float serviceDetailMoney;
    float serviceDiagnosticsMoney;
    float serviceTireFittingMoney;
    float serviceOtherMoney;

public:
    void updateMoney(std::vector<std::shared_ptr<Event>> eventList);

    float getCarMoneySpent() const;
    void setCarMoneySpent(float newCarMoneySpent);
    float getServiceMoney() const;
    void setServiceMoney(float newServiceMoney);
    float getFuelMoney() const;
    void setFuelMoney(float newFuelMoney);
    float getOtherMoney() const;
    void setOtherMoney(float newOtherMoney);
    float getServiceMaintenanceMoney() const;
    void setServiceMaintenanceMoney(float newServiceMaintenanceMoney);
    float getServiceRepairMoney() const;
    void setServiceRepairMoney(float newServiceRepairMoney);
    float getServiceTuningMoney() const;
    void setServiceTuningMoney(float newServiceTuningMoney);
    float getServiceDetailMoney() const;
    void setServiceDetailMoney(float newServiceDetailMoney);
    float getServiceDiagnosticsMoney() const;
    void setServiceDiagnosticsMoney(float newServiceDiagnosticsMoney);
    float getServiceTireFittingMoney() const;
    void setServiceTireFittingMoney(float newServiceTireFittingMoney);
    float getServiceOtherMoney() const;
    void setServiceOtherMoney(float newServiceOtherMoney);
};

#endif // STATISTICS_H
