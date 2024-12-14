#ifndef MYAPP_H
#define MYAPP_H
#include <QApplication>
#include "Headers/user.h"
class MyApp : public QApplication{
    ~MyApp(){
        this_user->saveUserData();
    }

    void setThisUser(User &user){
        this_user = &user;
    }
private:
    User* this_user;
};

#endif // MYAPP_H
