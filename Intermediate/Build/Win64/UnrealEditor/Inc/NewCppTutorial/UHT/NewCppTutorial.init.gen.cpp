// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeNewCppTutorial_init() {}
	NEWCPPTUTORIAL_API UFunction* Z_Construct_UDelegateFunction_NewCppTutorial_OnJumpTriggerSignature__DelegateSignature();
	NEWCPPTUTORIAL_API UFunction* Z_Construct_UDelegateFunction_NewCppTutorial_OnMoveComponentEndPointReachedSignature__DelegateSignature();
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_NewCppTutorial;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_NewCppTutorial()
	{
		if (!Z_Registration_Info_UPackage__Script_NewCppTutorial.OuterSingleton)
		{
			static UObject* (*const SingletonFuncArray[])() = {
				(UObject* (*)())Z_Construct_UDelegateFunction_NewCppTutorial_OnJumpTriggerSignature__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_NewCppTutorial_OnMoveComponentEndPointReachedSignature__DelegateSignature,
			};
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/NewCppTutorial",
				SingletonFuncArray,
				UE_ARRAY_COUNT(SingletonFuncArray),
				PKG_CompiledIn | 0x00000000,
				0x701DABEA,
				0x2DCB0BD3,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_NewCppTutorial.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_NewCppTutorial.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_NewCppTutorial(Z_Construct_UPackage__Script_NewCppTutorial, TEXT("/Script/NewCppTutorial"), Z_Registration_Info_UPackage__Script_NewCppTutorial, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x701DABEA, 0x2DCB0BD3));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
