
#include "Headers/service.h"
#include <iostream>
using namespace std;



SERVICE_NAME CarService::getServiceType() const{
    return service_type;
}
void CarService::setServiceType(SERVICE_NAME serviceType) {
    service_type = serviceType;
}
std::string CarService::getServiceTypeAsString() const{
    return service_type_string;
}
void CarService::setServiceTypeAsString(std::string &serviceName) {
    service_type_string = serviceName;
}

