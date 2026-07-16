// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "NewCppTutorial/Public/WallRunWall.h"
#include "GameplayTagContainer.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeWallRunWall() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_AStaticMeshActor();
	GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTagContainer();
	NEWCPPTUTORIAL_API UClass* Z_Construct_UClass_AWallRunWall();
	NEWCPPTUTORIAL_API UClass* Z_Construct_UClass_AWallRunWall_NoRegister();
	UPackage* Z_Construct_UPackage__Script_NewCppTutorial();
// End Cross Module References
	void AWallRunWall::StaticRegisterNativesAWallRunWall()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AWallRunWall);
	UClass* Z_Construct_UClass_AWallRunWall_NoRegister()
	{
		return AWallRunWall::StaticClass();
	}
	struct Z_Construct_UClass_AWallRunWall_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_WallRunWallTags_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_WallRunWallTags;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AWallRunWall_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AStaticMeshActor,
		(UObject* (*)())Z_Construct_UPackage__Script_NewCppTutorial,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AWallRunWall_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWallRunWall_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Input" },
		{ "IncludePath", "WallRunWall.h" },
		{ "ModuleRelativePath", "Public/WallRunWall.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWallRunWall_Statics::NewProp_WallRunWallTags_MetaData[] = {
		{ "Category", "GameplayTags" },
		{ "ModuleRelativePath", "Public/WallRunWall.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AWallRunWall_Statics::NewProp_WallRunWallTags = { "WallRunWallTags", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AWallRunWall, WallRunWallTags), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AWallRunWall_Statics::NewProp_WallRunWallTags_MetaData), Z_Construct_UClass_AWallRunWall_Statics::NewProp_WallRunWallTags_MetaData) }; // 405371792
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AWallRunWall_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWallRunWall_Statics::NewProp_WallRunWallTags,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AWallRunWall_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AWallRunWall>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AWallRunWall_Statics::ClassParams = {
		&AWallRunWall::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AWallRunWall_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AWallRunWall_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AWallRunWall_Statics::Class_MetaDataParams), Z_Construct_UClass_AWallRunWall_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AWallRunWall_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_AWallRunWall()
	{
		if (!Z_Registration_Info_UClass_AWallRunWall.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AWallRunWall.OuterSingleton, Z_Construct_UClass_AWallRunWall_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AWallRunWall.OuterSingleton;
	}
	template<> NEWCPPTUTORIAL_API UClass* StaticClass<AWallRunWall>()
	{
		return AWallRunWall::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AWallRunWall);
	AWallRunWall::~AWallRunWall() {}
	struct Z_CompiledInDeferFile_FID_Unreal_engine_NewCppTutorial_Source_NewCppTutorial_Public_WallRunWall_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Unreal_engine_NewCppTutorial_Source_NewCppTutorial_Public_WallRunWall_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AWallRunWall, AWallRunWall::StaticClass, TEXT("AWallRunWall"), &Z_Registration_Info_UClass_AWallRunWall, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AWallRunWall), 2662071190U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Unreal_engine_NewCppTutorial_Source_NewCppTutorial_Public_WallRunWall_h_493814500(TEXT("/Script/NewCppTutorial"),
		Z_CompiledInDeferFile_FID_Unreal_engine_NewCppTutorial_Source_NewCppTutorial_Public_WallRunWall_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Unreal_engine_NewCppTutorial_Source_NewCppTutorial_Public_WallRunWall_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
