// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "CustomMoveComponent.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef NEWCPPTUTORIAL_CustomMoveComponent_generated_h
#error "CustomMoveComponent.generated.h already included, missing '#pragma once' in CustomMoveComponent.h"
#endif
#define NEWCPPTUTORIAL_CustomMoveComponent_generated_h

#define FID_Unreal_engine_NewCppTutorial_Source_NewCppTutorial_CustomMoveComponent_h_28_SPARSE_DATA
#define FID_Unreal_engine_NewCppTutorial_Source_NewCppTutorial_CustomMoveComponent_h_28_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Unreal_engine_NewCppTutorial_Source_NewCppTutorial_CustomMoveComponent_h_28_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Unreal_engine_NewCppTutorial_Source_NewCppTutorial_CustomMoveComponent_h_28_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execIsRailGrinding); \
	DECLARE_FUNCTION(execSpeedCheck); \
	DECLARE_FUNCTION(execWallRunningIsRight); \
	DECLARE_FUNCTION(execIsWallRunning); \
	DECLARE_FUNCTION(execIsCustomMovementMode); \
	DECLARE_FUNCTION(execSprintReleased); \
	DECLARE_FUNCTION(execSprintPressed);


#define FID_Unreal_engine_NewCppTutorial_Source_NewCppTutorial_CustomMoveComponent_h_28_ACCESSORS
#define FID_Unreal_engine_NewCppTutorial_Source_NewCppTutorial_CustomMoveComponent_h_28_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUCustomMoveComponent(); \
	friend struct Z_Construct_UClass_UCustomMoveComponent_Statics; \
public: \
	DECLARE_CLASS(UCustomMoveComponent, UCharacterMovementComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/NewCppTutorial"), NO_API) \
	DECLARE_SERIALIZER(UCustomMoveComponent)


#define FID_Unreal_engine_NewCppTutorial_Source_NewCppTutorial_CustomMoveComponent_h_28_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UCustomMoveComponent(UCustomMoveComponent&&); \
	NO_API UCustomMoveComponent(const UCustomMoveComponent&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UCustomMoveComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCustomMoveComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UCustomMoveComponent) \
	NO_API virtual ~UCustomMoveComponent();


#define FID_Unreal_engine_NewCppTutorial_Source_NewCppTutorial_CustomMoveComponent_h_25_PROLOG
#define FID_Unreal_engine_NewCppTutorial_Source_NewCppTutorial_CustomMoveComponent_h_28_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Unreal_engine_NewCppTutorial_Source_NewCppTutorial_CustomMoveComponent_h_28_SPARSE_DATA \
	FID_Unreal_engine_NewCppTutorial_Source_NewCppTutorial_CustomMoveComponent_h_28_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Unreal_engine_NewCppTutorial_Source_NewCppTutorial_CustomMoveComponent_h_28_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Unreal_engine_NewCppTutorial_Source_NewCppTutorial_CustomMoveComponent_h_28_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Unreal_engine_NewCppTutorial_Source_NewCppTutorial_CustomMoveComponent_h_28_ACCESSORS \
	FID_Unreal_engine_NewCppTutorial_Source_NewCppTutorial_CustomMoveComponent_h_28_INCLASS_NO_PURE_DECLS \
	FID_Unreal_engine_NewCppTutorial_Source_NewCppTutorial_CustomMoveComponent_h_28_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> NEWCPPTUTORIAL_API UClass* StaticClass<class UCustomMoveComponent>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Unreal_engine_NewCppTutorial_Source_NewCppTutorial_CustomMoveComponent_h


#define FOREACH_ENUM_ECUSTOMMOVEMENTMODE(op) \
	op(CMOVE_None) \
	op(CMOVE_WallRun) \
	op(CMOVE_RailGrind) \
	op(CMOVE_Max) 
PRAGMA_ENABLE_DEPRECATION_WARNINGS
