#include "ObjectHandlingMetrics.h"
#include <sofa/core/ObjectFactory.h>
#include <iostream>
#include < time.h >
#include <ctime>
#include <cmath>
#include <winsqlite/winsqlite3.h>
#include <qtableview.h>
#include <iostream>
#include < time.h >
#include <ctime>
#include <cmath>
#include <sofa/simulation/Node.h>
#include <winsqlite\winsqlite3.h>
#include <sql.h>
#include <QtSql\qsqltablemodel.h>
#include "dialog.h"
#include "ui_dialog.h"


SOFA_DECL_CLASS(ObjectHandlingMetrics)

ObjectHandlingMetrics::ObjectHandlingMetrics()
{
	count = 1;
	startFlag = 0;
	PathLengthLI = 0.0;
	HandlePipeline = NULL;
	
	
}

ObjectHandlingMetrics::~ObjectHandlingMetrics()
{

}


void ObjectHandlingMetrics::doCollisionResponse()
{
}



void ObjectHandlingMetrics::updatePosition(SReal dt)
{
	//clock_t start = clock();
	// Execuatable code
	//clock_t stop = clock();
	//double elapsed = (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC;
	//double seconds = elapsed / 1000;
	//std::cout << "Time elapsed in seconds:" << seconds;
	// DWORD dw1 = GetTickCount();

	////Do something

	if (count == 1)
	{
		dw1 = GetTickCount();
		count++;
	}

	DWORD dw2 = GetTickCount();

	double time_diff = dw2 - dw1;
	double time = (time_diff) / CLOCKS_PER_SEC;
	//std::cout << "Total run time is:" << time << "Seconds\n";

	int y = ceil(time);
	std::cout << "time is :" << y << "seconds\n";
	
	//for distance
	sofa::core::objectmodel::BaseContext*scene = getContext();

	sofa::simulation::Node* node = dynamic_cast<sofa::simulation::Node*> (scene);
	sofa::core::behavior::MechanicalState<sofa::defaulttype::RigidTypes>* LapLi = NULL;
	std::vector<sofa::core::behavior::MechanicalState<sofa::defaulttype::RigidTypes>*>instruments;
	node->getTreeObjects<sofa::core::behavior::MechanicalState<sofa::defaulttype::RigidTypes>, std::vector<sofa::core::behavior::MechanicalState<sofa::defaulttype::RigidTypes>*>>(&instruments);



	if (!instruments.empty())
	{
		LapLi = instruments[0];
	}
	if (startFlag == 0)
	{
		distLI[0] = (LapLi->readPositions())[0][0];
		distLI[1] = (LapLi->readPositions())[0][1];
		distLI[2] = (LapLi->readPositions())[0][2];
		startFlag = 1;

	}
	else
	{
		if (startFlag == 1) {
			distLI[0] = abs((LapLi->readPositions())[0][0]) - abs(distLI[0]);
			distLI[1] = abs((LapLi->readPositions())[0][1]) - abs(distLI[1]);
			distLI[2] = abs((LapLi->readPositions())[0][2]) - abs(distLI[2]);
			startFlag = 2;
			tempxL = abs((LapLi->readPositions())[0][0]);
			tempyL = abs((LapLi->readPositions())[0][1]);
			tempzL = abs((LapLi->readPositions())[0][2]);
		}
		else
		{
			if (tempxL != abs((LapLi->readPositions())[0][0]) || tempyL != abs((LapLi->readPositions())[0][1]) || tempzL != abs((LapLi->readPositions())[0][2])) {
				distLI[0] = abs((LapLi->readPositions())[0][0]) - abs(distLI[0]);
				distLI[1] = abs((LapLi->readPositions())[0][1]) - abs(distLI[1]);
				distLI[2] = abs((LapLi->readPositions())[0][2]) - abs(distLI[2]);

			}
		}
		tempxL = abs((LapLi->readPositions())[0][0]);
		tempyL = abs((LapLi->readPositions())[0][1]);
		tempzL = abs((LapLi->readPositions())[0][2]);

		PathLengthLI = PathLengthLI + sqrt((distLI[0] * distLI[0]) + (distLI[1] * distLI[1]) + (distLI[2] * distLI[2]));
		//std::cout << "distance covered is: \n" << PathLengthLI;
		//int Trajectory = PathLengthLI;
		std::cout << "The Distance covered is: " << PathLengthLI;
		sofa::simulation::Node* rootNode = dynamic_cast<sofa::simulation::Node*> (scene);
	
		
		 HandlePipeline = rootNode->getTreeObject<sofa::component::collision::ObjectHandlingPipeline>();
		if (HandlePipeline->collisionContinue == false)
		{
			
			this->getContext()->getRootContext()->setAnimate(false);
			std::cout << "animation is stopped";
			if (!dialogDisplayed)
			{
				Dialog* w = new Dialog();
				w->exec();
				dialogDisplayed = true;
			}
			
			}

		

		else
		{

			std::cout << "cant stop";
			
		}

	}
	

}
/*
sqlite3 *db;

char *err_message = 0;

char *zErrMsg = 0;



int rc = sqlite3_open("MCIDatabase.db", &db);
std::ostringstream temp;
std::string command;

//std::ostringstream  temp.str("");
char *sql = "INSERT INTO Performance(Time, Distance)" "VALUES (77, 133234.8 );";
//std::string command = temp.str();
int  rcd = sqlite3_exec(db, sql, 0, 0, &zErrMsg);

*/
int MyObjectHandlingMetricsClass = sofa::core::RegisterObject("This component does nothing.").add<ObjectHandlingMetrics>();
