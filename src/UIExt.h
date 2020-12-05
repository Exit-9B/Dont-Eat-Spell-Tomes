#pragma once

namespace UIExt
{
	using VM = RE::BSScript::IVirtualMachine;

	void Notification(
		RE::StaticFunctionTag*,
		std::string a_notificationText,
		std::string a_soundID,
		bool a_cancelIfAlreadyQueued);

	bool RegisterFuncs(VM* a_vm);
}
