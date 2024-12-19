#ifndef PRESAVEABLE_H
#define PRESAVEABLE_H

#include <QVariantMap>

class Presaveable{

public:
    virtual QVariantMap preSaveData() const = 0;
};

#endif // PRESAVEABLE_H
