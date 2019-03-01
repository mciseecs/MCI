#ifndef INJECTORHANDLINGMETRICS_H
#define INJECTORHANDLINGMETRICS_H
#include < time.h >
#include<ctime>

#include <sofa/core/objectmodel/Event.h>
#include <sofa/core/core.h>
#include <sofa/component/typedef/MechanicalState_double.h>
#include <sofa/core/objectmodel/BaseObject.h>
#include <sofa/core/BehaviorModel.h>
#include <sofa/simulation/PipelineImpl.h>
#include "C:\sofa\src\applications\plugins\ExercisePipeline\InjectorHandlingPipeline.h"

class InjectorHandlingMetrics : public sofa::core::BehaviorModel

{
public:
	sofa::component::container::MechanicalObject<sofa::defaulttype::Vec3dTypes>::Coord distLI;
	//double time_diff;
	int count;
	DWORD dw1;
	int startFlag;
	double PathLengthLI;
	bool dialogDisplayed;
	sofa::component::collision::InjectorHandlingPipeline *HandlePipeline;

	double tempxL, tempyL, tempzL;
	SOFA_CLASS(InjectorHandlingMetrics, sofa::core::BehaviorModel);
	//sofa::core::objectmodel::Data<float> m_myparam;
	void updatePosition(SReal dt);
	virtual void doCollisionResponse();
	InjectorHandlingMetrics();
	~InjectorHandlingMetrics();



};


#endif
