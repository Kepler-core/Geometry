#pragma once
#include "memoryleakdetect.h"
#include "geo_base.hpp"
#include "feature.h"

#include <vector>

class SpatialIndex {
public:
    SpatialIndex() {}
    virtual ~SpatialIndex() {};

    // Point query
    // construct a square
    // x, y:        square's central point
    // halfEdge:    a half of rectangle's length of side
    virtual void queryFeature(double x, double y, double halfEdge, GeoFeature*& featureResult) = 0;

    // box query
    virtual void queryFeatures(const GeoExtent& extent, std::vector<GeoFeature*>& featuresResult) = 0;
};
