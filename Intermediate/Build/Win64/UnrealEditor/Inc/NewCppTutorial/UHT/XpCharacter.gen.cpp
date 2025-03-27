// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "NewCppTutorial/XpCharacter.h"
#include "InputActionValue.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeXpCharacter() {}
// Cross Module References
	CUSTOMMESHCOMPONENT_API UClass* Z_Construct_UClass_UCustomMeshComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_ACharacter();
	ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
	ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputAction_NoRegister();
	ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputMappingContext_NoRegister();
	ENHANCEDINPUT_API UScriptStruct* Z_Construct_UScriptStruct_FInputActionValue();
	NEWCPPTUTORIAL_API UClass* Z_Construct_UClass_AXpCharacter();
	NEWCPPTUTORIAL_API UClass* Z_Construct_UClass_AXpCharacter_NoRegister();
	NEWCPPTUTORIAL_API UClass* Z_Construct_UClass_UCustomMoveComponent_NoRegister();
	UPackage* Z_Construct_UPackage__Script_NewCppTutorial();
// End Cross Module References
	DEFINE_FUNCTION(AXpCharacter::execEnhancedMovement)
	{
		P_GET_STRUCT_REF(FInputActionValue,Z_Param_Out_value);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->EnhancedMovement(Z_Param_Out_value);
		P_NATIVE_END;
	}
	void AXpCharacter::StaticRegisterNativesAXpCharacter()
	{
		UClass* Class = AXpCharacter::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "EnhancedMovement", &AXpCharacter::execEnhancedMovement },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AXpCharacter_EnhancedMovement_Statics
	{
		struct XpCharacter_eventEnhancedMovement_Parms
		{
			FInputActionValue value;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_value_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_value;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AXpCharacter_EnhancedMovement_Statics::NewProp_value_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AXpCharacter_EnhancedMovement_Statics::NewProp_value = { "value", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(XpCharacter_eventEnhancedMovement_Parms, value), Z_Construct_UScriptStruct_FInputActionValue, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AXpCharacter_EnhancedMovement_Statics::NewProp_value_MetaData), Z_Construct_UFunction_AXpCharacter_EnhancedMovement_Statics::NewProp_value_MetaData) }; // 1693336646
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AXpCharacter_EnhancedMovement_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AXpCharacter_EnhancedMovement_Statics::NewProp_value,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AXpCharacter_EnhancedMovement_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*void MoveFB(float Value);\n\n\x09void MoveLR(float Value);\n\n\x09void Rotate(float Value);*/" },
#endif
		{ "ModuleRelativePath", "XpCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "void MoveFB(float Value);\n\n       void MoveLR(float Value);\n\n       void Rotate(float Value);" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AXpCharacter_EnhancedMovement_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AXpCharacter, nullptr, "EnhancedMovement", nullptr, nullptr, Z_Construct_UFunction_AXpCharacter_EnhancedMovement_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AXpCharacter_EnhancedMovement_Statics::PropPointers), sizeof(Z_Construct_UFunction_AXpCharacter_EnhancedMovement_Statics::XpCharacter_eventEnhancedMovement_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04440401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AXpCharacter_EnhancedMovement_Statics::Function_MetaDataParams), Z_Construct_UFunction_AXpCharacter_EnhancedMovement_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AXpCharacter_EnhancedMovement_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_AXpCharacter_EnhancedMovement_Statics::XpCharacter_eventEnhancedMovement_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_AXpCharacter_EnhancedMovement()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AXpCharacter_EnhancedMovement_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AXpCharacter);
	UClass* Z_Construct_UClass_AXpCharacter_NoRegister()
	{
		return AXpCharacter::StaticClass();
	}
	struct Z_Construct_UClass_AXpCharacter_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MovementComponent_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_MovementComponent;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ScanTriangle1_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ScanTriangle1;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Springarm_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Springarm;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_PlayerCamera_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_PlayerCamera;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_GrindRailHitBoxContainer_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_GrindRailHitBoxContainer;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_PlayerMesh_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_PlayerMesh;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TestHitBox_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_TestHitBox;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_InputMapping_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_InputMapping;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MovementAction_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_MovementAction;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_JumpAction_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_JumpAction;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Look_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Look;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AXpCharacter_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ACharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_NewCppTutorial,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AXpCharacter_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_AXpCharacter_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AXpCharacter_EnhancedMovement, "EnhancedMovement" }, // 2443587076
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AXpCharacter_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AXpCharacter_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "XpCharacter.h" },
		{ "ModuleRelativePath", "XpCharacter.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AXpCharacter_Statics::NewProp_MovementComponent_MetaData[] = {
		{ "Category", "Movement" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*EditDefaultsOnly, BlueprintReadWrite,*/" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "XpCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "EditDefaultsOnly, BlueprintReadWrite," },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AXpCharacter_Statics::NewProp_MovementComponent = { "MovementComponent", nullptr, (EPropertyFlags)0x002008000008000c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AXpCharacter, MovementComponent), Z_Construct_UClass_UCustomMoveComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AXpCharacter_Statics::NewProp_MovementComponent_MetaData), Z_Construct_UClass_AXpCharacter_Statics::NewProp_MovementComponent_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AXpCharacter_Statics::NewProp_ScanTriangle1_MetaData[] = {
		{ "Category", "CustomMesh" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "XpCharacter.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AXpCharacter_Statics::NewProp_ScanTriangle1 = { "ScanTriangle1", nullptr, (EPropertyFlags)0x001000000008000c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AXpCharacter, ScanTriangle1), Z_Construct_UClass_UCustomMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AXpCharacter_Statics::NewProp_ScanTriangle1_MetaData), Z_Construct_UClass_AXpCharacter_Statics::NewProp_ScanTriangle1_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AXpCharacter_Statics::NewProp_Springarm_MetaData[] = {
		{ "Category", "Camera" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "XpCharacter.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AXpCharacter_Statics::NewProp_Springarm = { "Springarm", nullptr, (EPropertyFlags)0x0010000000080009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AXpCharacter, Springarm), Z_Construct_UClass_USpringArmComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AXpCharacter_Statics::NewProp_Springarm_MetaData), Z_Construct_UClass_AXpCharacter_Statics::NewProp_Springarm_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AXpCharacter_Statics::NewProp_PlayerCamera_MetaData[] = {
		{ "Category", "Camera" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "XpCharacter.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AXpCharacter_Statics::NewProp_PlayerCamera = { "PlayerCamera", nullptr, (EPropertyFlags)0x001000000008000c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AXpCharacter, PlayerCamera), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AXpCharacter_Statics::NewProp_PlayerCamera_MetaData), Z_Construct_UClass_AXpCharacter_Statics::NewProp_PlayerCamera_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AXpCharacter_Statics::NewProp_GrindRailHitBoxContainer_MetaData[] = {
		{ "Category", "XpCharacter" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "XpCharacter.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AXpCharacter_Statics::NewProp_GrindRailHitBoxContainer = { "GrindRailHitBoxContainer", nullptr, (EPropertyFlags)0x001000000008000c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AXpCharacter, GrindRailHitBoxContainer), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AXpCharacter_Statics::NewProp_GrindRailHitBoxContainer_MetaData), Z_Construct_UClass_AXpCharacter_Statics::NewProp_GrindRailHitBoxContainer_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AXpCharacter_Statics::NewProp_PlayerMesh_MetaData[] = {
		{ "Category", "XpCharacter" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "XpCharacter.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AXpCharacter_Statics::NewProp_PlayerMesh = { "PlayerMesh", nullptr, (EPropertyFlags)0x0040000000090009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AXpCharacter, PlayerMesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AXpCharacter_Statics::NewProp_PlayerMesh_MetaData), Z_Construct_UClass_AXpCharacter_Statics::NewProp_PlayerMesh_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AXpCharacter_Statics::NewProp_TestHitBox_MetaData[] = {
		{ "Category", "XpCharacter" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "XpCharacter.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AXpCharacter_Statics::NewProp_TestHitBox = { "TestHitBox", nullptr, (EPropertyFlags)0x0040000000090009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AXpCharacter, TestHitBox), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AXpCharacter_Statics::NewProp_TestHitBox_MetaData), Z_Construct_UClass_AXpCharacter_Statics::NewProp_TestHitBox_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AXpCharacter_Statics::NewProp_InputMapping_MetaData[] = {
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*UPROPERTY(EditAnywhere)\n\x09""float MoveSpeed = 1.0f;\n\n\x09UPROPERTY(EditAnywhere)\n\x09""float RotationSpeed = 1.0f;*/" },
#endif
		{ "ModuleRelativePath", "XpCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "UPROPERTY(EditAnywhere)\n       float MoveSpeed = 1.0f;\n\n       UPROPERTY(EditAnywhere)\n       float RotationSpeed = 1.0f;" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AXpCharacter_Statics::NewProp_InputMapping = { "InputMapping", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AXpCharacter, InputMapping), Z_Construct_UClass_UInputMappingContext_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AXpCharacter_Statics::NewProp_InputMapping_MetaData), Z_Construct_UClass_AXpCharacter_Statics::NewProp_InputMapping_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AXpCharacter_Statics::NewProp_MovementAction_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "XpCharacter.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AXpCharacter_Statics::NewProp_MovementAction = { "MovementAction", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AXpCharacter, MovementAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AXpCharacter_Statics::NewProp_MovementAction_MetaData), Z_Construct_UClass_AXpCharacter_Statics::NewProp_MovementAction_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AXpCharacter_Statics::NewProp_JumpAction_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "XpCharacter.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AXpCharacter_Statics::NewProp_JumpAction = { "JumpAction", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AXpCharacter, JumpAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AXpCharacter_Statics::NewProp_JumpAction_MetaData), Z_Construct_UClass_AXpCharacter_Statics::NewProp_JumpAction_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AXpCharacter_Statics::NewProp_Look_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "XpCharacter.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AXpCharacter_Statics::NewProp_Look = { "Look", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AXpCharacter, Look), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AXpCharacter_Statics::NewProp_Look_MetaData), Z_Construct_UClass_AXpCharacter_Statics::NewProp_Look_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AXpCharacter_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AXpCharacter_Statics::NewProp_MovementComponent,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AXpCharacter_Statics::NewProp_ScanTriangle1,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AXpCharacter_Statics::NewProp_Springarm,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AXpCharacter_Statics::NewProp_PlayerCamera,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AXpCharacter_Statics::NewProp_GrindRailHitBoxContainer,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AXpCharacter_Statics::NewProp_PlayerMesh,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AXpCharacter_Statics::NewProp_TestHitBox,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AXpCharacter_Statics::NewProp_InputMapping,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AXpCharacter_Statics::NewProp_MovementAction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AXpCharacter_Statics::NewProp_JumpAction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AXpCharacter_Statics::NewProp_Look,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AXpCharacter_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AXpCharacter>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AXpCharacter_Statics::ClassParams = {
		&AXpCharacter::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_AXpCharacter_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_AXpCharacter_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AXpCharacter_Statics::Class_MetaDataParams), Z_Construct_UClass_AXpCharacter_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AXpCharacter_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_AXpCharacter()
	{
		if (!Z_Registration_Info_UClass_AXpCharacter.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AXpCharacter.OuterSingleton, Z_Construct_UClass_AXpCharacter_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AXpCharacter.OuterSingleton;
	}
	template<> NEWCPPTUTORIAL_API UClass* StaticClass<AXpCharacter>()
	{
		return AXpCharacter::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AXpCharacter);
	AXpCharacter::~AXpCharacter() {}
	struct Z_CompiledInDeferFile_FID_NewCppTutorial_Source_NewCppTutorial_XpCharacter_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_NewCppTutorial_Source_NewCppTutorial_XpCharacter_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AXpCharacter, AXpCharacter::StaticClass, TEXT("AXpCharacter"), &Z_Registration_Info_UClass_AXpCharacter, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AXpCharacter), 3614563130U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_NewCppTutorial_Source_NewCppTutorial_XpCharacter_h_4007159550(TEXT("/Script/NewCppTutorial"),
		Z_CompiledInDeferFile_FID_NewCppTutorial_Source_NewCppTutorial_XpCharacter_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_NewCppTutorial_Source_NewCppTutorial_XpCharacter_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
