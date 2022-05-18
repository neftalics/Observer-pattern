
#include "ClassWeather.hpp"

int main()
{ 
    WeatherStation WS; 

    Forecast Forecast(WS); 
    Current Current(WS); 
    Stadistics Stadistics(WS);
    WS.SetVars(14, 41, 36);
}