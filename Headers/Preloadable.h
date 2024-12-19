#ifndef PRELOADABLE_H
#define PRELOADABLE_H
#include <QVariantMap>

class Preloadable{

public:
    virtual void preLoadData(QVariantMap &map) = 0;
};

#endif // PRELOADABLE_H
