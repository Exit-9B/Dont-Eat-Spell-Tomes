Scriptname DEST_PlayerSpellLearningScript extends ReferenceAlias

Actor PlayerRef

Event OnInit()
	PlayerRef = Game.GetPlayer()
	DEST_ReferenceAliasExt.RegisterForSpellTomeReadEvent(self)
EndEvent

Event OnPlayerLoadGame()
	DEST_ReferenceAliasExt.RegisterForSpellTomeReadEvent(self)
EndEvent

Event OnSpellTomeRead(Book akBook, Spell akSpell, ObjectReference akContainer)

	if !PlayerRef.HasSpell(akSpell)
		if akContainer
			akContainer.RemoveItem(akBook, 1, abSilent = true)
		else
			PlayerRef.RemoveItem(akBook, 1, abSilent = true)
		endif

		string sSpellAdded = Game.GetGameSettingString("sSpellAdded")
		Debug.Notification(sSpellAdded + ": " + akSpell.GetName())
		PlayerRef.AddSpell(akSpell)
	else
		string sAlreadyKnown = Game.GetGameSettingString("sAlreadyKnown")
		Debug.Notification(sAlreadyKnown + " " + akSpell.GetName())
	endif
EndEvent
