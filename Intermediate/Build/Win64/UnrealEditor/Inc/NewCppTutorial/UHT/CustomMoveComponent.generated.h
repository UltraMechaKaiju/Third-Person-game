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

#define FID_NewCppTutorial_Source_NewCppTutorial_CustomMoveComponent_h_27_SPARSE_DATA
#define FID_NewCppTutorial_Source_NewCppTutorial_CustomMoveComponent_h_27_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_NewCppTutorial_Source_NewCppTutorial_CustomMoveComponent_h_27_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_NewCppTutorial_Source_NewCppTutorial_CustomMoveComponent_h_27_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execIsRailGrinding); \
	DECLARE_FUNCTION(execSpeedCheck); \
	DECLARE_FUNCTION(execWallRunningIsRight); \
	DECLARE_FUNCTION(execIsWallRunning); \
	DECLARE_FUNCTION(execIsCustomMovementMode); \
	DECLARE_FUNCTION(execSprintReleased); \
	DECLARE_FUNCTION(execSprintPressed);


#define FID_NewCppTutorial_Source_NewCppTutorial_CustomMoveComponent_h_27_ACCESSORS
#define FID_NewCppTutorial_Source_NewCppTutorial_CustomMoveComponent_h_27_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUCustomMoveComponent(); \
	friend struct Z_Construct_UClass_UCustomMoveComponent_Statics; \
public: \
	DECLARE_CLASS(UCustomMoveComponent, UCharacterMovementComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/NewCppTutorial"), NO_API) \
	DECLARE_SERIALIZER(UCustomMoveComponent)


#define FID_NewCppTutorial_Source_NewCppTutorial_CustomMoveComponent_h_27_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UCustomMoveComponent(UCustomMoveComponent&&); \
	NO_API UCustomMoveComponent(const UCustomMoveComponent&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UCustomMoveComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCustomMoveComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UCustomMoveComponent) \
	NO_API virtual ~UCustomMoveComponent();


#define FID_NewCppTutorial_Source_NewCppTutorial_CustomMoveComponent_h_24_PROLOG
#define FID_NewCppTutorial_Source_NewCppTutorial_CustomMoveComponent_h_27_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_NewCppTutorial_Source_NewCppTutorial_CustomMoveComponent_h_27_SPARSE_DATA \
	FID_NewCppTutorial_Source_NewCppTutorial_CustomMoveComponent_h_27_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_NewCppTutorial_Source_NewCppTutorial_CustomMoveComponent_h_27_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_NewCppTutorial_Source_NewCppTutorial_CustomMoveComponent_h_27_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_NewCppTutorial_Source_NewCppTutorial_CustomMoveComponent_h_27_ACCESSORS \
	FID_NewCppTutorial_Source_NewCppTutorial_CustomMoveComponent_h_27_INCLASS_NO_PURE_DECLS \
	FID_NewCppTutorial_Source_NewCppTutorial_CustomMoveComponent_h_27_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> NEWCPPTUTORIAL_API UClass* StaticClass<class UCustomMoveComponent>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_NewCppTutorial_Source_NewCppTutorial_CustomMoveComponent_h


#define FOREACH_ENUM_ECUSTOMMOVEMENTMODE(op) \
	op(CMOVE_None) \
	op(CMOVE_WallRun) \
	op(CMOVE_RailGrind) \
	op(CMOVE_Max) 
PRAGMA_ENABLE_DEPRECATION_WARNINGS
