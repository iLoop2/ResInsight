/////////////////////////////////////////////////////////////////////////////////
//
//  Copyright (C) Statoil ASA, Ceetron Solutions AS
// 
//  ResInsight is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
// 
//  ResInsight is distributed in the hope that it will be useful, but WITHOUT ANY
//  WARRANTY; without even the implied warranty of MERCHANTABILITY or
//  FITNESS FOR A PARTICULAR PURPOSE.
// 
//  See the GNU General Public License at <http://www.gnu.org/licenses/gpl.html> 
//  for more details.
//
/////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "cvfStructGridScalarDataAccess.h"
#include "RifReaderInterface.h"


class RigActiveCellInfo;
class RigGridBase;
class RigResultAccessor;

class RigResultAccessorFactory
{
public:
    static cvf::ref<RigResultAccessor> 
        createResultAccessor(RigCaseData* eclipseCase,
        size_t gridIndex,
        RifReaderInterface::PorosityModelResultType porosityModel,
        size_t timeStepIndex,
        const QString& uiResultName);


    // TO BE DELETED
    static cvf::ref<cvf::StructGridScalarDataAccess> 
        TO_BE_DELETED_createNativeDataAccessObject(RigCaseData* eclipseCase,
        size_t gridIndex,
        RifReaderInterface::PorosityModelResultType porosityModel,
        size_t timeStepIndex,
        size_t scalarSetIndex);


private:
    static cvf::ref<RigResultAccessor> 
        createNativeResultAccessor(RigCaseData* eclipseCase,
                                        size_t gridIndex,
                                        RifReaderInterface::PorosityModelResultType porosityModel,
                                        size_t timeStepIndex,
                                        const QString& resultName);


};

