
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

void CarService::saveCarServiceInDatabase() {
    // pqxx::connection database_connect("dbname=postgres user=postgres password=Sosi_jopy host=localhost port=5432");
    // if (!database_connect.is_open()) {
    //     std::cerr << "Database connection error" << std::endl;
    //     exit(111);
    // }
    // pqxx::work database_work1(database_connect);
    // pqxx::result database_car_service_id = database_work1.exec("INSERT INTO service (fk_event_id, service_type, service_string) VALUES (" +
    //                                                            database_work1.quote(getEventId()) + ", " + database_work1.quote(static_cast<int>(service_type)) + ", " + database_work1.quote(service_type_string) + ") RETURNING event_service_id;");
    // car_service_id = database_car_service_id[0][0].as<int>();
    // database_work1.commit();
}
void CarService::loadCarServiceFromDatabase() {
    // pqxx::connection database_connect("dbname=postgres user=postgres password=Sosi_jopy host=localhost port=5432");
    // if (!database_connect.is_open()) {
    //     std::cerr << "Database connection error" << std::endl;
    //     exit(111);
    // }
    // pqxx::work database_work(database_connect);
    // pqxx::row car_service_info = database_work.exec1("SELECT * FROM service WHERE fk_event_id = " + database_work.quote(getEventId()));
    // car_service_id = car_service_info["event_service_id"].as<int>();
    // service_type = static_cast<SERVICE_NAME>(car_service_info["service_type"].as<int>());
    // service_type_string = car_service_info["service_string"].as<std::string>();
    // database_work.commit();
}
