#ifndef ICSISIMULATIONMETRICS_H
#define ICSISIMULATIONMETRICS_H
#include < time.h >
#include<ctime>

#include <sofa/core/objectmodel/Event.h>
#include <sofa/core/core.h>
#include <sofa/component/typedef/MechanicalState_double.h>
#include <sofa/core/objectmodel/BaseObject.h>
#include <sofa/core/BehaviorModel.h>
#include <sofa/simulation/PipelineImpl.h>
#include "C:\sofa\src\applications\plugins\ExercisePipeline\InjectorHandlingPipeline.h"
#include <SofaEngine/BoxROI.inl>
#include <SofaOpenglVisual/Light.h>
#include <SofaBaseMechanics/MechanicalObject.h>
class ICSISimulationMetrics : public sofa::core::BehaviorModel

{
public:
	sofa::component::container::MechanicalObject<sofa::defaulttype::Vec3dTypes>::Coord distLI;
	sofa::component::container::MechanicalObject<sofa::defaulttype::Vec3dTypes>::Coord zdistLI;
	sofa::component::container::MechanicalObject<sofa::defaulttype::Vec3dTypes>::Coord distLI2;
	sofa::component::container::MechanicalObject<sofa::defaulttype::Vec3dTypes>::Coord distLI3;
	//double time_diff;
	int count;
	DWORD dw1;
	int startFlag;
	int startFlag2;
	double PathLengthLI;
	double PathLengthLI2;
	double PathLengthLI3;

	double PathLengthLIAccuracy;
	double PathLengthLIAccuracy2;
	double PathLengthLIAccuracy3;
	double PathLength2;
	double DropPathLengthLI;
	double tempxL, tempyL, tempzL;
	double DroptempX, DroptempY, DroptempZ, CoordX, CoordY, CoordZ;
	double PathLengthLIz;
	bool dialogDisplayed;
	//sofa::component::collision::InjectorHandlingPipeline *HandlePipeline;
	int cubeCount;
	bool firstTouchObj;
	double lastx;
	double lastz;
	int numTimeSteps;
	bool visEffect;
	bool collisionContinue;
	bool objectChanged;
	SOFA_CLASS(ICSISimulationMetrics, sofa::core::BehaviorModel);
	//sofa::core::objectmodel::Data<float> m_myparam;
	void updatePosition(SReal dt);
	virtual void doCollisionResponse();
	ICSISimulationMetrics();
	~ICSISimulationMetrics();



};


#endif
