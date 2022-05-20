
#include "ClassWeather.hpp"
using namespace std;
int main()
{ 
    auto WS = WeatherStation();

    Forecast Forecast(WS); 
    Current Current(WS); 
    Stadistics Stadistics(WS);
    WS.SetVars(14, 41, 36);
}