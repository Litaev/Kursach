#include "Headers/eventsWindow.h"


EventsWindow::EventsWindow(EventListElementModel *event_model, User *user){
    this->event_model = event_model;
    this->user = user;
}

void EventsWindow::updateModel(){
    event_model->resetEventsModel(user);
    if (user->getCarListSize() > 0){
        (*user->getCarList()[user->getChosenCarId()]) == 1;
        user->getCarList()[user->getChosenCarId()]->updateCarMileage();
    }
};
