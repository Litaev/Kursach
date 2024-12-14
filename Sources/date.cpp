#define _CRT_SECURE_NO_WARNINGS
#include "Headers/date.h"


int Date::getYear() const{
    return year;
}
int Date::getMonth() const{
    return month;
}
int Date::getDay() const{
    return day;
}

int Date::getHour() const{
    return hour;
}

int Date::getMinute() const{
    return minute;
}
void Date::setYear(int new_year){
    year = new_year;
}
void Date::setMonth(int new_month){
    month = new_month;
}
void Date::setDay(int new_day){
    day = new_day;
}
void Date::setNowDate(){
    auto now = std::chrono::system_clock::now();
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);
    std::tm local_time = *std::localtime(&now_c);
    minute = local_time.tm_min;
    hour = local_time.tm_hour;
    day = local_time.tm_mday;
    month = local_time.tm_mon;
    year = local_time.tm_year + 1900;
}

QVariant Date::getDate() const{
    QString sDay = QString::fromStdString(std::to_string(day));
    QString sMonth = QString::fromStdString(std::to_string(month));
    QString sYear = QString::fromStdString(std::to_string(year));
    if (day < 10) sDay = "0" + sDay;
    if (month < 10) sMonth = "0" + sMonth;
    return QVariant::fromValue(sDay + "-" + sMonth + "-" + sYear);
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

long int Date::getDateForSort() const{
    std::tm tm = {0};
    tm.tm_year = year - 1900;
    tm.tm_mon = month - 1;
    tm.tm_mday = day;
    tm.tm_hour = hour;
    tm.tm_min = minute;
    std::time_t time = std::mktime(&tm) / 60;
    return static_cast<long int>(time);

}
