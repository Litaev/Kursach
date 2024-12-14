#ifndef DATE_H
#define DATE_H

#include <QVariantMap>
#include <string>

class Date {
    int year = 1970;
    int month = 0;
    int day = 0;
    int hour = 0;
    int minute = 0;
public:
    int getYear() const;
    int getMonth() const;
    int getDay() const;
    int getHour() const;
    int getMinute() const;
    void setYear(int new_year);
    void setMonth(int new_month);
    void setDay(int new_day);
    void setNowDate();

    QVariant getDate() const;
    static QVariant DateToVariant(const Date& date);
    static Date VariantToDate(const QVariant& var);

};

#endif // DATE_H
