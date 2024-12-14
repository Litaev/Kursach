#ifndef CARSERVICE_H
#define CARSERVICE_H

#include "event.h"

class User;

class CarService : public Event {
    friend User;
    SERVICE_NAME service_type;
    std::string service_type_string;
public:
    SERVICE_NAME getServiceType() const override;
    void setServiceType(SERVICE_NAME serviceType) override;
    std::string getServiceTypeAsString() const;
    void setServiceTypeAsString(std::string &serviceName) override;

};

#endif // CARSERVICE_H
