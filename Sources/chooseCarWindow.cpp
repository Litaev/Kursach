#include "Headers/chooseCarWindow.h"



ChooseCarWindow::ChooseCarWindow(CarListElementModel *car_model, User *user){
    this->car_model = car_model;
    this->user = user;
}

void ChooseCarWindow::updateModel(){
    car_model->resetModel(user);
};




