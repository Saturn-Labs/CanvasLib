#include "Zenova.h"
#include "generated/initcpp.h"

MOD_FUNCTION void ModLoad(ModContext& ctx) {
	Zenova_Info("Mod {} loaded!", ctx.folder);
}

MOD_FUNCTION void ModStart() {
	Zenova_Info("Mod Started!");
}

MOD_FUNCTION void ModTick() {

}

MOD_FUNCTION void ModStop() {
	Zenova_Info("Mod Stopped!");
}