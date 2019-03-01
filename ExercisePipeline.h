
#ifndef SOFA_COMPONENT_COLLISION_EXERCISEPIPELINE_H
#define SOFA_COMPONENT_COLLISION_EXERCISEPIPELINE_H
#include <sofa/defaulttype/defaulttype.h>
#include <sofa/core/collision/Detection.h>
#include <SofaBaseCollision/DefaultPipeline.h>
#include <sofa/helper/system/config.h>
#include <sofa/helper/system/gl.h>
#include <sofa/core/behavior/MechanicalState.h>
#include <sofa/defaulttype/VecTypes.h>
#include <sofa/helper/vector.h>
#include <sofa/helper/accessor.h>
#include <SofaBaseMechanics/UniformMass.h>
#include <sofa/core/objectmodel/BaseObject.h>
#include <sofa/core/BehaviorModel.h>
#include <sofa/simulation/PipelineImpl.h>
#include <sofa/defaulttype/defaulttype.h>
#include <sofa/core/collision/Detection.h>
#include <SofaBaseCollision/DefaultPipeline.h>
#include <sofa/helper/system/config.h>
#include <sofa/helper/system/gl.h>
#include <sofa/core/objectmodel/BaseObject.h>
#include <sofa/core/BehaviorModel.h>
#include <sofa/simulation/PipelineImpl.h>
namespace sofa
{

	namespace component
	{

		namespace collision
		{

			class  ExercisePipeline : public sofa::component::collision::DefaultPipeline
			{
			public:
				SOFA_CLASS(ExercisePipeline, sofa::component::collision::DefaultPipeline);

				int exerciseId;
				bool visEffect;
				bool collisionContinue;
				bool blockInstrument;
				bool blockSecondInstrument;
				bool detached;
				bool cameraLocked;
				bool displayText;

				int damageCount;
				int damageCountRight;
				int damageCountLeft;
				std::string dispText;
				bool warningText;

				int itemsRemaining;

				ExercisePipeline() : visEffect(false), collisionContinue(true), blockInstrument(false), blockSecondInstrument(false), detached(false),
					cameraLocked(false), displayText(false), dispText(" "), warningText(false), damageCount(0), damageCountRight(0),
					damageCountLeft(0), itemsRemaining(0) {};

				virtual std::string getText();

			protected:
				// -- Pipeline interface

				virtual void doCollisionResponse();

			};

		} // namespace collision

	} // namespace component

} // namespace sofa

#endif
