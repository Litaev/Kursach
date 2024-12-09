#include "Headers/statistics.h"
#include <QDebug>



void Statistics::updateMoney(std::vector<std::shared_ptr<Event>> eventList){
    carMoneySpent = 0;
    serviceMoney = 0;
    fuelMoney = 0;
    otherMoney = 0;
    serviceMaintenanceMoney = 0;
    serviceRepairMoney = 0;
    serviceTuningMoney = 0;
    serviceDetailMoney = 0;
    serviceDiagnosticsMoney = 0;
    serviceTireFittingMoney = 0;
    serviceOtherMoney = 0;

    float eventMoney;
    for (auto &event : eventList){
        eventMoney = event->getMoneyValue();
        carMoneySpent += eventMoney;
        if (event->getEventType() == CONSUMPTION_NAME::SERVICE){
            serviceMoney += eventMoney;
            switch (event->getServiceType()) {
            case SERVICE_NAME::MAINTENANCE:
                serviceMaintenanceMoney += eventMoney;
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

float Statistics::getOtherMoney() const
{
    return otherMoney;
}

void Statistics::setOtherMoney(float newOtherMoney)
{
    otherMoney = newOtherMoney;
}

float Statistics::getServiceMaintenanceMoney() const
{
    return serviceMaintenanceMoney;
}

void Statistics::setServiceMaintenanceMoney(float newServiceMaintanceMoney)
{
    serviceMaintenanceMoney = newServiceMaintanceMoney;
}

float Statistics::getServiceRepairMoney() const
{
    return serviceRepairMoney;
}

void Statistics::setServiceRepairMoney(float newServiceRepairMoney)
{
    serviceRepairMoney = newServiceRepairMoney;
}

float Statistics::getServiceTuningMoney() const
{
    return serviceTuningMoney;
}

void Statistics::setServiceTuningMoney(float newServiceTuningMoney)
{
    serviceTuningMoney = newServiceTuningMoney;
}

float Statistics::getServiceDetailMoney() const
{
    return serviceDetailMoney;
}

void Statistics::setServiceDetailMoney(float newServiceDetailMoney)
{
    serviceDetailMoney = newServiceDetailMoney;
}

float Statistics::getServiceDiagnosticsMoney() const
{
    return serviceDiagnosticsMoney;
}

void Statistics::setServiceDiagnosticsMoney(float newServiceDiagnosticsMoney)
{
    serviceDiagnosticsMoney = newServiceDiagnosticsMoney;
}

float Statistics::getServiceTireFittingMoney() const
{
    return serviceTireFittingMoney;
}

void Statistics::setServiceTireFittingMoney(float newServiceTireFittingMoney)
{
    serviceTireFittingMoney = newServiceTireFittingMoney;
}

float Statistics::getServiceOtherMoney() const
{
    return serviceOtherMoney;
}

void Statistics::setServiceOtherMoney(float newServiceOtherMoney)
{
    serviceOtherMoney = newServiceOtherMoney;
}

float Statistics::getCarMoneySpent() const
{
    return carMoneySpent;
}

void Statistics::setCarMoneySpent(float newCarMoneySpent)
{
    carMoneySpent = newCarMoneySpent;
}

float Statistics::getServiceMoney() const
{
    return serviceMoney;
}

void Statistics::setServiceMoney(float newServiceMoney)
{
    serviceMoney = newServiceMoney;
}

float Statistics::getFuelMoney() const
{
    return fuelMoney;
}

void Statistics::setFuelMoney(float newFuelMoney)
{
    fuelMoney = newFuelMoney;
}
