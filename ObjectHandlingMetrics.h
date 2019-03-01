#ifndef OBJECTHANDLINGMETRICS_H
#define OBJECTHANDLINGMETRICS_H
#include < time.h >
#include<ctime>
#include <sofa/core/objectmodel/BaseObject.h>
#include <sofa/core/BehaviorModel.h>
#include <sofa/simulation/PipelineImpl.h>
#include <sofa/simulation/Node.h>
#include <winsqlite\winsqlite3.h>
#include <C:\sofa\build\applications\plugins\EvaluationMetrixx\sqlite3.h>
#include <qtablewidget.h>
#include <QTableView.h>
#include <QtSql\qsqldatabase.h>
#include <QtSql\qsqltablemodel.h>
#include <QMessageBox>
#include <qdesktopwidget.h>
#include <qapplication.h>
#include <QtCore>
#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QTableview.h>
#include <QHeaderView>

#include <QTime>
#include <string>
#include <sofa/core/ObjectFactory.h>
#include <sofa/core/objectmodel/KeypressedEvent.h>

#include <sofa/core/objectmodel/Event.h>
#include <sofa/core/core.h>
#include <sofa/component/typedef/MechanicalState_double.h>
#include <sofa/core/objectmodel/BaseObject.h>
#include <sofa/core/BehaviorModel.h>
#include "C:\sofa\src\applications\plugins\ExercisePipeline\ObjectHandlingPipeline.h"
#include <sofa/simulation/PipelineImpl.h>


class ObjectHandlingMetrics:  public sofa::core::BehaviorModel
{
public:      
	sofa::component::container::MechanicalObject<sofa::defaulttype::Vec3dTypes>::Coord distLI;

	//double time_diff;

	sofa::core::behavior::MechanicalState<sofa::defaulttype::Vec3dTypes>* holdingCollision;
	sofa::component::collision::ObjectHandlingPipeline *HandlePipeline;
        int count;
        DWORD dw1;
		int startFlag;
		double PathLengthLI;
		double tempxL, tempyL, tempzL;
		bool collisionContinue;
		
       SOFA_CLASS(ObjectHandlingMetrics, sofa::core::BehaviorModel);
        //sofa::core::objectmodel::Data<float> m_myparam;
         void updatePosition(SReal dt) ;
		 
		 bool dialogDisplayed;

         virtual void doCollisionResponse();
        ObjectHandlingMetrics();
        ~ObjectHandlingMetrics();
};


#endif