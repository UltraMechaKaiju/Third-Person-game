// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "NewCppTutorial/MyCollectAcceptable.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMyCollectAcceptable() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UInterface();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
	NEWCPPTUTORIAL_API UClass* Z_Construct_UClass_UMyCollectAcceptable();
	NEWCPPTUTORIAL_API UClass* Z_Construct_UClass_UMyCollectAcceptable_NoRegister();
	UPackage* Z_Construct_UPackage__Script_NewCppTutorial();
// End Cross Module References
	struct MyCollectAcceptable_eventCollect_Parms
	{
		UObject* SourceObject;
		float Count;
	};
	void IMyCollectAcceptable::Collect(UObject* SourceObject, float Count)
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_Collect instead.");
	}
	void UMyCollectAcceptable::StaticRegisterNativesUMyCollectAcceptable()
	{
	}
	struct Z_Construct_UFunction_UMyCollectAcceptable_Collect_Statics
	{
		static const UECodeGen_Private::FObjectPropertyParams NewProp_SourceObject;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Count;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UMyCollectAcceptable_Collect_Statics::NewProp_SourceObject = { "SourceObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MyCollectAcceptable_eventCollect_Parms, SourceObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UMyCollectAcceptable_Collect_Statics::NewProp_Count = { "Count", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MyCollectAcceptable_eventCollect_Parms, Count), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMyCollectAcceptable_Collect_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMyCollectAcceptable_Collect_Statics::NewProp_SourceObject,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMyCollectAcceptable_Collect_Statics::NewProp_Count,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMyCollectAcceptable_Collect_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "MyCollectAcceptable.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMyCollectAcceptable_Collect_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMyCollectAcceptable, nullptr, "Collect", nullptr, nullptr, Z_Construct_UFunction_UMyCollectAcceptable_Collect_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMyCollectAcceptable_Collect_Statics::PropPointers), sizeof(MyCollectAcceptable_eventCollect_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UMyCollectAcceptable_Collect_Statics::Function_MetaDataParams), Z_Construct_UFunction_UMyCollectAcceptable_Collect_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UMyCollectAcceptable_Collect_Statics::PropPointers) < 2048);
	static_assert(sizeof(MyCollectAcceptable_eventCollect_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UMyCollectAcceptable_Collect()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMyCollectAcceptable_Collect_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UMyCollectAcceptable);
	UClass* Z_Construct_UClass_UMyCollectAcceptable_NoRegister()
	{
		return UMyCollectAcceptable::StaticClass();
	}
	struct Z_Construct_UClass_UMyCollectAcceptable_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UMyCollectAcceptable_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UInterface,
		(UObject* (*)())Z_Construct_UPackage__Script_NewCppTutorial,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UMyCollectAcceptable_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UMyCollectAcceptable_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UMyCollectAcceptable_Collect, "Collect" }, // 185940242
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UMyCollectAcceptable_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMyCollectAcceptable_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "MyCollectAcceptable.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UMyCollectAcceptable_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<IMyCollectAcceptable>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UMyCollectAcceptable_Statics::ClassParams = {
		&UMyCollectAcceptable::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x000840A1u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UMyCollectAcceptable_Statics::Class_MetaDataParams), Z_Construct_UClass_UMyCollectAcceptable_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UMyCollectAcceptable()
	{
		if (!Z_Registration_Info_UClass_UMyCollectAcceptable.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UMyCollectAcceptable.OuterSingleton, Z_Construct_UClass_UMyCollectAcceptable_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UMyCollectAcceptable.OuterSingleton;
	}
	template<> NEWCPPTUTORIAL_API UClass* StaticClass<UMyCollectAcceptable>()
	{
		return UMyCollectAcceptable::StaticClass();
	}
	UMyCollectAcceptable::UMyCollectAcceptable(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UMyCollectAcceptable);
	UMyCollectAcceptable::~UMyCollectAcceptable() {}
	static FName NAME_UMyCollectAcceptable_Collect = FName(TEXT("Collect"));
	void IMyCollectAcceptable::Execute_Collect(UObject* O, UObject* SourceObject, float Count)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UMyCollectAcceptable::StaticClass()));
		MyCollectAcceptable_eventCollect_Parms Parms;
		UFunction* const Func = O->FindFunction(NAME_UMyCollectAcceptable_Collect);
		if (Func)
		{
			Parms.SourceObject=SourceObject;
			Parms.Count=Count;
			O->ProcessEvent(Func, &Parms);
		}
	}
	struct Z_CompiledInDeferFile_FID_NewCppTutorial_Source_NewCppTutorial_MyCollectAcceptable_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_NewCppTutorial_Source_NewCppTutorial_MyCollectAcceptable_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UMyCollectAcceptable, UMyCollectAcceptable::StaticClass, TEXT("UMyCollectAcceptable"), &Z_Registration_Info_UClass_UMyCollectAcceptable, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UMyCollectAcceptable), 3638458169U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_NewCppTutorial_Source_NewCppTutorial_MyCollectAcceptable_h_2530642751(TEXT("/Script/NewCppTutorial"),
		Z_CompiledInDeferFile_FID_NewCppTutorial_Source_NewCppTutorial_MyCollectAcceptable_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_NewCppTutorial_Source_NewCppTutorial_MyCollectAcceptable_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
