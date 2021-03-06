/////////////////////////////////////////////////////////////////////////////////
//
//  Copyright (C) Statoil ASA
//  Copyright (C) Ceetron Solutions AS
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
#include "cvfBase.h"
#include "cvfObject.h"

#include "RigGridBase.h"
#include "RimFault.h"
#include "RivFaultGeometryGenerator.h"
#include "cvfColor4.h"
#include "RivNNCGeometryGenerator.h"
#include "cvfEffect.h"
#include "cafEffectGenerator.h"

namespace cvf
{
    class StructGridInterface;
    class ModelBasicList;
    class Transform;
    class Part;
}

class RimResultSlot;
class RimCellEdgeResultSlot;
class RimFaultCollection;

//==================================================================================================
///
///
//==================================================================================================

class RivFaultPartMgr : public cvf::Object
{
public:
    RivFaultPartMgr(const RigGridBase* grid, const RimFaultCollection* rimFaultCollection, const RimFault* rimFault);

    void setCellVisibility(cvf::UByteArray* cellVisibilities);

    void applySingleColorEffect();
    void setOpacityLevel(float opacity) { m_opacityLevel = opacity; }
    void updateCellResultColor(size_t timeStepIndex, RimResultSlot* cellResultSlot);
    void updateCellEdgeResultColor(size_t timeStepIndex, RimResultSlot* cellResultSlot, RimCellEdgeResultSlot* cellEdgeResultSlot);

    void appendNativeFaultFacesToModel(cvf::ModelBasicList* model);
    void appendOppositeFaultFacesToModel(cvf::ModelBasicList* model);
    void appendNNCFacesToModel(cvf::ModelBasicList* model);
    void appendLabelPartsToModel(cvf::ModelBasicList* model);
    void appendMeshLinePartsToModel(cvf::ModelBasicList* model);

private:
    void generatePartGeometry();
    void updatePartEffect();

    void updateNNCColors(RimResultSlot* cellResultSlot);

    caf::FaceCulling faceCullingMode() const;
    
    void createLabelWithAnchorLine(const cvf::Part* part);
   
    static cvf::Vec3f findClosestVertex(const cvf::Vec3f& point, const cvf::Vec3fArray* vertices);
private:
    cvf::cref<RigGridBase>      m_grid;
    const RimFault*             m_rimFault;
    const RimFaultCollection*   m_rimFaultCollection;

    float                       m_opacityLevel;
    cvf::Color3f                m_defaultColor;

    bool                        m_showNativeFaces;
    bool                        m_showOppositeFaces;
    bool                        m_showLabel;

    cvf::ref<cvf::UByteArray>   m_cellVisibility;

    cvf::ref<RivFaultGeometryGenerator>   m_nativeFaultGenerator;
    cvf::ref<cvf::Part>         m_nativeFaultFaces;
    cvf::ref<cvf::Part>         m_nativeFaultGridLines;
    cvf::ref<cvf::Vec2fArray>   m_nativeFaultFacesTextureCoords;

    cvf::ref<RivFaultGeometryGenerator>   m_oppositeFaultGenerator;
    cvf::ref<cvf::Part>         m_oppositeFaultFaces;
    cvf::ref<cvf::Part>         m_oppositeFaultGridLines;
    cvf::ref<cvf::Vec2fArray>   m_oppositeFaultFacesTextureCoords;

    cvf::ref<RivNNCGeometryGenerator>     m_NNCGenerator;
    cvf::ref<cvf::Part>         m_NNCFaces;
    cvf::ref<cvf::Vec2fArray>   m_NNCTextureCoords;
 
    cvf::ref<cvf::Part>         m_faultLabelPart;
    cvf::ref<cvf::Part>         m_faultLabelLinePart;
};
