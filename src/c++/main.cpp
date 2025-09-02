#include "Papyrus/Papyrus.h"
#include "F4SE/Logger.h"

extern "C" DLLEXPORT bool F4SEAPI F4SEPlugin_Query(const F4SE::QueryInterface* a_f4se, F4SE::PluginInfo* a_info)
{
	// Early logging uses F4SE::log::info/warn/error which forward to
	// OutputDebugString until F4SE::log::init() runs in F4SEPlugin_Load.

	a_info->infoVersion = F4SE::PluginInfo::kVersion;
	a_info->name = "ConsoleUtilF4VR";
	a_info->version = 1;

	if (a_f4se->IsEditor()) {
		logger::critical("loaded in editor"sv);
		return false;
	}

	const auto ver = a_f4se->RuntimeVersion();
	if (ver < F4SE::RUNTIME_VR_1_2_72) {
		logger::critical("unsupported runtime v{}"sv, ver.string());
		return false;
	}

	return true;
}

extern "C" DLLEXPORT bool F4SEAPI F4SEPlugin_Load(const F4SE::LoadInterface* a_f4se)
{
	F4SE::Init(a_f4se);

	const auto papyrus = F4SE::GetPapyrusInterface();
	papyrus->Register(Papyrus::Bind);

	return true;
}
