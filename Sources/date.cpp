#define _CRT_SECURE_NO_WARNINGS
#include "Headers/date.h"


unsigned int Date::getYear() const{
    return year;
}
unsigned int Date::getMonth() const{
    return month;
}
unsigned int Date::getDay() const{
    return day;
}
void Date::setYear(unsigned int new_year){
    year = new_year;
}
void Date::setMonth(unsigned int new_month){
    month = new_month;
}
void Date::setDay(unsigned int new_day){
    day = new_day;
}
void Date::setNowDate(){
    auto now = std::chrono::system_clock::now();
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);
    std::tm local_time = *std::localtime(&now_c);
    minute = local_time.tm_min;
    hour = local_time.tm_hour;
    day = local_time.tm_mday;
    month = local_time.tm_mon + 1;
    year = local_time.tm_year + 1900;
}

QVariant Date::DateToVariant(const Date& date) {
    QString sDay = QString::fromStdString(std::to_string(date.day));
    QString sMonth = QString::fromStdString(std::to_string(date.month));
    QString sYear = QString::fromStdString(std::to_string(date.year));
    QString sHour = QString::fromStdString(std::to_string(date.hour));
    QString sMinute = QString::fromStdString(std::to_string(date.minute));
    if (date.day < 10) sDay = "0" + sDay;
    if (date.month < 10) sMonth = "0" + sMonth;
    if (date.hour < 10) sHour = "0" + sHour;
    if (date.minute < 10) sMinute = "0" + sMinute;
    return QVariant::fromValue(sDay + "-" + sMonth + "-" + sYear + "-" + sHour + ":" + sMinute);
}

Date Date::VariantToDate(const QVariant& var) {
    QStringList parts = var.toString().split("-");
    Date date;
    if (parts.size() == 4) {
        date.day = parts[0].toInt();
        date.month = parts[1].toInt();
        date.year = parts[2].toInt();
        QStringList time = parts[3].split(":");
        date.hour = time[0].toInt();
        date.minute = time[1].toInt();
        time.clear();
    }
    parts.clear();
    return date;
}
