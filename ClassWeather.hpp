#include "ClassObserver.hpp"

class WeatherStation : public Subject 
{
    private: 
        int humidity;
        int temperature;
        int pressure;

    public:
        WeatherStation() = default;
        void SetVars(int humidity_, int temperature_, int pressure_)
        {
            this->humidity = humidity_; 
            this->temperature = temperature_;
            this->pressure = pressure_;

            Notify(); 
        }

        int Gethumidity() const { return humidity; }
        int Gettemperature() const { return temperature; }
        int Getpressure() const { return pressure; }
}; 

//-------------------------

class Forecast: public Observer 
{ 
    private:
        WeatherStation& subject;

    public: 
        explicit Forecast(WeatherStation& s) : subject(s) { subject.Attach(*this); }
        ~Forecast() final { subject.Detach(*this); }
        void update(Subject& theChangedSubject) override
        {
            if (&theChangedSubject == &subject) {
                Draw();
            }
        }

        void Draw() const
        {
            int humidity = subject.Gethumidity(); 
            int temperature = subject.Gettemperature(); 
            int pressure = subject.Getpressure(); 

            std::cout << "las variables de forecast son " << humidity << " ; " 
                    << temperature << " ; " 
                    << pressure << std::endl;           
        }
};

class Current: public Observer 
{
    private:
        WeatherStation& subject;

    public: 
        explicit Current(WeatherStation& s) : subject(s) { subject.Attach(*this); }
        ~Current() final { subject.Detach(*this); }
        void update(Subject& theChangedSubject) override
        {
            if (&theChangedSubject == &subject) {
                Draw();
            }
        }
        void Draw() const
        {
            int humidity = subject.Gethumidity(); 
            int temperature = subject.Gettemperature(); 
            int pressure = subject.Getpressure(); 

            std::cout << "las variables de current son " << humidity << " ; " 
                    << temperature << " ; " 
                    << pressure << std::endl; 
        }

};


class Stadistics: public Observer 
{ 
    private:
        WeatherStation& subject;

    public: 
        explicit Stadistics(WeatherStation& s) : subject(s) { subject.Attach(*this); }
        ~Stadistics() final { subject.Detach(*this); }
        void update(Subject& theChangedSubject) override
        {
            if (&theChangedSubject == &subject) {
                Draw();
            }
        }
        void Draw() const
        {
            int humidity = subject.Gethumidity(); 
            int temperature = subject.Gettemperature(); 
            int pressure = subject.Getpressure(); 

            std::cout << "las variables de stadistics son " << humidity << " ; " 
                    << temperature << " ; " 
                    << pressure << std::endl; 
        }

};
