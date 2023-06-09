#pragma once
#include "field.h"
#include "Geometry.h"

#include <QString>


enum LayerStyleMode {
    kSingleStyle = 0,
    kCategorized = 1,
    kRuleBased = 2
};


class GeoFeatureLayerProperty {
public:
    GeoFeatureLayerProperty() = default;
    ~GeoFeatureLayerProperty() = default;

    void setName(const QString& nameIn) { name = nameIn; }

    GeometryType getGeometryType() const { return geometryType; }
    void setGeometryType(GeometryType geometryTypeIn);

public:
    bool visible = true;
    int id = 0;
    QString name;
    GeoExtent extent;
    QString spatialRef;
    LayerStyleMode styleMode = kSingleStyle;
private:
    GeometryType geometryType = kGeometryTypeUnknown;
};
