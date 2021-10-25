#include "stats.h"

struct Stats
{
    Stats() : average(NAN), min(NAN), max(NAN){}
    float average;
    float min;
    float max;
};

Stats Statistics::ComputeStatistics(const std::vector<float>& sensorValueList )
{
    Stats stats_object;
    std::vector<float>measurementList= sensorValueList;
    int count=measurementList.size();
    if(count!=0)
    {
       std::sort(measurementList.begin(), measurementList.end());
       float total=std::accumulate(measurementList.begin(), measurementList.end(),0.0);
       stats_object.average =  total / measurementList.size();
       stats_object.min=measurementList[0];
       cout<<"min:"<<stats_object.min<<endl;
       stats_object.max=measurementList[count -1 ];
       cout<<"max:"<<stats_object.max<<endl;
    }
    return stats_object;
}
