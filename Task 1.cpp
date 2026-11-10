#include<iostream>
#include<algorithm>
using namespace std;
class WeatherStats{
    public:
    double calculateAverageTemperature(double temp[],int n)
    {
        double total=0;
        for(int i=0;i<n;i++)
        {
            total += temp[i];
        }
        return total/n;
    }
    double getTemperatureFluctuation(double temp[],int n)
    {
        double min=0,max=0;
        min = temp[0];
        max = temp[0];
        for(int i=0;i<n;i++)
        {
            if(temp[i]>max)
            {
                max = temp[i];
            }
            if(temp[i]<min)
            {
                min = temp[i];
            }
        }
        cout<<min<<"  "<<max<<endl;
        return max-min;
    }
};
int main()
{
    double arr[]={23.4,67.9,23.3,43.2,12,76};
    int n = sizeof(arr)/sizeof(arr[0]);
    WeatherStats w1;
    cout<<"Average Temperature : "<<
    w1.calculateAverageTemperature(arr,n)<<endl;
    cout<<"Temperature Fluctuation : "<<
    w1.getTemperatureFluctuation(arr,n)<<endl;
    return 0;
}