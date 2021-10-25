#include <vector>
#include <math.h>

namespace Statistics {
    struct Stats
    {
    	Stats() : average(NAN), min(NAN), max(NAN){}
    	float average;
    	float min;
    	float max;
    };
    Stats ComputeStatistics(const std::vector<float>& );
}
