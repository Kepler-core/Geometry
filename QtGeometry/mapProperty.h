#pragma once
#include "geo_base.hpp"

/*��ͼ����  ����+�߽�*/

#include <QString>


class GeoMapProperty 
{
public:
    GeoMapProperty() = default;
    ~GeoMapProperty() = default;

public:
    QString name = "untitled";
    GeoExtent extent;
};