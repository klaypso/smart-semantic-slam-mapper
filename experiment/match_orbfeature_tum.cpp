#include "common_headers.h"
#include "parameter_reader.h"
#include "rgbdframe.h"
#include "orb.h"

#include <opencv2/features2d/features2d.hpp>
#include <cstdlib>

#include "Thirdparty/orbslam_modified/include/ORBextractor.h"

using namespace std;
using namespace rgbd_tutor;

int main()
{
    cout<<"running orbfeature_tum"<<endl;
    ParameterReader para;
    FrameReader frameReader( para );
    