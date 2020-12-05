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
	RE::DebugNotification(a_notificationText.c_str(), a_soundID.c_str(), a_cancelIfAlreadyQueued);
}

bool UIExt::RegisterFuncs(VM* a_vm)
{
	constexpr std::string_view scriptname = "DEST_UIExt"sv;
	REGISTER(a_vm, scriptname, Notification);

	return true;
}
