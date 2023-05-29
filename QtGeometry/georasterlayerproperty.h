#pragma once
#include <QString>

#include "geo_base.hpp"


class GeoRasterLayerProperty 
{
public:
    GeoRasterLayerProperty() {}
    ~GeoRasterLayerProperty() {}

    bool visible = true;
    int id = 0;
    QString name;
    GeoExtent extent;
};
