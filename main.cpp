#include <glog/logging.h>
#include "geometry.h"
int main(int argc, char** argv) {
    gflags::ParseCommandLineFlags(&argc, &argv, true);
    google::InitGoogleLogging(argv[0]);
    LOG(INFO) << "This is INFO log information";
    LOG(WARNING) << "This is WARNING log information";
    LOG(ERROR) << "This is ERROR log information";
    //LOG(FATAL) << "This is FATAL log information";

    LOG_IF(INFO, 1 < 2) << "This is true: 1 < 2. ";
    for (int i = 0; i < 100; ++i)
    {
        LOG_EVERY_N(INFO, 10) << "Log every 10 times. ";
    }


    CHECK(1 < 2) << "The world is end, because one is not less than  2. ";
    Vector2f vec2f(1.0, 2.0);
    Vector3f vec3f(-1.0, 20., 3.0);
    Point3f pot3f(1.0, 2.0, 3.0);
    Point3f pot3f1(-1.0, 4.0, 5.0);
    Normal3f n3f(2.0, 1.0, -1.0);
    std::cout << n3f << Normalize(n3f) << std::endl;
    std::cout << Lerp(0.5, pot3f, pot3f1) << std::endl;
    std::cout << vec2f << vec3f;
    return 0;
}
