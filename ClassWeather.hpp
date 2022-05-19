#include "ClassObserver.hpp"

class WeatherStation : public Subject 
{
private: 
    int humidity;
    int temperature;
    int pressure;

public:
    WeatherStation(){}
    void SetVars(int humidity, int temperature, int pressure)
    {
        this->humidity = humidity; 
        this->temperature = temperature;
        this->pressure = pressure;

        Notify(); 
    }

    int Gethumidity() const { return humidity; }
    int Gettemperature() const { return temperature; }
    int Getpressure() const { return pressure; }
}; 

//-------------------------

class Forecast: public Observer 
{ 
public: 
    Forecast(WeatherStation& s) : subject(s) { subject.Attach(*this); }
    ~Forecast() { subject.Detach(*this); }
    void Update(Subject& theChangedSubject) override
    {
        if (&theChangedSubject == &subject) {
             Draw();
        }
    }

    void Draw()
    {
        int humidity = subject.Gethumidity(); 
        int temperature = subject.Gettemperature(); 
        int pressure = subject.Getpressure(); 

        std::cout << "las variables de forecast son " << humidity << " ; " 
                << temperature << " ; " 
                << pressure << std::endl;           
    }

private:
    WeatherStation& subject;
};

class Current: public Observer 
{ 
public: 
    Current(WeatherStation& s) : subject(s) { subject.Attach(*this); }
    ~Current() { subject.Detach(*this); }
    void Update(Subject& theChangedSubject) override
    {
        if (&theChangedSubject == &subject) {
            Draw();
        }
    }
    void Draw()
    {
        int humidity = subject.Gethumidity(); 
        int temperature = subject.Gettemperature(); 
        int pressure = subject.Getpressure(); 

        std::cout << "las variables de current son " << humidity << " ; " 
                << temperature << " ; " 
                << pressure << std::endl; 
    }
private:
    WeatherStation& subject;
};


class Stadistics: public Observer 
{ 
public: 
    Stadistics(WeatherStation& s) : subject(s) { subject.Attach(*this); }
    ~Stadistics() { subject.Detach(*this); }
    void Update(Subject& theChangedSubject) override
    {
        if (&theChangedSubject == &subject) {
            Draw();
        }
    }
    void Draw()
    {
        int humidity = subject.Gethumidity(); 
        int temperature = subject.Gettemperature(); 
        int pressure = subject.Getpressure(); 

        std::cout << "las variables de stadistics son " << humidity << " ; " 
                << temperature << " ; " 
                << pressure << std::endl; 
    }
private:
    WeatherStation& subject;
};
