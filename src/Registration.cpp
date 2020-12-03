#include "Registration.h"

OnSpellTomeReadRegSet* OnSpellTomeReadRegSet::GetSingleton()
{
	static OnSpellTomeReadRegSet singleton;
	return &singleton;
}

OnSpellTomeReadRegSet::OnSpellTomeReadRegSet() : Base("OnSpellTomeRead"sv)
{ }