#ifndef CAPILLARYMICROCELLINJECTIONMETRICS_H
#define CAPILLARYMICROCELLINJECTIONMETRICS_H
#include < time.h >
#include<ctime>

#include <sofa/component/typedef/MechanicalState_double.h>
#include <sofa/core/objectmodel/BaseObject.h>
#include <sofa/core/BehaviorModel.h>
#include <sofa/simulation/PipelineImpl.h>
#include <sofa/simulation/Node.h>

namespace sofa {

	namespace component
	{
		namespace container
		{
			class CapillaryMicroCellInjectionMetrics : public sofa::core::BehaviorModel


			{
			public:
				sofa::component::container::MechanicalObject<sofa::defaulttype::Vec3dTypes>::Coord distLI;
				sofa::component::container::MechanicalObject<sofa::defaulttype::Vec3dTypes>::Coord distLI2;
				sofa::component::container::MechanicalObject<sofa::defaulttype::Vec3dTypes>::Coord distLI3;
				sofa::component::container::MechanicalObject<sofa::defaulttype::Vec1dTypes>*Vec1dObjectVariable1;
				sofa::core::behavior::MechanicalState<sofa::defaulttype::RigidTypes>* Boxinstrument;
				sofa::core::behavior::MechanicalState<sofa::defaulttype::RigidTypes>* Dropinstrument;
				sofa::core::behavior::MechanicalState<sofa::defaulttype::RigidTypes>* Coordinstrument;
				sofa::component::container::MechanicalObject<sofa::defaulttype::Vec3dTypes>::Coord DropdistLI;
				/*
				sofa::core::behavior::MechanicalState<sofa::defaulttype::Vec3dTypes>* BoxROI1;
				sofa::core::behavior::MechanicalState<sofa::defaulttype::Vec3dTypes>* BoxROI2;
				sofa::core::behavior::MechanicalState<sofa::defaulttype::Vec3dTypes>* BoxROI3;
				sofa::core::behavior::MechanicalState<sofa::defaulttype::RigidTypes>* HoldRigid;

				sofa::component::container::MechanicalObject<sofa::defaulttype::Vec1dTypes>::Coord distance1;
				sofa::component::container::MechanicalObject<sofa::defaulttype::Vec1dTypes>::Coord distance2;
				sofa::component::container::MechanicalObject<sofa::defaulttype::Vec1dTypes>::Coord distance3;
				sofa::component::container::MechanicalObject<sofa::defaulttype::Vec1dTypes>::Coord distance01;
				sofa::component::container::MechanicalObject<sofa::defaulttype::Vec1dTypes>::Coord distance02;
				sofa::component::container::MechanicalObject<sofa::defaulttype::Vec1dTypes>::Coord distance03;
				sofa::component::container::MechanicalObject<sofa::defaulttype::Vec3dTypes>* cyto1;
				sofa::component::container::MechanicalObject<sofa::defaulttype::Vec1dTypes>*Vec1dObjectfordrop;
				*/
				sofa::component::container::MechanicalObject<sofa::defaulttype::Vec3dTypes>* box1;
				sofa::core::behavior::MechanicalState<sofa::defaulttype::Vec3dTypes>* holdingbox1;
				sofa::core::behavior::MechanicalState<sofa::defaulttype::Vec3dTypes>* holdingdrop1;
				int startFlag3;
				int startFlag;
				int startFlag2;
				double PathLengthLI2;
				double PathLengthLI;

				double PathLengthBox1;
				double PathLengthLIAccuracy;
				double PathLengthLIAccuracy2;
				double PathLengthLIAccuracy3;
				double PathLength2;
				double DropPathLengthLI;
				double tempxL, tempyL, tempzL;
				double DroptempX, DroptempY, DroptempZ, CoordX, CoordY, CoordZ;
				//double time_diff;
				int count;
				DWORD dw1;
				int accuracyCounter;
				sofa::simulation::Node::SPtr groot;
				sofa::component::container::MechanicalObject<sofa::defaulttype::Vec1dTypes>*Vec1dObjectVariablePointer1;
				SOFA_CLASS(CapillaryMicroCellInjectionMetrics, sofa::core::BehaviorModel);
				//sofa::core::objectmodel::Data<float> m_myparam;
				void updatePosition(SReal dt);
				virtual void doCollisionResponse();
				
				CapillaryMicroCellInjectionMetrics();
				~CapillaryMicroCellInjectionMetrics();



			};


		}
	}

}






#endif