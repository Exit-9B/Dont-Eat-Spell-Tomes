#include "UIExt.h"
#include "Registration.h"

#define REGISTER(vm, script_name, fn_name) \
vm->RegisterFunction(#fn_name ## sv, script_name, fn_name, true)

void UIExt::Notification(
	RE::StaticFunctionTag*,
	std::string a_notificationText,
	std::string a_soundID,
	bool a_cancelIfAlreadyQueued)
{
	const char* text = a_notificationText.c_str();
	const char* sound = a_soundID.empty() ? nullptr : a_soundID.c_str();
	RE::DebugNotification(text, sound, a_cancelIfAlreadyQueued);
}

bool UIExt::RegisterFuncs(VM* a_vm)
{
	constexpr std::string_view scriptname = "DEST_UIExt"sv;
	REGISTER(a_vm, scriptname, Notification);

	return true;
}
