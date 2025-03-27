// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "NewCppTutorial/Public/RailGrindRails.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRailGrindRails() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	ENGINE_API UClass* Z_Construct_UClass_USplineComponent_NoRegister();
	NEWCPPTUTORIAL_API UClass* Z_Construct_UClass_ARailGrindRails();
	NEWCPPTUTORIAL_API UClass* Z_Construct_UClass_ARailGrindRails_NoRegister();
	UPackage* Z_Construct_UPackage__Script_NewCppTutorial();
// End Cross Module References
	void ARailGrindRails::StaticRegisterNativesARailGrindRails()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ARailGrindRails);
	UClass* Z_Construct_UClass_ARailGrindRails_NoRegister()
	{
		return ARailGrindRails::StaticClass();
	}
	struct Z_Construct_UClass_ARailGrindRails_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_GrindRail_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_GrindRail;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ARailGrindRails_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_NewCppTutorial,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ARailGrindRails_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ARailGrindRails_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "RailGrindRails.h" },
		{ "ModuleRelativePath", "Public/RailGrindRails.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ARailGrindRails_Statics::NewProp_GrindRail_MetaData[] = {
		{ "Category", "Custom" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/RailGrindRails.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ARailGrindRails_Statics::NewProp_GrindRail = { "GrindRail", nullptr, (EPropertyFlags)0x001000000008000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ARailGrindRails, GrindRail), Z_Construct_UClass_USplineComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ARailGrindRails_Statics::NewProp_GrindRail_MetaData), Z_Construct_UClass_ARailGrindRails_Statics::NewProp_GrindRail_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ARailGrindRails_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ARailGrindRails_Statics::NewProp_GrindRail,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ARailGrindRails_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ARailGrindRails>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ARailGrindRails_Statics::ClassParams = {
		&ARailGrindRails::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_ARailGrindRails_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_ARailGrindRails_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ARailGrindRails_Statics::Class_MetaDataParams), Z_Construct_UClass_ARailGrindRails_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ARailGrindRails_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_ARailGrindRails()
	{
		if (!Z_Registration_Info_UClass_ARailGrindRails.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ARailGrindRails.OuterSingleton, Z_Construct_UClass_ARailGrindRails_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ARailGrindRails.OuterSingleton;
	}
	template<> NEWCPPTUTORIAL_API UClass* StaticClass<ARailGrindRails>()
	{
		return ARailGrindRails::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ARailGrindRails);
	ARailGrindRails::~ARailGrindRails() {}
	struct Z_CompiledInDeferFile_FID_NewCppTutorial_Source_NewCppTutorial_Public_RailGrindRails_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_NewCppTutorial_Source_NewCppTutorial_Public_RailGrindRails_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ARailGrindRails, ARailGrindRails::StaticClass, TEXT("ARailGrindRails"), &Z_Registration_Info_UClass_ARailGrindRails, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ARailGrindRails), 3682567328U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_NewCppTutorial_Source_NewCppTutorial_Public_RailGrindRails_h_4137375857(TEXT("/Script/NewCppTutorial"),
		Z_CompiledInDeferFile_FID_NewCppTutorial_Source_NewCppTutorial_Public_RailGrindRails_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_NewCppTutorial_Source_NewCppTutorial_Public_RailGrindRails_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
