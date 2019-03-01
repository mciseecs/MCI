#include "SphereHandlingMetrics.h"
#include <sofa/core/ObjectFactory.h>
#include <iostream>
#include < time.h >
#include <ctime>
#include <cmath>
SOFA_DECL_CLASS(SphereHandlingMetrics)

SphereHandlingMetrics::SphereHandlingMetrics()
{
        count = 1;

}

SphereHandlingMetrics::~SphereHandlingMetrics()
{

}


void SphereHandlingMetrics::doCollisionResponse()
{
}



void SphereHandlingMetrics::updatePosition(SReal dt)
{
        //clock_t start = clock();
        // Execuatable code
        //clock_t stop = clock();
        //double elapsed = (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC;
        //double seconds = elapsed / 1000;
        //std::cout << "Time elapsed in seconds:" << seconds;
     // DWORD dw1 = GetTickCount();

        ////Do something

        if (count == 1 )
        {
                dw1 = GetTickCount();
                count++;
        }

DWORD dw2 = GetTickCount();

        double time_diff = dw2 - dw1;
        double time = (time_diff) / CLOCKS_PER_SEC;
        //std::cout << "Total run time is:" << time << "Seconds\n";

int y = ceil(time);
std::cout << "time is :" <<y<< "seconds\n";

}

        int MySphereHandlingMetricsClass = sofa::core::RegisterObject("This component does nothing.").add<SphereHandlingMetrics>();