class IAlerter
{
  public:
      virtual void sendAlert(bool alertStatus)=0;
};

class EmailAlert: public IAlerter
{
 public:
    EmailAlert(): emailSent(false) {}

    void sendAlert(bool alertStatus)
    {
      emailSent=alertStatus;
    }
    
    //member variable
    bool emailSent;
};

class LEDAlert: public IAlerter
{
 public:
    LEDAlert(): ledGlows(false) {}
    
    void sendAlert(bool alertStatus)
    {
      ledGlows=alertStatus;
    }

    //member variable
    bool ledGlows;
};

class StatsAlerter
{
 public:
   StatsAlerter():maxThreshold(0.0){}
   StatsAlerter(float p_maxThreshold,std::vector<IAlerter*> alerterList):maxThreshold(p_maxThreshold),alerters(alerterList){}
   
   void checkAndAlert(const std::vector<float>& sensorValues)
   {
      Statistics::Stats statsResult = Statistics::ComputeStatistics(sensorValues);
      if(statsResult.max > maxThreshold)
      {
          //alerters[0]->sendAlert(true);
          //alerters[1]->sendAlert(true);
          std::vector<IAlerter*>::iterator itAlerts;
          for (itAlerts = alerters.begin(); itAlerts != alerters.end(); itAlerts++)
          {
	      (*itAlerts)->sendAlert(true);  
          }
      }
   }
   float maxThreshold;
   std::vector<IAlerter*> alerters;
};
