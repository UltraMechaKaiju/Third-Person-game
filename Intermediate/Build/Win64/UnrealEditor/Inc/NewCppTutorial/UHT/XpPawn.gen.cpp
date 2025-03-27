// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "NewCppTutorial/XpPawn.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeXpPawn() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_APawn();
	ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
	NEWCPPTUTORIAL_API UClass* Z_Construct_UClass_AXpPawn();
	NEWCPPTUTORIAL_API UClass* Z_Construct_UClass_AXpPawn_NoRegister();
	UPackage* Z_Construct_UPackage__Script_NewCppTutorial();
// End Cross Module References
	void AXpPawn::StaticRegisterNativesAXpPawn()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AXpPawn);
	UClass* Z_Construct_UClass_AXpPawn_NoRegister()
	{
		return AXpPawn::StaticClass();
	}
	struct Z_Construct_UClass_AXpPawn_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_PlayerMesh_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_PlayerMesh;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_PlayerCamera_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_PlayerCamera;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MoveSpeed_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_MoveSpeed;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_RotationSpeed_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_RotationSpeed;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AXpPawn_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_APawn,
		(UObject* (*)())Z_Construct_UPackage__Script_NewCppTutorial,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AXpPawn_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AXpPawn_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "XpPawn.h" },
		{ "ModuleRelativePath", "XpPawn.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AXpPawn_Statics::NewProp_PlayerMesh_MetaData[] = {
		{ "Category", "XpPawn" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "XpPawn.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AXpPawn_Statics::NewProp_PlayerMesh = { "PlayerMesh", nullptr, (EPropertyFlags)0x0040000000090009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AXpPawn, PlayerMesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AXpPawn_Statics::NewProp_PlayerMesh_MetaData), Z_Construct_UClass_AXpPawn_Statics::NewProp_PlayerMesh_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AXpPawn_Statics::NewProp_PlayerCamera_MetaData[] = {
		{ "Category", "XpPawn" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "XpPawn.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AXpPawn_Statics::NewProp_PlayerCamera = { "PlayerCamera", nullptr, (EPropertyFlags)0x0040000000090009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AXpPawn, PlayerCamera), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AXpPawn_Statics::NewProp_PlayerCamera_MetaData), Z_Construct_UClass_AXpPawn_Statics::NewProp_PlayerCamera_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AXpPawn_Statics::NewProp_MoveSpeed_MetaData[] = {
		{ "Category", "XpPawn" },
		{ "ModuleRelativePath", "XpPawn.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AXpPawn_Statics::NewProp_MoveSpeed = { "MoveSpeed", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AXpPawn, MoveSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AXpPawn_Statics::NewProp_MoveSpeed_MetaData), Z_Construct_UClass_AXpPawn_Statics::NewProp_MoveSpeed_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AXpPawn_Statics::NewProp_RotationSpeed_MetaData[] = {
		{ "Category", "XpPawn" },
		{ "ModuleRelativePath", "XpPawn.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AXpPawn_Statics::NewProp_RotationSpeed = { "RotationSpeed", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AXpPawn, RotationSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AXpPawn_Statics::NewProp_RotationSpeed_MetaData), Z_Construct_UClass_AXpPawn_Statics::NewProp_RotationSpeed_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AXpPawn_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AXpPawn_Statics::NewProp_PlayerMesh,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AXpPawn_Statics::NewProp_PlayerCamera,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AXpPawn_Statics::NewProp_MoveSpeed,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AXpPawn_Statics::NewProp_RotationSpeed,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AXpPawn_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AXpPawn>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AXpPawn_Statics::ClassParams = {
		&AXpPawn::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AXpPawn_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AXpPawn_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AXpPawn_Statics::Class_MetaDataParams), Z_Construct_UClass_AXpPawn_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AXpPawn_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_AXpPawn()
	{
		if (!Z_Registration_Info_UClass_AXpPawn.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AXpPawn.OuterSingleton, Z_Construct_UClass_AXpPawn_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AXpPawn.OuterSingleton;
	}
	template<> NEWCPPTUTORIAL_API UClass* StaticClass<AXpPawn>()
	{
		return AXpPawn::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AXpPawn);
	AXpPawn::~AXpPawn() {}
	struct Z_CompiledInDeferFile_FID_NewCppTutorial_Source_NewCppTutorial_XpPawn_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_NewCppTutorial_Source_NewCppTutorial_XpPawn_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AXpPawn, AXpPawn::StaticClass, TEXT("AXpPawn"), &Z_Registration_Info_UClass_AXpPawn, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AXpPawn), 2323599128U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_NewCppTutorial_Source_NewCppTutorial_XpPawn_h_1266046586(TEXT("/Script/NewCppTutorial"),
		Z_CompiledInDeferFile_FID_NewCppTutorial_Source_NewCppTutorial_XpPawn_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_NewCppTutorial_Source_NewCppTutorial_XpPawn_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
