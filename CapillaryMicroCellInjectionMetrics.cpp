#include "CapillaryMicroCellInjectionMetrics.h"
#include <sofa/core/ObjectFactory.h>
#include <iostream>
#include < time.h >
#include <ctime>
#include <cmath>
#include <SofaSimulationTree/TreeSimulation.h>
#include <sofa/helper/gl/glText.inl>
#include <sofa/helper/system/gl.h>
#include <sofa/helper/system/glu.h>
#include <sofa/simulation/Simulation.h>
#include <sofa/helper/gl/glText.inl>
#include <sofa/helper/gl/Axis.h>
#include <sofa/helper/gl/RAII.h>
#include <SofaEngine/BoxROI.inl>
#include <SofaOpenglVisual/Light.h>
#include <sofa/simulation/Node.h>
#include <SofaSimulationTree/TreeSimulation.h>
#include <sofa/defaulttype/Vec.h>
namespace sofa {

	namespace component {

		namespace container {


			SOFA_DECL_CLASS(CapillaryMicroCellInjectionMetrics)

				CapillaryMicroCellInjectionMetrics::CapillaryMicroCellInjectionMetrics()
			{
				int startFlag2;
				count = 1;
				startFlag = 0;
				PathLengthLI = 0.0;
				accuracyCounter = 0.0;
				startFlag2 = 0;
				startFlag3 = 0;
			}
			CapillaryMicroCellInjectionMetrics::~CapillaryMicroCellInjectionMetrics()
			{

			}

			void CapillaryMicroCellInjectionMetrics::doCollisionResponse()
			{
			}

			void CapillaryMicroCellInjectionMetrics::updatePosition(SReal dt)
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
				core::objectmodel::BaseContext*scene = getContext();

				simulation::Node* node = dynamic_cast<simulation::Node*> (scene);
				sofa::core::behavior::MechanicalState<sofa::defaulttype::RigidTypes>* LapLi = NULL;
				std::vector<sofa::core::behavior::MechanicalState<sofa::defaulttype::RigidTypes>*>instruments;
				node->getTreeObjects<sofa::core::behavior::MechanicalState<sofa::defaulttype::RigidTypes>, std::vector<sofa::core::behavior
					::MechanicalState<sofa::defaulttype::RigidTypes>*>>(&instruments);
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
					//std::cout << "distance covered by pipette is: \n" << PathLengthLI;


				}

				//for accuracy

				//access drop node now
				sofa::simulation::Node * getDrop = NULL;
				sofa::simulation::Node * getPipette = NULL;


				getPipette = node->getTreeNode("Pipette");
				getDrop = getPipette->getTreeNode("node8");



				sofa::component::container::MechanicalObject<sofa::defaulttype::Rigid3dTypes>*DropLapLi = NULL;
				std::vector<sofa::component::container::MechanicalObject<sofa::defaulttype::Rigid3dTypes>*>Dropinstruments;
				getDrop->getTreeObjects<sofa::component::container::MechanicalObject<sofa::defaulttype::Rigid3dTypes>,
					std::vector<sofa::component::container::MechanicalObject<sofa::defaulttype::Rigid3dTypes>*>>(&Dropinstruments);




				if (!Dropinstruments.empty())
				{
					DropLapLi = Dropinstruments[0];

				}
				if (startFlag2 == 0)
				{
					distLI2[0] = (DropLapLi->readPositions())[0][0];
					distLI2[1] = (DropLapLi->readPositions())[0][1];
					distLI2[2] = (DropLapLi->readPositions())[0][2];

					startFlag2 = 1;

				}
				else
				{
					if (startFlag2 == 1) {

						DroptempX = abs((DropLapLi->readPositions())[0][0]);
						DroptempY = abs((DropLapLi->readPositions())[0][1]);
						DroptempZ = abs((DropLapLi->readPositions())[0][2]);

					}
					else
					{
						DroptempX = abs((DropLapLi->readPositions())[0][0]);
						DroptempY = abs((DropLapLi->readPositions())[0][1]);
						DroptempZ = abs((DropLapLi->readPositions())[0][2]);


					}


					//std::cout << "Dropis now at " << DroptempX;
					//std::cout << "Dropis now at " << DroptempY;
					//std::cout << "Dropis now at " << DroptempZ;

				}


				//for coord




				sofa::simulation::Node * getcoord1 = NULL;
				sofa::simulation::Node * getcoord2 = NULL;
				simulation::Node* node2 = dynamic_cast<simulation::Node*> (scene);


				getcoord1 = node2->getTreeNode("Coord");
				getcoord2 = getcoord1->getTreeNode("node08");


				sofa::core::behavior::MechanicalState<sofa::defaulttype::Rigid3dTypes>*CoordLapLi = NULL;
				std::vector<sofa::core::behavior::MechanicalState<sofa::defaulttype::Rigid3dTypes>*>Coordinstruments;
				getcoord2->getTreeObjects<sofa::core::behavior::MechanicalState<sofa::defaulttype::Rigid3dTypes>, std::vector<sofa::core::behavior
					::MechanicalState<sofa::defaulttype::Rigid3dTypes>*>>(&Coordinstruments);



				if (!Coordinstruments.empty())
				{
					CoordLapLi = Coordinstruments[0];
				}
				if (startFlag3 == 0)
				{
					distLI3[0] = (CoordLapLi->readPositions())[0][0];
					distLI3[1] = (CoordLapLi->readPositions())[0][1];
					distLI3[2] = (CoordLapLi->readPositions())[0][2];
					startFlag3 = 1;

				}
				else
				{
					CoordX = abs((CoordLapLi->readPositions())[0][0]);
					CoordY = abs((CoordLapLi->readPositions())[0][1]);
					CoordZ = abs((CoordLapLi->readPositions())[0][2]);


				}


				//std::cout << "second Dropis now at " << CoordX;
				//std::cout << "second Dropis now at " << CoordY;
				//std::cout << "secomd Dropis now at " << CoordZ;





				PathLengthLI2 = sqrt((CoordZ * CoordZ) - (DroptempZ * DroptempZ));



				int dist = ceil(PathLengthLI2);
				//std::cout << "path value" << dist;

				switch (dist)
				{
				case  15:
					std::cout << "Hold the cell, move a little forward for injection (move towards cell)" << accuracyCounter++;;
					break;
				case  16:
					std::cout << "Accuracy is increasing, move a little forward for injection (move towards cell)" << accuracyCounter++;
					break;
				case  17:
					std::cout << "Accuracy is highest, kindly inject here" << accuracyCounter++;
					break;
				case  18:
					std::cout << "Accuracy is highest, kindly inject here" << accuracyCounter++;
					break;
				case  19:
					std::cout << "Accuracy is highest, kindly inject here" << accuracyCounter++;
					break;
				default:
					std::cout << "Hold the cell, Accuracy is low, move to the cell center" << accuracyCounter--;
					break;
				}




				/* if (ceil(PathLengthLI2) == 17 || 16 )
				{

				std::cout << "Move forward to the center, accuracy is:\n" << accuracyCounter++;
				}

				else if (ceil(PathLengthLI2) == 18 || 19)
				{
				std::cout << "Accuracy is highest, kindly insert into the cell:\n" << accuracyCounter++;

				}

				else if (ceil(PathLengthLI2) < 18 || ceil(PathLengthLI2) > 19)
				{
				std::cout << "Accuracy is decreasing, kindly move the pipette towards center of cell:\n" << accuracyCounter++;
				}

				*/
			}
			int MyCapillaryMicroCellInjectionMetricsClass = sofa::core::RegisterObject("This component does nothing.").add<CapillaryMicroCellInjectionMetrics>();

		}

	}



}

