#include "Headers/eventsWindow.h"


EventsWindow::EventsWindow(EventListElementModel *event_model, User *user)
    : event_model(event_model), user(user) {}


void EventsWindow::updateModel(){
    event_model->resetEventsModel(user);
    if (user->getCarListSize() > 0){
        (*user->getCarList()[user->getChosenCarId()]) == 1;
        user->getCarList()[user->getChosenCarId()]->updateCarMileage();
    }
};
