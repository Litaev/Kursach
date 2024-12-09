#include "eventlistelement.h"

EventListElement::EventListElement() {}

CONSUMPTION_NAME EventListElement::event_type() const
{
    return m_event_type;
}

void EventListElement::setEvent_type(CONSUMPTION_NAME newEvent_type)
{
    m_event_type = newEvent_type;
}
