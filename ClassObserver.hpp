#include <iostream>
#include <vector>
#include <algorithm>


class Subject; 

class Observer 
{ 
public:
    virtual ~Observer() = default;
    virtual void update(Subject&) = 0;
};

class Subject 
{ 
public: 
     virtual ~Subject() = default;
     void Attach(Observer& o) { observers.push_back(&o); }
     void Detach(Observer& o)
     {
         observers.erase(std::remove(observers.begin(), observers.end(), &o));
     }
     void Notify()
     {
         for (auto* o : observers) {
             o->update(*this);
         }
     }
private:
     std::vector<Observer*> observers; 
};