#ifndef LOD_H
#define LOD_H

#include "TerrainMap.h"
#include "Path.h"

class Lod : public Path {
    public:
        Lod(TerrainMap& m, std::string name_in, Point start_in, Point finish_in);
        bool find();
};

#endif