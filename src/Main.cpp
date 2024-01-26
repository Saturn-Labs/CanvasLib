#include "Zenova.h"
#include "generated/initcpp.h"
#include "Hooks/Hooks.h"
using namespace Minecraft;

const mce::Color mce::Color::WHITE = { 1, 1, 1, 1 }; 

MOD_FUNCTION void ModLoad(ModContext& ctx) {
	CanvasLib::HookManager::Initialize();
}

MOD_FUNCTION void ModStart() {
	Zenova_Info("CanvasLib started!");
}

MOD_FUNCTION void ModTick() {

}

MOD_FUNCTION void ModStop() {
	
}