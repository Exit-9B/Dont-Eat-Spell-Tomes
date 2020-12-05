Scriptname DEST_PlayerSpellLearningScript extends ReferenceAlias

import DEST_ReferenceAliasExt
import DEST_UIExt

Actor PlayerRef

Event OnInit()
	PlayerRef = Game.GetPlayer()
	RegisterForSpellTomeReadEvent(self)
EndEvent

Event OnPlayerLoadGame()
	RegisterForSpellTomeReadEvent(self)
EndEvent

Event OnSpellTomeRead(Book akBook, Spell akSpell, ObjectReference akContainer)

	if !PlayerRef.HasSpell(akSpell)
		;/ Don't eat the book
		if akContainer
			akContainer.RemoveItem(akBook, 1, abSilent = true)
		else
			PlayerRef.RemoveItem(akBook, 1, abSilent = true)
		endif
		/;

		string sSpellAdded = Game.GetGameSettingString("sSpellAdded")
		string sText = sSpellAdded + ": " + akSpell.GetName()
		PlayerRef.AddSpell(akSpell, abVerbose = false)

		Notification(sText, "UISpellLearned")
	else
		string sAlreadyKnown = Game.GetGameSettingString("sAlreadyKnown")
		string sText = sAlreadyKnown + " " + akSpell.GetName()

		Notification(sText)
	endif
EndEvent
