// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "NewCppTutorial/CustomMoveComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCustomMoveComponent() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_UCharacterMovementComponent();
	ENGINE_API UClass* Z_Construct_UClass_UCurveFloat_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMesh_NoRegister();
	NEWCPPTUTORIAL_API UClass* Z_Construct_UClass_AXpCharacter_NoRegister();
	NEWCPPTUTORIAL_API UClass* Z_Construct_UClass_UCustomMoveComponent();
	NEWCPPTUTORIAL_API UClass* Z_Construct_UClass_UCustomMoveComponent_NoRegister();
	NEWCPPTUTORIAL_API UEnum* Z_Construct_UEnum_NewCppTutorial_ECustomMovementMode();
	UPackage* Z_Construct_UPackage__Script_NewCppTutorial();
// End Cross Module References
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_ECustomMovementMode;
	static UEnum* ECustomMovementMode_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_ECustomMovementMode.OuterSingleton)
		{
			Z_Registration_Info_UEnum_ECustomMovementMode.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_NewCppTutorial_ECustomMovementMode, (UObject*)Z_Construct_UPackage__Script_NewCppTutorial(), TEXT("ECustomMovementMode"));
		}
		return Z_Registration_Info_UEnum_ECustomMovementMode.OuterSingleton;
	}
	template<> NEWCPPTUTORIAL_API UEnum* StaticEnum<ECustomMovementMode>()
	{
		return ECustomMovementMode_StaticEnum();
	}
	struct Z_Construct_UEnum_NewCppTutorial_ECustomMovementMode_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_NewCppTutorial_ECustomMovementMode_Statics::Enumerators[] = {
		{ "CMOVE_None", (int64)CMOVE_None },
		{ "CMOVE_WallRun", (int64)CMOVE_WallRun },
		{ "CMOVE_RailGrind", (int64)CMOVE_RailGrind },
		{ "CMOVE_Max", (int64)CMOVE_Max },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_NewCppTutorial_ECustomMovementMode_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "CMOVE_Max.Comment", "/**\n * \n */" },
		{ "CMOVE_Max.Hidden", "" },
		{ "CMOVE_Max.Name", "CMOVE_Max" },
		{ "CMOVE_None.Comment", "/**\n * \n */" },
		{ "CMOVE_None.Hidden", "" },
		{ "CMOVE_None.Name", "CMOVE_None" },
		{ "CMOVE_RailGrind.Comment", "/**\n * \n */" },
		{ "CMOVE_RailGrind.DisplayName", "Grind" },
		{ "CMOVE_RailGrind.Name", "CMOVE_RailGrind" },
		{ "CMOVE_WallRun.Comment", "/**\n * \n */" },
		{ "CMOVE_WallRun.DisplayName", "Skate" },
		{ "CMOVE_WallRun.Name", "CMOVE_WallRun" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "ModuleRelativePath", "CustomMoveComponent.h" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_NewCppTutorial_ECustomMovementMode_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_NewCppTutorial,
		nullptr,
		"ECustomMovementMode",
		"ECustomMovementMode",
		Z_Construct_UEnum_NewCppTutorial_ECustomMovementMode_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_NewCppTutorial_ECustomMovementMode_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::Regular,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_NewCppTutorial_ECustomMovementMode_Statics::Enum_MetaDataParams), Z_Construct_UEnum_NewCppTutorial_ECustomMovementMode_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_NewCppTutorial_ECustomMovementMode()
	{
		if (!Z_Registration_Info_UEnum_ECustomMovementMode.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_ECustomMovementMode.InnerSingleton, Z_Construct_UEnum_NewCppTutorial_ECustomMovementMode_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_ECustomMovementMode.InnerSingleton;
	}
	DEFINE_FUNCTION(UCustomMoveComponent::execIsRailGrinding)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->IsRailGrinding();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UCustomMoveComponent::execSpeedCheck)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->SpeedCheck();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UCustomMoveComponent::execWallRunningIsRight)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->WallRunningIsRight();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UCustomMoveComponent::execIsWallRunning)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->IsWallRunning();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UCustomMoveComponent::execIsCustomMovementMode)
	{
		P_GET_PROPERTY(FByteProperty,Z_Param_InCustomMovementMode);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->IsCustomMovementMode(ECustomMovementMode(Z_Param_InCustomMovementMode));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UCustomMoveComponent::execSprintReleased)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SprintReleased();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UCustomMoveComponent::execSprintPressed)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SprintPressed();
		P_NATIVE_END;
	}
	void UCustomMoveComponent::StaticRegisterNativesUCustomMoveComponent()
	{
		UClass* Class = UCustomMoveComponent::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "IsCustomMovementMode", &UCustomMoveComponent::execIsCustomMovementMode },
			{ "IsRailGrinding", &UCustomMoveComponent::execIsRailGrinding },
			{ "IsWallRunning", &UCustomMoveComponent::execIsWallRunning },
			{ "SpeedCheck", &UCustomMoveComponent::execSpeedCheck },
			{ "SprintPressed", &UCustomMoveComponent::execSprintPressed },
			{ "SprintReleased", &UCustomMoveComponent::execSprintReleased },
			{ "WallRunningIsRight", &UCustomMoveComponent::execWallRunningIsRight },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UCustomMoveComponent_IsCustomMovementMode_Statics
	{
		struct CustomMoveComponent_eventIsCustomMovementMode_Parms
		{
			TEnumAsByte<ECustomMovementMode> InCustomMovementMode;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_InCustomMovementMode;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UCustomMoveComponent_IsCustomMovementMode_Statics::NewProp_InCustomMovementMode = { "InCustomMovementMode", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CustomMoveComponent_eventIsCustomMovementMode_Parms, InCustomMovementMode), Z_Construct_UEnum_NewCppTutorial_ECustomMovementMode, METADATA_PARAMS(0, nullptr) }; // 295011779
	void Z_Construct_UFunction_UCustomMoveComponent_IsCustomMovementMode_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((CustomMoveComponent_eventIsCustomMovementMode_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UCustomMoveComponent_IsCustomMovementMode_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(CustomMoveComponent_eventIsCustomMovementMode_Parms), &Z_Construct_UFunction_UCustomMoveComponent_IsCustomMovementMode_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCustomMoveComponent_IsCustomMovementMode_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCustomMoveComponent_IsCustomMovementMode_Statics::NewProp_InCustomMovementMode,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCustomMoveComponent_IsCustomMovementMode_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCustomMoveComponent_IsCustomMovementMode_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "CustomMoveComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCustomMoveComponent_IsCustomMovementMode_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCustomMoveComponent, nullptr, "IsCustomMovementMode", nullptr, nullptr, Z_Construct_UFunction_UCustomMoveComponent_IsCustomMovementMode_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCustomMoveComponent_IsCustomMovementMode_Statics::PropPointers), sizeof(Z_Construct_UFunction_UCustomMoveComponent_IsCustomMovementMode_Statics::CustomMoveComponent_eventIsCustomMovementMode_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCustomMoveComponent_IsCustomMovementMode_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCustomMoveComponent_IsCustomMovementMode_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCustomMoveComponent_IsCustomMovementMode_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UCustomMoveComponent_IsCustomMovementMode_Statics::CustomMoveComponent_eventIsCustomMovementMode_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UCustomMoveComponent_IsCustomMovementMode()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCustomMoveComponent_IsCustomMovementMode_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UCustomMoveComponent_IsRailGrinding_Statics
	{
		struct CustomMoveComponent_eventIsRailGrinding_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UCustomMoveComponent_IsRailGrinding_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((CustomMoveComponent_eventIsRailGrinding_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UCustomMoveComponent_IsRailGrinding_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(CustomMoveComponent_eventIsRailGrinding_Parms), &Z_Construct_UFunction_UCustomMoveComponent_IsRailGrinding_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCustomMoveComponent_IsRailGrinding_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCustomMoveComponent_IsRailGrinding_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCustomMoveComponent_IsRailGrinding_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "CustomMoveComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCustomMoveComponent_IsRailGrinding_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCustomMoveComponent, nullptr, "IsRailGrinding", nullptr, nullptr, Z_Construct_UFunction_UCustomMoveComponent_IsRailGrinding_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCustomMoveComponent_IsRailGrinding_Statics::PropPointers), sizeof(Z_Construct_UFunction_UCustomMoveComponent_IsRailGrinding_Statics::CustomMoveComponent_eventIsRailGrinding_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCustomMoveComponent_IsRailGrinding_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCustomMoveComponent_IsRailGrinding_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCustomMoveComponent_IsRailGrinding_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UCustomMoveComponent_IsRailGrinding_Statics::CustomMoveComponent_eventIsRailGrinding_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UCustomMoveComponent_IsRailGrinding()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCustomMoveComponent_IsRailGrinding_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UCustomMoveComponent_IsWallRunning_Statics
	{
		struct CustomMoveComponent_eventIsWallRunning_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UCustomMoveComponent_IsWallRunning_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((CustomMoveComponent_eventIsWallRunning_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UCustomMoveComponent_IsWallRunning_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(CustomMoveComponent_eventIsWallRunning_Parms), &Z_Construct_UFunction_UCustomMoveComponent_IsWallRunning_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCustomMoveComponent_IsWallRunning_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCustomMoveComponent_IsWallRunning_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCustomMoveComponent_IsWallRunning_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "CustomMoveComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCustomMoveComponent_IsWallRunning_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCustomMoveComponent, nullptr, "IsWallRunning", nullptr, nullptr, Z_Construct_UFunction_UCustomMoveComponent_IsWallRunning_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCustomMoveComponent_IsWallRunning_Statics::PropPointers), sizeof(Z_Construct_UFunction_UCustomMoveComponent_IsWallRunning_Statics::CustomMoveComponent_eventIsWallRunning_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCustomMoveComponent_IsWallRunning_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCustomMoveComponent_IsWallRunning_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCustomMoveComponent_IsWallRunning_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UCustomMoveComponent_IsWallRunning_Statics::CustomMoveComponent_eventIsWallRunning_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UCustomMoveComponent_IsWallRunning()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCustomMoveComponent_IsWallRunning_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UCustomMoveComponent_SpeedCheck_Statics
	{
		struct CustomMoveComponent_eventSpeedCheck_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UCustomMoveComponent_SpeedCheck_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((CustomMoveComponent_eventSpeedCheck_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UCustomMoveComponent_SpeedCheck_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(CustomMoveComponent_eventSpeedCheck_Parms), &Z_Construct_UFunction_UCustomMoveComponent_SpeedCheck_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCustomMoveComponent_SpeedCheck_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCustomMoveComponent_SpeedCheck_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCustomMoveComponent_SpeedCheck_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "CustomMoveComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCustomMoveComponent_SpeedCheck_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCustomMoveComponent, nullptr, "SpeedCheck", nullptr, nullptr, Z_Construct_UFunction_UCustomMoveComponent_SpeedCheck_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCustomMoveComponent_SpeedCheck_Statics::PropPointers), sizeof(Z_Construct_UFunction_UCustomMoveComponent_SpeedCheck_Statics::CustomMoveComponent_eventSpeedCheck_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCustomMoveComponent_SpeedCheck_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCustomMoveComponent_SpeedCheck_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCustomMoveComponent_SpeedCheck_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UCustomMoveComponent_SpeedCheck_Statics::CustomMoveComponent_eventSpeedCheck_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UCustomMoveComponent_SpeedCheck()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCustomMoveComponent_SpeedCheck_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UCustomMoveComponent_SprintPressed_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCustomMoveComponent_SprintPressed_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "CustomMoveComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCustomMoveComponent_SprintPressed_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCustomMoveComponent, nullptr, "SprintPressed", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCustomMoveComponent_SprintPressed_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCustomMoveComponent_SprintPressed_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_UCustomMoveComponent_SprintPressed()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCustomMoveComponent_SprintPressed_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UCustomMoveComponent_SprintReleased_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCustomMoveComponent_SprintReleased_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "CustomMoveComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCustomMoveComponent_SprintReleased_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCustomMoveComponent, nullptr, "SprintReleased", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCustomMoveComponent_SprintReleased_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCustomMoveComponent_SprintReleased_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_UCustomMoveComponent_SprintReleased()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCustomMoveComponent_SprintReleased_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UCustomMoveComponent_WallRunningIsRight_Statics
	{
		struct CustomMoveComponent_eventWallRunningIsRight_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UCustomMoveComponent_WallRunningIsRight_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((CustomMoveComponent_eventWallRunningIsRight_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UCustomMoveComponent_WallRunningIsRight_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(CustomMoveComponent_eventWallRunningIsRight_Parms), &Z_Construct_UFunction_UCustomMoveComponent_WallRunningIsRight_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCustomMoveComponent_WallRunningIsRight_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCustomMoveComponent_WallRunningIsRight_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCustomMoveComponent_WallRunningIsRight_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "CustomMoveComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCustomMoveComponent_WallRunningIsRight_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCustomMoveComponent, nullptr, "WallRunningIsRight", nullptr, nullptr, Z_Construct_UFunction_UCustomMoveComponent_WallRunningIsRight_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCustomMoveComponent_WallRunningIsRight_Statics::PropPointers), sizeof(Z_Construct_UFunction_UCustomMoveComponent_WallRunningIsRight_Statics::CustomMoveComponent_eventWallRunningIsRight_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCustomMoveComponent_WallRunningIsRight_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCustomMoveComponent_WallRunningIsRight_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCustomMoveComponent_WallRunningIsRight_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UCustomMoveComponent_WallRunningIsRight_Statics::CustomMoveComponent_eventWallRunningIsRight_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UCustomMoveComponent_WallRunningIsRight()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCustomMoveComponent_WallRunningIsRight_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UCustomMoveComponent);
	UClass* Z_Construct_UClass_UCustomMoveComponent_NoRegister()
	{
		return UCustomMoveComponent::StaticClass();
	}
	struct Z_Construct_UClass_UCustomMoveComponent_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Sprint_MaxSpeed_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Sprint_MaxSpeed;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Walk_MaxSpeed_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Walk_MaxSpeed;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_WallRunScanDistance_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_WallRunScanDistance;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MinWallRunSpeed_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_MinWallRunSpeed;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MaxWallRunSpeed_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxWallRunSpeed;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MaxVerticalRunSpeed_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxVerticalRunSpeed;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_WallRunPullAwayAngle_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_WallRunPullAwayAngle;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MinWallRunHeight_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_MinWallRunHeight;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_WallJumpOffForce_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_WallJumpOffForce;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_WallAttractionForce_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_WallAttractionForce;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_WallRunGravityScaleCurve_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_WallRunGravityScaleCurve;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ScanMesh_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ScanMesh;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CustomCharacterOwner_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_CustomCharacterOwner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_skateGravity_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_skateGravity;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UCustomMoveComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UCharacterMovementComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_NewCppTutorial,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCustomMoveComponent_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UCustomMoveComponent_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UCustomMoveComponent_IsCustomMovementMode, "IsCustomMovementMode" }, // 2173831277
		{ &Z_Construct_UFunction_UCustomMoveComponent_IsRailGrinding, "IsRailGrinding" }, // 1557020219
		{ &Z_Construct_UFunction_UCustomMoveComponent_IsWallRunning, "IsWallRunning" }, // 2952872040
		{ &Z_Construct_UFunction_UCustomMoveComponent_SpeedCheck, "SpeedCheck" }, // 2150467488
		{ &Z_Construct_UFunction_UCustomMoveComponent_SprintPressed, "SprintPressed" }, // 680905000
		{ &Z_Construct_UFunction_UCustomMoveComponent_SprintReleased, "SprintReleased" }, // 771380118
		{ &Z_Construct_UFunction_UCustomMoveComponent_WallRunningIsRight, "WallRunningIsRight" }, // 881871630
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCustomMoveComponent_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCustomMoveComponent_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "CustomMoveComponent.h" },
		{ "ModuleRelativePath", "CustomMoveComponent.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCustomMoveComponent_Statics::NewProp_Sprint_MaxSpeed_MetaData[] = {
		{ "Category", "CustomMoveComponent" },
		{ "ModuleRelativePath", "CustomMoveComponent.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCustomMoveComponent_Statics::NewProp_Sprint_MaxSpeed = { "Sprint_MaxSpeed", nullptr, (EPropertyFlags)0x0040000000010001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCustomMoveComponent, Sprint_MaxSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UCustomMoveComponent_Statics::NewProp_Sprint_MaxSpeed_MetaData), Z_Construct_UClass_UCustomMoveComponent_Statics::NewProp_Sprint_MaxSpeed_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCustomMoveComponent_Statics::NewProp_Walk_MaxSpeed_MetaData[] = {
		{ "Category", "CustomMoveComponent" },
		{ "ModuleRelativePath", "CustomMoveComponent.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCustomMoveComponent_Statics::NewProp_Walk_MaxSpeed = { "Walk_MaxSpeed", nullptr, (EPropertyFlags)0x0040000000010001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCustomMoveComponent, Walk_MaxSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UCustomMoveComponent_Statics::NewProp_Walk_MaxSpeed_MetaData), Z_Construct_UClass_UCustomMoveComponent_Statics::NewProp_Walk_MaxSpeed_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCustomMoveComponent_Statics::NewProp_WallRunScanDistance_MetaData[] = {
		{ "Category", "CustomMoveComponent" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//wallRun Params\n" },
#endif
		{ "ModuleRelativePath", "CustomMoveComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "wallRun Params" },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCustomMoveComponent_Statics::NewProp_WallRunScanDistance = { "WallRunScanDistance", nullptr, (EPropertyFlags)0x0040000000010001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCustomMoveComponent, WallRunScanDistance), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UCustomMoveComponent_Statics::NewProp_WallRunScanDistance_MetaData), Z_Construct_UClass_UCustomMoveComponent_Statics::NewProp_WallRunScanDistance_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCustomMoveComponent_Statics::NewProp_MinWallRunSpeed_MetaData[] = {
		{ "Category", "CustomMoveComponent" },
		{ "ModuleRelativePath", "CustomMoveComponent.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCustomMoveComponent_Statics::NewProp_MinWallRunSpeed = { "MinWallRunSpeed", nullptr, (EPropertyFlags)0x0040000000010001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCustomMoveComponent, MinWallRunSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UCustomMoveComponent_Statics::NewProp_MinWallRunSpeed_MetaData), Z_Construct_UClass_UCustomMoveComponent_Statics::NewProp_MinWallRunSpeed_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCustomMoveComponent_Statics::NewProp_MaxWallRunSpeed_MetaData[] = {
		{ "Category", "CustomMoveComponent" },
		{ "ModuleRelativePath", "CustomMoveComponent.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCustomMoveComponent_Statics::NewProp_MaxWallRunSpeed = { "MaxWallRunSpeed", nullptr, (EPropertyFlags)0x0040000000010001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCustomMoveComponent, MaxWallRunSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UCustomMoveComponent_Statics::NewProp_MaxWallRunSpeed_MetaData), Z_Construct_UClass_UCustomMoveComponent_Statics::NewProp_MaxWallRunSpeed_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCustomMoveComponent_Statics::NewProp_MaxVerticalRunSpeed_MetaData[] = {
		{ "Category", "CustomMoveComponent" },
		{ "ModuleRelativePath", "CustomMoveComponent.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCustomMoveComponent_Statics::NewProp_MaxVerticalRunSpeed = { "MaxVerticalRunSpeed", nullptr, (EPropertyFlags)0x0040000000010001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCustomMoveComponent, MaxVerticalRunSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UCustomMoveComponent_Statics::NewProp_MaxVerticalRunSpeed_MetaData), Z_Construct_UClass_UCustomMoveComponent_Statics::NewProp_MaxVerticalRunSpeed_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCustomMoveComponent_Statics::NewProp_WallRunPullAwayAngle_MetaData[] = {
		{ "Category", "CustomMoveComponent" },
		{ "ModuleRelativePath", "CustomMoveComponent.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCustomMoveComponent_Statics::NewProp_WallRunPullAwayAngle = { "WallRunPullAwayAngle", nullptr, (EPropertyFlags)0x0040000000010001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCustomMoveComponent, WallRunPullAwayAngle), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UCustomMoveComponent_Statics::NewProp_WallRunPullAwayAngle_MetaData), Z_Construct_UClass_UCustomMoveComponent_Statics::NewProp_WallRunPullAwayAngle_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCustomMoveComponent_Statics::NewProp_MinWallRunHeight_MetaData[] = {
		{ "Category", "CustomMoveComponent" },
		{ "ModuleRelativePath", "CustomMoveComponent.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCustomMoveComponent_Statics::NewProp_MinWallRunHeight = { "MinWallRunHeight", nullptr, (EPropertyFlags)0x0040000000010001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCustomMoveComponent, MinWallRunHeight), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UCustomMoveComponent_Statics::NewProp_MinWallRunHeight_MetaData), Z_Construct_UClass_UCustomMoveComponent_Statics::NewProp_MinWallRunHeight_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCustomMoveComponent_Statics::NewProp_WallJumpOffForce_MetaData[] = {
		{ "Category", "CustomMoveComponent" },
		{ "ModuleRelativePath", "CustomMoveComponent.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCustomMoveComponent_Statics::NewProp_WallJumpOffForce = { "WallJumpOffForce", nullptr, (EPropertyFlags)0x0040000000010001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCustomMoveComponent, WallJumpOffForce), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UCustomMoveComponent_Statics::NewProp_WallJumpOffForce_MetaData), Z_Construct_UClass_UCustomMoveComponent_Statics::NewProp_WallJumpOffForce_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCustomMoveComponent_Statics::NewProp_WallAttractionForce_MetaData[] = {
		{ "Category", "CustomMoveComponent" },
		{ "ModuleRelativePath", "CustomMoveComponent.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCustomMoveComponent_Statics::NewProp_WallAttractionForce = { "WallAttractionForce", nullptr, (EPropertyFlags)0x0040000000010001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCustomMoveComponent, WallAttractionForce), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UCustomMoveComponent_Statics::NewProp_WallAttractionForce_MetaData), Z_Construct_UClass_UCustomMoveComponent_Statics::NewProp_WallAttractionForce_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCustomMoveComponent_Statics::NewProp_WallRunGravityScaleCurve_MetaData[] = {
		{ "Category", "CustomMoveComponent" },
		{ "ModuleRelativePath", "CustomMoveComponent.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UCustomMoveComponent_Statics::NewProp_WallRunGravityScaleCurve = { "WallRunGravityScaleCurve", nullptr, (EPropertyFlags)0x0040000000010001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCustomMoveComponent, WallRunGravityScaleCurve), Z_Construct_UClass_UCurveFloat_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UCustomMoveComponent_Statics::NewProp_WallRunGravityScaleCurve_MetaData), Z_Construct_UClass_UCustomMoveComponent_Statics::NewProp_WallRunGravityScaleCurve_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCustomMoveComponent_Statics::NewProp_ScanMesh_MetaData[] = {
		{ "Category", "CustomMoveComponent" },
		{ "ModuleRelativePath", "CustomMoveComponent.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UCustomMoveComponent_Statics::NewProp_ScanMesh = { "ScanMesh", nullptr, (EPropertyFlags)0x0040000000010001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCustomMoveComponent, ScanMesh), Z_Construct_UClass_UStaticMesh_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UCustomMoveComponent_Statics::NewProp_ScanMesh_MetaData), Z_Construct_UClass_UCustomMoveComponent_Statics::NewProp_ScanMesh_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCustomMoveComponent_Statics::NewProp_CustomCharacterOwner_MetaData[] = {
		{ "ModuleRelativePath", "CustomMoveComponent.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UCustomMoveComponent_Statics::NewProp_CustomCharacterOwner = { "CustomCharacterOwner", nullptr, (EPropertyFlags)0x0010000000002000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCustomMoveComponent, CustomCharacterOwner), Z_Construct_UClass_AXpCharacter_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UCustomMoveComponent_Statics::NewProp_CustomCharacterOwner_MetaData), Z_Construct_UClass_UCustomMoveComponent_Statics::NewProp_CustomCharacterOwner_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCustomMoveComponent_Statics::NewProp_skateGravity_MetaData[] = {
		{ "Category", "CustomMoveComponent" },
		{ "ModuleRelativePath", "CustomMoveComponent.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCustomMoveComponent_Statics::NewProp_skateGravity = { "skateGravity", nullptr, (EPropertyFlags)0x0020080000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCustomMoveComponent, skateGravity), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UCustomMoveComponent_Statics::NewProp_skateGravity_MetaData), Z_Construct_UClass_UCustomMoveComponent_Statics::NewProp_skateGravity_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UCustomMoveComponent_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCustomMoveComponent_Statics::NewProp_Sprint_MaxSpeed,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCustomMoveComponent_Statics::NewProp_Walk_MaxSpeed,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCustomMoveComponent_Statics::NewProp_WallRunScanDistance,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCustomMoveComponent_Statics::NewProp_MinWallRunSpeed,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCustomMoveComponent_Statics::NewProp_MaxWallRunSpeed,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCustomMoveComponent_Statics::NewProp_MaxVerticalRunSpeed,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCustomMoveComponent_Statics::NewProp_WallRunPullAwayAngle,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCustomMoveComponent_Statics::NewProp_MinWallRunHeight,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCustomMoveComponent_Statics::NewProp_WallJumpOffForce,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCustomMoveComponent_Statics::NewProp_WallAttractionForce,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCustomMoveComponent_Statics::NewProp_WallRunGravityScaleCurve,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCustomMoveComponent_Statics::NewProp_ScanMesh,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCustomMoveComponent_Statics::NewProp_CustomCharacterOwner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCustomMoveComponent_Statics::NewProp_skateGravity,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UCustomMoveComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCustomMoveComponent>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UCustomMoveComponent_Statics::ClassParams = {
		&UCustomMoveComponent::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UCustomMoveComponent_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UCustomMoveComponent_Statics::PropPointers),
		0,
		0x00B000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UCustomMoveComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UCustomMoveComponent_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCustomMoveComponent_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UCustomMoveComponent()
	{
		if (!Z_Registration_Info_UClass_UCustomMoveComponent.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCustomMoveComponent.OuterSingleton, Z_Construct_UClass_UCustomMoveComponent_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UCustomMoveComponent.OuterSingleton;
	}
	template<> NEWCPPTUTORIAL_API UClass* StaticClass<UCustomMoveComponent>()
	{
		return UCustomMoveComponent::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UCustomMoveComponent);
	UCustomMoveComponent::~UCustomMoveComponent() {}
	struct Z_CompiledInDeferFile_FID_NewCppTutorial_Source_NewCppTutorial_CustomMoveComponent_h_Statics
	{
		static const FEnumRegisterCompiledInInfo EnumInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FEnumRegisterCompiledInInfo Z_CompiledInDeferFile_FID_NewCppTutorial_Source_NewCppTutorial_CustomMoveComponent_h_Statics::EnumInfo[] = {
		{ ECustomMovementMode_StaticEnum, TEXT("ECustomMovementMode"), &Z_Registration_Info_UEnum_ECustomMovementMode, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 295011779U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_NewCppTutorial_Source_NewCppTutorial_CustomMoveComponent_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UCustomMoveComponent, UCustomMoveComponent::StaticClass, TEXT("UCustomMoveComponent"), &Z_Registration_Info_UClass_UCustomMoveComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCustomMoveComponent), 1010119427U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_NewCppTutorial_Source_NewCppTutorial_CustomMoveComponent_h_948496313(TEXT("/Script/NewCppTutorial"),
		Z_CompiledInDeferFile_FID_NewCppTutorial_Source_NewCppTutorial_CustomMoveComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_NewCppTutorial_Source_NewCppTutorial_CustomMoveComponent_h_Statics::ClassInfo),
		nullptr, 0,
		Z_CompiledInDeferFile_FID_NewCppTutorial_Source_NewCppTutorial_CustomMoveComponent_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_NewCppTutorial_Source_NewCppTutorial_CustomMoveComponent_h_Statics::EnumInfo));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
