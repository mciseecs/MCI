#ifndef SPHEREHANDLINGMETRICS_H
#define SPHEREHANDLINGMETRICS_H
#include < time.h >
#include<ctime>


#include <sofa/core/objectmodel/BaseObject.h>
#include <sofa/core/BehaviorModel.h>
#include <sofa/simulation/PipelineImpl.h>

class SphereHandlingMetrics:  public sofa::core::BehaviorModel

{
public:
        //double time_diff;
        int count;
        DWORD dw1;
       SOFA_CLASS(SphereHandlingMetrics, sofa::core::BehaviorModel);
        //sofa::core::objectmodel::Data<float> m_myparam;
         void updatePosition(SReal dt) ;
         virtual void doCollisionResponse();
        SphereHandlingMetrics();
        ~SphereHandlingMetrics();



};


#endif
