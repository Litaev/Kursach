#ifndef DATE_H
#define DATE_H

#include <QVariantMap>
#include <string>

class Date {
    unsigned int year;
    unsigned int month;
    unsigned int day;
    unsigned int hour;
    unsigned int minute;
public:
    unsigned int getYear() const;
    unsigned int getMonth() const;
    unsigned int getDay() const;
    void setYear(unsigned int new_year);
    void setMonth(unsigned int new_month);
    void setDay(unsigned int new_day);
    void setNowDate();


    static QVariant DateToVariant(const Date& date);
    static Date VariantToDate(const QVariant& var);

};

#endif // DATE_H
