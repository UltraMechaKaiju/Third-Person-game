// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "NewCppTutorial/NewCppTuitorialGameModeBase.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeNewCppTuitorialGameModeBase() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	NEWCPPTUTORIAL_API UClass* Z_Construct_UClass_ANewCppTuitorialGameModeBase();
	NEWCPPTUTORIAL_API UClass* Z_Construct_UClass_ANewCppTuitorialGameModeBase_NoRegister();
	NEWCPPTUTORIAL_API UClass* Z_Construct_UClass_AXpPawn_NoRegister();
	UPackage* Z_Construct_UPackage__Script_NewCppTutorial();
// End Cross Module References
	void ANewCppTuitorialGameModeBase::StaticRegisterNativesANewCppTuitorialGameModeBase()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ANewCppTuitorialGameModeBase);
	UClass* Z_Construct_UClass_ANewCppTuitorialGameModeBase_NoRegister()
	{
		return ANewCppTuitorialGameModeBase::StaticClass();
	}
	struct Z_Construct_UClass_ANewCppTuitorialGameModeBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CustomXpPawn_MetaData[];
#endif
		static const UECodeGen_Private::FClassPropertyParams NewProp_CustomXpPawn;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ANewCppTuitorialGameModeBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_NewCppTutorial,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ANewCppTuitorialGameModeBase_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANewCppTuitorialGameModeBase_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "NewCppTuitorialGameModeBase.h" },
		{ "ModuleRelativePath", "NewCppTuitorialGameModeBase.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANewCppTuitorialGameModeBase_Statics::NewProp_CustomXpPawn_MetaData[] = {
		{ "Category", "NewCppTuitorialGameModeBase" },
		{ "ModuleRelativePath", "NewCppTuitorialGameModeBase.h" },
	};
#endif
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_ANewCppTuitorialGameModeBase_Statics::NewProp_CustomXpPawn = { "CustomXpPawn", nullptr, (EPropertyFlags)0x0044000002000001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANewCppTuitorialGameModeBase, CustomXpPawn), Z_Construct_UClass_UClass, Z_Construct_UClass_AXpPawn_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANewCppTuitorialGameModeBase_Statics::NewProp_CustomXpPawn_MetaData), Z_Construct_UClass_ANewCppTuitorialGameModeBase_Statics::NewProp_CustomXpPawn_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ANewCppTuitorialGameModeBase_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANewCppTuitorialGameModeBase_Statics::NewProp_CustomXpPawn,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ANewCppTuitorialGameModeBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ANewCppTuitorialGameModeBase>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ANewCppTuitorialGameModeBase_Statics::ClassParams = {
		&ANewCppTuitorialGameModeBase::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_ANewCppTuitorialGameModeBase_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_ANewCppTuitorialGameModeBase_Statics::PropPointers),
		0,
		0x009002ACu,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANewCppTuitorialGameModeBase_Statics::Class_MetaDataParams), Z_Construct_UClass_ANewCppTuitorialGameModeBase_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ANewCppTuitorialGameModeBase_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_ANewCppTuitorialGameModeBase()
	{
		if (!Z_Registration_Info_UClass_ANewCppTuitorialGameModeBase.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ANewCppTuitorialGameModeBase.OuterSingleton, Z_Construct_UClass_ANewCppTuitorialGameModeBase_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ANewCppTuitorialGameModeBase.OuterSingleton;
	}
	template<> NEWCPPTUTORIAL_API UClass* StaticClass<ANewCppTuitorialGameModeBase>()
	{
		return ANewCppTuitorialGameModeBase::StaticClass();
	}
	ANewCppTuitorialGameModeBase::ANewCppTuitorialGameModeBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ANewCppTuitorialGameModeBase);
	ANewCppTuitorialGameModeBase::~ANewCppTuitorialGameModeBase() {}
	struct Z_CompiledInDeferFile_FID_NewCppTutorial_Source_NewCppTutorial_NewCppTuitorialGameModeBase_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_NewCppTutorial_Source_NewCppTutorial_NewCppTuitorialGameModeBase_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ANewCppTuitorialGameModeBase, ANewCppTuitorialGameModeBase::StaticClass, TEXT("ANewCppTuitorialGameModeBase"), &Z_Registration_Info_UClass_ANewCppTuitorialGameModeBase, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ANewCppTuitorialGameModeBase), 2183517437U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_NewCppTutorial_Source_NewCppTutorial_NewCppTuitorialGameModeBase_h_1544906447(TEXT("/Script/NewCppTutorial"),
		Z_CompiledInDeferFile_FID_NewCppTutorial_Source_NewCppTutorial_NewCppTuitorialGameModeBase_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_NewCppTutorial_Source_NewCppTutorial_NewCppTuitorialGameModeBase_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
