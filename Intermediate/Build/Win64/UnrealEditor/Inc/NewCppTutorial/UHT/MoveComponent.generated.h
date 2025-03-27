// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "MoveComponent.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef NEWCPPTUTORIAL_MoveComponent_generated_h
#error "MoveComponent.generated.h already included, missing '#pragma once' in MoveComponent.h"
#endif
#define NEWCPPTUTORIAL_MoveComponent_generated_h

#define FID_NewCppTutorial_Source_NewCppTutorial_MoveComponent_h_10_DELEGATE \
NEWCPPTUTORIAL_API void FOnMoveComponentEndPointReachedSignature_DelegateWrapper(const FMulticastScriptDelegate& OnMoveComponentEndPointReachedSignature, bool IsTopEndpoint);


#define FID_NewCppTutorial_Source_NewCppTutorial_MoveComponent_h_15_SPARSE_DATA
#define FID_NewCppTutorial_Source_NewCppTutorial_MoveComponent_h_15_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_NewCppTutorial_Source_NewCppTutorial_MoveComponent_h_15_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_NewCppTutorial_Source_NewCppTutorial_MoveComponent_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execSetDirection); \
	DECLARE_FUNCTION(execMoveReset); \
	DECLARE_FUNCTION(execEnableMovement);


#define FID_NewCppTutorial_Source_NewCppTutorial_MoveComponent_h_15_ACCESSORS
#define FID_NewCppTutorial_Source_NewCppTutorial_MoveComponent_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUMoveComponent(); \
	friend struct Z_Construct_UClass_UMoveComponent_Statics; \
public: \
	DECLARE_CLASS(UMoveComponent, USceneComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/NewCppTutorial"), NO_API) \
	DECLARE_SERIALIZER(UMoveComponent)


#define FID_NewCppTutorial_Source_NewCppTutorial_MoveComponent_h_15_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UMoveComponent(UMoveComponent&&); \
	NO_API UMoveComponent(const UMoveComponent&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UMoveComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UMoveComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UMoveComponent) \
	NO_API virtual ~UMoveComponent();


#define FID_NewCppTutorial_Source_NewCppTutorial_MoveComponent_h_12_PROLOG
#define FID_NewCppTutorial_Source_NewCppTutorial_MoveComponent_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_NewCppTutorial_Source_NewCppTutorial_MoveComponent_h_15_SPARSE_DATA \
	FID_NewCppTutorial_Source_NewCppTutorial_MoveComponent_h_15_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_NewCppTutorial_Source_NewCppTutorial_MoveComponent_h_15_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_NewCppTutorial_Source_NewCppTutorial_MoveComponent_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_NewCppTutorial_Source_NewCppTutorial_MoveComponent_h_15_ACCESSORS \
	FID_NewCppTutorial_Source_NewCppTutorial_MoveComponent_h_15_INCLASS_NO_PURE_DECLS \
	FID_NewCppTutorial_Source_NewCppTutorial_MoveComponent_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> NEWCPPTUTORIAL_API UClass* StaticClass<class UMoveComponent>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_NewCppTutorial_Source_NewCppTutorial_MoveComponent_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
