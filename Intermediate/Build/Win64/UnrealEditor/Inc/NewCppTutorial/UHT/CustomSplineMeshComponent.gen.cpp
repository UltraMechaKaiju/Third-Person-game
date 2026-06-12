// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "NewCppTutorial/Public/CustomSplineMeshComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCustomSplineMeshComponent() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_USplineMeshComponent();
	NEWCPPTUTORIAL_API UClass* Z_Construct_UClass_UCustomSplineMeshComponent();
	NEWCPPTUTORIAL_API UClass* Z_Construct_UClass_UCustomSplineMeshComponent_NoRegister();
	UPackage* Z_Construct_UPackage__Script_NewCppTutorial();
// End Cross Module References
	void UCustomSplineMeshComponent::StaticRegisterNativesUCustomSplineMeshComponent()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UCustomSplineMeshComponent);
	UClass* Z_Construct_UClass_UCustomSplineMeshComponent_NoRegister()
	{
		return UCustomSplineMeshComponent::StaticClass();
	}
	struct Z_Construct_UClass_UCustomSplineMeshComponent_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UCustomSplineMeshComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_USplineMeshComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_NewCppTutorial,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCustomSplineMeshComponent_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCustomSplineMeshComponent_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n *\n */" },
#endif
		{ "HideCategories", "Physics Object Activation Components|Activation Trigger" },
		{ "IncludePath", "CustomSplineMeshComponent.h" },
		{ "ModuleRelativePath", "Public/CustomSplineMeshComponent.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UCustomSplineMeshComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCustomSplineMeshComponent>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UCustomSplineMeshComponent_Statics::ClassParams = {
		&UCustomSplineMeshComponent::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x00B010A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UCustomSplineMeshComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UCustomSplineMeshComponent_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UCustomSplineMeshComponent()
	{
		if (!Z_Registration_Info_UClass_UCustomSplineMeshComponent.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCustomSplineMeshComponent.OuterSingleton, Z_Construct_UClass_UCustomSplineMeshComponent_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UCustomSplineMeshComponent.OuterSingleton;
	}
	template<> NEWCPPTUTORIAL_API UClass* StaticClass<UCustomSplineMeshComponent>()
	{
		return UCustomSplineMeshComponent::StaticClass();
	}
	UCustomSplineMeshComponent::UCustomSplineMeshComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UCustomSplineMeshComponent);
	UCustomSplineMeshComponent::~UCustomSplineMeshComponent() {}
	struct Z_CompiledInDeferFile_FID_Unreal_engine_NewCppTutorial_Source_NewCppTutorial_Public_CustomSplineMeshComponent_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Unreal_engine_NewCppTutorial_Source_NewCppTutorial_Public_CustomSplineMeshComponent_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UCustomSplineMeshComponent, UCustomSplineMeshComponent::StaticClass, TEXT("UCustomSplineMeshComponent"), &Z_Registration_Info_UClass_UCustomSplineMeshComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCustomSplineMeshComponent), 2858676862U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Unreal_engine_NewCppTutorial_Source_NewCppTutorial_Public_CustomSplineMeshComponent_h_4245207171(TEXT("/Script/NewCppTutorial"),
		Z_CompiledInDeferFile_FID_Unreal_engine_NewCppTutorial_Source_NewCppTutorial_Public_CustomSplineMeshComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Unreal_engine_NewCppTutorial_Source_NewCppTutorial_Public_CustomSplineMeshComponent_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
