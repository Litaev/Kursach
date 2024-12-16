#include "Headers/chooseCarWindow.h"



ChooseCarWindow::ChooseCarWindow(CarListElementModel *car_model, User *user)
    : car_model(car_model), user(user) {}


void ChooseCarWindow::updateModel(){
    car_model->resetModel(user);
};




