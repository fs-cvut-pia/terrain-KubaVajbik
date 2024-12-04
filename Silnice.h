#ifndef SILNICE_H
#define SILNICE_H

#include "TerrainMap.h"
#include "Path.h"

class Silnice : public Path {
    public:
        Silnice(TerrainMap& m, std::string name_in, Point start_in, Point finish_in);
        bool find();
};

#endif