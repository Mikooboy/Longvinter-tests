#pragma once
#include "Ue4.hpp"

// dumped from the game

enum class weaponStanse : uint8_t {
	NewEnumerator0 = 0,
	NewEnumerator1 = 1,
	weaponStanse_MAX = 2
};

enum class itemCategoryEnum : uint8_t {
	NewEnumerator3 = 0,
	NewEnumerator0 = 1,
	NewEnumerator1 = 2,
	NewEnumerator2 = 3,
	NewEnumerator4 = 4,
	NewEnumerator5 = 5,
	NewEnumerator6 = 6,
	itemCategoryEnum_MAX = 7
};

enum class itemRarityEnum : uint8_t {
	NewEnumerator0 = 0,
	NewEnumerator1 = 1,
	NewEnumerator2 = 2,
	NewEnumerator3 = 3,
	itemRarityEnum_MAX = 4
};

enum class E_BuffEffect : uint8_t {
	NewEnumerator2 = 0,
	NewEnumerator0 = 1,
	NewEnumerator1 = 2,
	NewEnumerator3 = 3,
	NewEnumerator4 = 4,
	NewEnumerator5 = 5,
	NewEnumerator6 = 6,
	NewEnumerator7 = 7,
	NewEnumerator8 = 8,
	NewEnumerator9 = 9,
	NewEnumerator10 = 10,
	E_MAX = 11
};


struct FS_BuffValuesRename1 {
	enum class E_BuffEffect buffEffect_4_AF1481C94519CC30040D0D86DE9A2090; // 0x00(0x01)
	char pad_1[0x3]; // 0x01(0x03)
	int32_t buffDurationInSeconds_13_B51C5D0B43FF00D819AA4EB5359A753A; // 0x04(0x04)
	int32_t effectMultiplier_7_94550B904C95EAA8797637ADAFACBF33; // 0x08(0x04)
	float remainingDurationInSeconds_11_30E4BAD549ADEC3861AA50AEA7EC4CE9; // 0x0c(0x04)
	struct UE4::FText tooltip_16_A97FEB6B4788B180B995339D90761B1F; // 0x10(0x18)
};

struct FweaponStats {
	struct UE4::UStaticMesh* weaponMesh_8_2D2E99D74B075B558D6B3B8EED07B33E; // 0x00(0x08)
	struct UE4::UStaticMesh* holsterMesh_67_02E14C684B05FF8ACB2412B5683590E1; // 0x08(0x08)
	bool melee_56_15F5E30947F04B25DCA564B2879A8BF6; // 0x10(0x01)
	enum class weaponStanse weaponStanse_18_21CB1F07483C8ECB1BBADAB93782A78A; // 0x11(0x01)
	char pad_12[0x6]; // 0x12(0x06)
	struct UE4::USoundBase* gunSound_32_ED729B5049D5CD1096036396060DF105; // 0x18(0x08)
	struct UE4::USoundBase* aimingSound_44_E014140E495AC0947011489240216E28; // 0x20(0x08)
	float baseDamage_37_0E381C2941F0CC5144A1A69BBAB47F81; // 0x28(0x04)
	float fireRate_26_DC99460C4FCFA6B52CB1568B00077AB1; // 0x2c(0x04)
	bool fullAuto_46_D48862084BEA90E6292794AB5161B45E; // 0x30(0x01)
	char pad_31[0x3]; // 0x31(0x03)
	int32_t ammoConsumtionPerShot_43_AD4B02534B8A83B29B8596916931C93A; // 0x34(0x04)
	int32_t bulletsPerShot_47_F02EE6EB42E66F98A8EA8395AF68D445; // 0x38(0x04)
	int32_t shotsPerTrigger_50_D0CBBC6C457D68CB63B97FA70A777313; // 0x3c(0x04)
	float projectileScatter_13_F7C55D36413B0AF89BBD48AF92732E56; // 0x40(0x04)
	float projectileSpeed_9_2D42572049BF650AC08BA1A7B0C0A708; // 0x44(0x04)
	float damageFallOf_22_3C0EDAFE42F211E241ED41A3859038AD; // 0x48(0x04)
	float screenShake_19_8BAED12B470EE8E87C670AAEEE97328B; // 0x4c(0x04)
	float gravity_40_615D567440CAEC6F7BFC719AF4CDF827; // 0x50(0x04)
	float drag_41_7E74BC7D404E7A77691B7983E6B0BDC6; // 0x54(0x04)
	float mass_42_240BADBB4942701F5CFB5C9763E5CAF7; // 0x58(0x04)
	float MaxDistance_53_6A4D5727462BFAA85761B5B59D90A1E8; // 0x5c(0x04)
	float movementSpeedMultiplier_64_027BAC2A47393B9E4C9F27B1A7223A5F; // 0x60(0x04)
};

struct FS_ItemData_Rename2 {
	struct UE4::UStaticMesh* WorldModel_44_25575ED74FA9024CC85062A21885A1E3; // 0x00(0x08)
	struct UE4::FText Name_95_49AEBAFF411339CDDC5B75BD9B47F68E; // 0x08(0x18)
	struct UE4::FText Description_96_5253D5CA4E19DDBC2A45748CC8FBC46E; // 0x20(0x18)
	struct UE4::UTexture2D* Texture_47_340805084EF953EAFD7135A900B69245; // 0x38(0x08)
	bool Wearable_48_6F65EB264E00812D7F4B6989C961C87B; // 0x40(0x01)
	bool Weapon_49_208CF43F4D201D41298BE89E848FD7CA; // 0x41(0x01)
	char pad_42[0x6]; // 0x42(0x06)
	struct FweaponStats weaponStats_91_CFA1E29B4F1B416DD1831DA721C3B401; // 0x48(0x68)
	float EnergyAmount_50_2962D2EC44E3F6DB75336CB5C4E160CF; // 0xb0(0x04)
	int32_t Attribute_51_9B0C62CC4F1257664BB6C69E5DC08D10; // 0xb4(0x04)
	int32_t Slot_52_F68A8EC24334D6C31097B48A37966A97; // 0xb8(0x04)
	char pad_BC[0x4]; // 0xbc(0x04)
	struct UE4::TArray<struct FcraftingRequirements> craftingRequirement_54_44DF2DBD45A269F372DFD9B1B4618BDA; // 0xc0(0x10)
	bool craftedWithCooking_62_0D81458747AB3976D0FA459E0BA697CE; // 0xd0(0x01)
	char pad_D1[0x3]; // 0xd1(0x03)
	float cookingTime_65_F61E58FD480467C8BA697E9846B3D6A9; // 0xd4(0x04)
	enum class itemCategoryEnum category_76_651283F5460017660F1ECEBC60A5A519; // 0xd8(0x01)
	enum class itemRarityEnum rarity_82_AA8E08FD44DC6C09CD94238FC1C0F53A; // 0xd9(0x01)
	char pad_DA[0x2]; // 0xda(0x02)
	int32_t defaultPrice_88_723C2D9249CF37F7043C1B881F766960; // 0xdc(0x04)
	struct FS_BuffValuesRename1 buff_94_5AB2FA614942F1666E8696AF0586F61D; // 0xe0(0x28)
};

struct FS_Items_Rename22 {
	struct UE4::TArray<struct FS_ItemData_Rename2> Items; // 0x00(0x10)
};