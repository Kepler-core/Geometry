#pragma once
#include "rasterBand.h"
#include <vector>


class GeoRasterData {
public:
    GeoRasterData() {}
    GeoRasterData(const GeoRasterData& rhs);
    virtual ~GeoRasterData();

    int getBandsCount() const { return bands.size(); }
    GeoRasterBand* getBand(int idx) const { return bands[idx]; }
    GeoExtent getExtent() const;

    void addBand(GeoRasterBand* band);

    void Draw() const;

    std::vector<GeoRasterBand*>::iterator begin() { return bands.begin(); }
    std::vector<GeoRasterBand*>::iterator end() { return bands.end(); }

private:
    std::vector<GeoRasterBand*> bands;
};