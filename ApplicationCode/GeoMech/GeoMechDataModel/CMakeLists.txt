cmake_minimum_required (VERSION 2.8)

project (RigGeoMechDataModel)

include_directories(
	${LibCore_SOURCE_DIR}
	../../ResultStatisticsCache
	../OdbReader
)


add_library( ${PROJECT_NAME}
	RigFemPart.h
	RigFemPart.cpp
	RigFemTypes.h
	RigFemTypes.cpp
	RigGeoMechCaseData.cpp
	RigGeoMechCaseData.h
	RigFemPartCollection.cpp
	RigFemPartCollection.h
	RigFemPartResults.h
	RigFemPartResults.cpp
	RigFemScalarResultFrames.h
	RigFemScalarResultFrames.cpp
	RigFemNativeStatCalc.h
	RigFemNativeStatCalc.cpp
)

target_link_libraries( ${PROJECT_NAME} LibCore ResultStatisticsCache)