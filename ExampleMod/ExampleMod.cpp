#include "ExampleMod.h"
#include "Utilities/MinHook.h"
#include "Ue4.hpp"
#define _USE_MATH_DEFINES
#include <math.h>
#include <comdef.h>
#include "Longvinter.h"

std::vector<UE4::AActor*> players;
UE4::AActor* localPlayer = nullptr;
UE4::AActor* pc_longvinter = nullptr;
UE4::UFunction* w2s = nullptr;

// [F4] Print item list
void ExampleMod::Test2() {
	std::cout << "Test2!" << "\n";
	if (localPlayer) {
		FS_Items_Rename22 ItemList = *(FS_Items_Rename22*)(localPlayer + 0x728);
		UE4::TArray<struct FS_ItemData_Rename2> items = ItemList.Items;
		for (int i = 0; i < items.Num(); i++) {
			if (items[i].Name_95_49AEBAFF411339CDDC5B75BD9B47F68E.Data->Name) {
				std::cout << i << " : ";
				std::wcout << items[i].Name_95_49AEBAFF411339CDDC5B75BD9B47F68E.Data->Name << "\n";
			}
		}
		std::cout << "Total items: " << items.Num() << "\n";
	}
}

// [F3] Heal
void ExampleMod::Test3() {
	if (localPlayer) {
		std::cout << "Test4!" << "\n";
		if (localPlayer->DoesObjectContainFunction("RemoveEnergyServer")) {
			UE4::UFunction* RemoveEnergyServer = localPlayer->GetFunction("RemoveEnergyServer");
			struct {
				float remove = -100.0f;
				UE4::AActor* causer = nullptr;
				bool updateClient = true;
			} params;
			localPlayer->ProcessEvent(RemoveEnergyServer, &params);
		}
	}
}

// Only Called Once, if you need to hook shit, declare some global non changing values
void ExampleMod::InitializeMod()
{
	UE4::InitSDK();
	SetupHooks();
	w2s = UE4::UObject::FindObject<UE4::UFunction>("Function Engine.PlayerController.ProjectWorldLocationToScreen");

	//MinHook::Init(); //Uncomment if you plan to do hooks

	UseMenuButton = true; // Allows Mod Loader To Show Button
}

void ExampleMod::InitGameState()
{
}

void ExampleMod::BeginPlay(UE4::AActor* Actor)
{
	// ThirdPersonCharacter_C
	if (Actor->GetName().find("ThirdPersonCharacter") != std::string::npos) {
		players.push_back(Actor);
		// Check if the ThirdPersonCharacter is the local Player
		if (Actor->DoesObjectContainFunction("IsLocalPlayer")) {
			UE4::UFunction* IsLocalPlayer = Actor->GetFunction("IsLocalPlayer");
			bool bIsLocalPlayer = false;
			Actor->ProcessEvent(IsLocalPlayer, &bIsLocalPlayer);

			if (bIsLocalPlayer) {
				localPlayer = Actor;
			}
		}
	}
	else if (Actor->GetName().find("PC_Longvinter") != std::string::npos) {
		pc_longvinter = Actor;
		std::cout << Actor->GetName() << "\n";
	}
}

void ExampleMod::PostBeginPlay(std::wstring ModActorName, UE4::AActor* Actor)
{
	// Filters Out All Mod Actors Not Related To Your Mod
	std::wstring TmpModName(ModName.begin(), ModName.end());
	if (ModActorName == TmpModName)
	{
		//Sets ModActor Ref
		ModActor = Actor;
	}
}

void ExampleMod::DX11Present(ID3D11Device* pDevice, ID3D11DeviceContext* pContext, ID3D11RenderTargetView* pRenderTargetView)
{
}

void ExampleMod::OnModMenuButtonPressed()
{
	std::cout << "\n\n\n" << "Pressed the menu button" << "\n\n\n";
}

const char* items[]{
"Fence Gate",
"Assault Rifle",
"Cloudberries",
"Research Tent",
"Wood",
"Container",
"Chainsaw",
"Ammo [100]",
"Satellite Communicator",
"Fishing Rod",
"Perch",
"Cooked Perch",
"Pike",
"Cooked Pike",
"Trout",
"Cooked Trout",
"Rainbow Trout",
"Cooked Rainbow Trout",
"Wood & Matches",
"Mezereons",
"Sign",
"Fireplace",
"Raspberries",
"Blackberries",
"Seeds: Cloudberry bush",
"Seeds: Raspberry bush",
"Seeds: Mezereon bush",
"Seeds: Blackberry bush",
"Fence",
"Workbench",
"Planter Box 3x3",
"Tarp",
"Mysterious bag",
"Pristine Hazel Hen Feather",
"Hazel Hen Feather",
"Fishing Hat",
"Whitefish",
"Cooked Whitefish",
"Shotgun",
"Hatchet",
"Combat Hat",
"Pristine Kiiruna Feather",
"Kiiruna Feather",
"AutoDefender",
"Semi-Automatic",
"Solar Kit",
"Light Bulb",
"Lamp Post",
"Wheat",
"Seeds: Wheat",
"Metal Parts",
"Juniper Wood",
"Juniper Planks",
"Regular Wood Planks",
"Sugar Beet",
"Seeds: Sugar Beet",
"Sugar Bag",
"Cloudberry Jam",
"Rasberry Jam",
"Blackberry Jam",
"Telescopic Reel",
"Flour",
"Cake",
"Bread",
"Croissant",
"Ammo [25]",
"Ammo [50]",
"Snackbar",
"Energy Drink: Regular",
"Crafting book",
"Cooking book",
"Salt",
"Black Pepper",
"Dill",
"Life Jacket",
"Lifebuoy",
"Canned Fish",
"Water Canister",
"Submachine Gun",
"Hunting Hat",
"Titanium Ingot",
"Fuel",
"Kingcup",
"Seeds: Kingcup",
"Windflower",
"Seeds: Windflower",
"Hepatica",
"Seeds: Hepatica",
"Painting: Anders",
"Garden Fence",
"Garden Fence (Red)",
"Garden Fence (Blue)",
"Garden Fence (Yellow)",
"Garden Fence (Mint)",
"Garden Fence (Blush)",
"Makeshift bench",
"Garden Tile",
"Garden Tile 2x2",
"Garden Firepit",
"Slab Planter Box",
"Trimmed Bush",
"Village Lamp Post",
"Farming Hat",
"Code Lock Gate",
"Heat Pack",
"Metal Stock",
"Wooden Stock",
"Short Gun Barrel",
"Long Gun Barrel",
"Semi-Automatic Kit",
"Assault Rifle Kit",
"Shotgun Kit",
"Submachine Gun Kit",
"Ammo Pouch",
"Pristine Peacock Feather",
"Peacock Feather",
"Haddock",
"Cooked Haddock",
"Cod",
"Cooked Cod",
"Pristine Capercaillie Feather",
"Capercaillie Feather",
"Energy Drink: Shock",
"Energy Drink: Mild",
"Salmon",
"Cooked Salmon",
"Catfish",
"Cooked Catfish",
"Arctic Char",
"Cooked Arctic Char",
"Rug: Grey Persian",
"Rug: Blue Cabin",
"Wood Stool",
"Poppy",
"Seeds: Poppy",
"Black Lotus",
"Seeds: Black Lotus",
"Battery",
"AutoDefender Kit",
"Bird Meat",
"Cooked Bird Meat",
"Chanterelles",
"Chanterelle soup",
"Redfish",
"Cooked Redfish",
"Salmon Shark",
"Cooked Salmon Shark",
"Black Grouper",
"Cooked Black Grouper",
"Misty Grouper",
"Cooked Misty Grouper"
};

std::string GetHitPlayer() {
	if (localPlayer) {
		try {
			UE4::AActor* currentHitActor = *(UE4::AActor**)(localPlayer + 0x5E0);
			if (currentHitActor->GetName().find("ThirdPersonCharacter") != std::string::npos) {
				UE4::APlayerState* playerState = *(UE4::APlayerState**)(currentHitActor + 0x240);
				if (playerState) {
					UE4::FString playerName = *(UE4::FString*)(playerState + 0x300);
					if (playerName.Num() > 0) {
						std::string name = playerName.ToString();
						return name;
					}
				}
			}
		}
		catch (...) {

		}
	}
	std::string name = "null";
	return name;
}

char* GetPlacerID() {
	if (localPlayer) {
		try {
			UE4::AActor* currentHitActor = *(UE4::AActor**)(localPlayer + 0x5E0);
			if (currentHitActor->GetName().find("Home") != std::string::npos) {
				UE4::FString playerName = *(UE4::FString*)(currentHitActor + 0x308);
				if (playerName.Num() > 16) {
					_bstr_t b(playerName.c_str());
					char* steamID = b;
					return steamID;
				}
			}
		}
		catch (...) {

		}
	}
	return nullptr;
}

char* GetItemPlacerID() {
	if (localPlayer) {
		try {
			UE4::AActor* currentHitActor = *(UE4::AActor**)(localPlayer + 0x5E0);
			if (currentHitActor) {
				UE4::FString playerName = *(UE4::FString*)(currentHitActor + 0x2A0);
				if (playerName.Num() > 16) {
					_bstr_t b(playerName.c_str());
					char* steamID = b;
					return steamID;
				}
			}
		}
		catch (...) {

		}
	}
	return nullptr;
}

void SetCoolName() {
	if (localPlayer) {
		*(float*)(localPlayer + 0x7D4) = 0.0f;
	}
}

UE4::AActor* playerWithCoords = nullptr;
void AddCoordinates() {
	if (localPlayer) {
		if (playerWithCoords != localPlayer) {
			if (pc_longvinter->DoesObjectContainFunction("toggleCordinatesWidget")) {
				UE4::UFunction* toggleCordinatesWidget = pc_longvinter->GetFunction("toggleCordinatesWidget");
				bool remove = false;
				pc_longvinter->ProcessEvent(toggleCordinatesWidget, &remove);
			}
		}
		playerWithCoords = localPlayer;
	}
}

void AddEnergy() {
	if (localPlayer) {
		std::cout << "Test4!" << "\n";
		if (localPlayer->DoesObjectContainFunction("RemoveEnergyServer")) {
			UE4::UFunction* RemoveEnergyServer = localPlayer->GetFunction("RemoveEnergyServer");
			struct {
				float remove = -100.0f;
				UE4::AActor* causer = nullptr;
				bool updateClient = true;
			} params;
			localPlayer->ProcessEvent(RemoveEnergyServer, &params);
		}
	}
}

void AddMoney() {
	if (localPlayer) {
		std::cout << "Test5!" << "\n";
		if (localPlayer->DoesObjectContainFunction("AddCurrency")) {
			UE4::UFunction* AddCurrency = localPlayer->GetFunction("AddCurrency");
			int32_t amount = 10000;
			localPlayer->ProcessEvent(AddCurrency, &amount);
		}
	}
}

void AddItem(int item) {
	if (localPlayer) {
		std::cout << "Test1!" << "\n";
		if (localPlayer->DoesObjectContainFunction("AddInventoryServer")) {
			UE4::UFunction* AddInventoryServer = localPlayer->GetFunction("AddInventoryServer");
			struct test {
				int32_t NewItem = 5;
				bool Fishing = false;
			} params;
			params.NewItem = item;
			localPlayer->ProcessEvent(AddInventoryServer, &params);
		}
	}
}

void DrawInfo() {
	ImGuiWindowFlags window_flags = 0;
	window_flags |= ImGuiWindowFlags_NoBackground;
	window_flags |= ImGuiWindowFlags_NoDecoration;
	window_flags |= ImGuiWindowFlags_NoInputs;

	bool open = true;
	bool* open_ptr = &open;
	ImGui::Begin("test", open_ptr, window_flags);
	ImGui::SetWindowSize(ImVec2(2560.0f, 1440.0f));
	ImGui::SetWindowPos(ImVec2(0.0f, 0.0f));
	ImGuiWindow* window = ImGui::GetCurrentWindow();

	UE4::UWorld* world = UE4::UWorld::GetWorld();
	UE4::AActor* gs = *(UE4::AActor**)(world + 0x120);
	if (!gs) return;
	UE4::TArray<UE4::AActor*> playerStates = *(UE4::TArray<UE4::AActor*>*)(gs + 0x238);
	if (playerStates.Num() == 0) return;

	for (int i = 0; i < playerStates.Num(); i++) {
		if (playerStates[i]) {
			for (int j = 0; j < players.size(); j++) {
				try {
					UE4::APlayerState* playerState = *(UE4::APlayerState**)(players[j] + 0x240);
					if (!playerState) continue;
					int32_t playerId = *(int32_t*)(playerState + 0x224);
					int32_t GSplayerId = *(int32_t*)(playerStates[i] + 0x224);

					if (playerId == GSplayerId) {
						if (players[j]) {
							UE4::FString playerName = *(UE4::FString*)(playerState + 0x300);
							UE4::UObject* capsuleComponent = *(UE4::UObject**)(players[j] + 0x290);

							float player_x = *(float*)(capsuleComponent + 0x1D0);
							float player_y = *(float*)(capsuleComponent + 0x1D4);
							float player_z = *(float*)(capsuleComponent + 0x1D8);

							UE4::APlayerController* playerController = *(UE4::APlayerController**)(localPlayer + 0x258);

							struct {
								UE4::FVector WorldLocation;
								UE4::FVector2D ScreenLocation;
								bool bPlayerViewportRelative = false;
								bool returnValue = false;
							} params;
							params.WorldLocation = UE4::FVector(player_x, player_y, player_z - 120.0f);
							params.ScreenLocation = UE4::FVector2D();
							playerController->ProcessEvent(w2s, &params);

							if (params.returnValue) {
								const auto screenPos = params.ScreenLocation;

								if (screenPos.X) {
									ImVec2 windowPos = ImVec2(screenPos.X - 22.5f, screenPos.Y);
									ImU32 color = ImGui::ColorConvertFloat4ToU32(ImVec4(1.0f, 1.0f, 1.0f, 255.0f));
									window->DrawList->AddText(windowPos, color, playerName.ToString().c_str(), nullptr);
								}
							}
						}
					}
				}
				catch (...) {
					continue;
				}
			}
		}
	}
	ImGui::End();
}

void DrawCameraControls() {
	if (localPlayer) {
		UE4::UObject* camera = *(UE4::UObject**)(localPlayer + 0x4C0);
		if (!camera) return;
		float* fov = (float*)(camera + 0x1F8);
		float* camera_x = (float*)(camera + 0x11C);
		float* camera_y = (float*)(camera + 0x120);
		float* camera_z = (float*)(camera + 0x124);

		UE4::UObject* cameraBoom = *(UE4::UObject**)(localPlayer + 0x4B8);
		if (!cameraBoom) return;
		float* camera_pitch = (float*)(cameraBoom + 0x128);
		float* camera_yaw = (float*)(cameraBoom + 0x12C);
		float* camera_roll = (float*)(cameraBoom + 0x130);

		UE4::UWorld* world = UE4::UWorld::GetWorld();
		UE4::UObject* offset1 = *(UE4::UObject**)(world + 0x30);
		UE4::UObject* offset2 = *(UE4::UObject**)(offset1 + 0xE8);
		UE4::UObject* offset3 = *(UE4::UObject**)(offset2 + 0x258);
		UE4::UObject* offset4 = *(UE4::UObject**)(offset3 + 0x220);
		float* fogOpacity = (float*)(offset4 + 0x25C);
		UE4::UObject* offset3_2 = *(UE4::UObject**)(offset2 + 0x250);
		int* hours = (int*)(offset3_2 + 0x24C);

		ImGui::Begin("Camera controls");
		ImGui::SliderFloat("Fov", fov, 1.0f, 179.0f);
		ImGui::Dummy(ImVec2(0.0f, 10.0f));
		ImGui::SliderFloat("X", camera_x, -10000.0f, 10000.0f);
		ImGui::SliderFloat("Y", camera_y, -10000.0f, 10000.0f);
		ImGui::SliderFloat("Z", camera_z, -10000.0f, 10000.0f);
		ImGui::Dummy(ImVec2(0.0f, 10.0f));
		ImGui::SliderFloat("Pitch", camera_pitch, -180.0f, 180.0f);
		ImGui::SliderFloat("Yaw", camera_yaw, -180.0f, 180.0f);
		ImGui::SliderFloat("Roll", camera_roll, -180.0f, 180.0f);
		ImGui::Dummy(ImVec2(0.0f, 10.0f));
		ImGui::SliderInt("Current time (h)", hours, 0, 24);
		ImGui::SliderFloat("Fog opacity", fogOpacity, 0.0f, 5.0f);
		if (ImGui::Button("Reset to defaults")) {
			*fov = 55.0f;
			*camera_x = 0.0f;
			*camera_y = 0.0f;
			*camera_z = -80.0f;
			*camera_pitch = -45.0f;
			*camera_yaw = 0.0f;
			*camera_roll = 0.0f;
			*fogOpacity = 1.0f;
		}
		ImGui::End();
	}
}

static int selectedItem = 0;
bool showNames = true;
void ExampleMod::DrawImGui()
{
	if (showNames) {
		DrawInfo();
	}
	ImGui::Begin("Cheats");
	ImGui::Checkbox("Player Names", &showNames);
	ImGui::Dummy(ImVec2(0.0f, 10.0f));
	//ImGui::Text("Player under cursor: %s", GetHitPlayer());
	ImGui::Text("House owner SteamID: %s", GetPlacerID());
	ImGui::Text("Item placer SteamID: %s", GetItemPlacerID());
	ImGui::Dummy(ImVec2(0.0f, 10.0f));
	ImGui::Combo("", &selectedItem, items, IM_ARRAYSIZE(items));
	if (ImGui::Button("Add Item")) {
		AddItem(selectedItem + 1);
	}
	ImGui::Dummy(ImVec2(0.0f, 10.0f));
	if (ImGui::Button("Cool Name")) {
		SetCoolName();
	}
	if (ImGui::Button("Show Coordinate Widget")) {
		AddCoordinates();
	}
	if (ImGui::Button("Heal")) {
		AddEnergy();
	}
	if (ImGui::Button("Add 10k mk")) {
		AddMoney();
	}
	ImGui::End();
	DrawCameraControls();
}