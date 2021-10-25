#include "stats.h"
#include <numeric>
#include <algorithm>

namespace Statistics
{
  Stats ComputeStatistics(const std::vector<float>& sensorValueList) {
    Stats stats_value;
    std::vector<float>measurementList= sensorValueList;
    int count=measurementList.size();
    if(count!=0)
    {
       //Sort the given input list to get the min and max value from the first and last position of the vector respectively
       std::sort(measurementList.begin(), measurementList.end());
       float total=std::accumulate(measurementList.begin(), measurementList.end(),0.0);
       stats_value.average =  total / count;
       stats_value.min=measurementList[0];
       stats_value.max=measurementList[count -1 ];
    }
    return stats_value;
  }
}//namespace Statistics
