Scriptname DEST_PlayerSpellLearningScript extends ReferenceAlias

Event OnInit()
	DEST_ReferenceAliasExt.RegisterForSpellTomeReadEvent(self)
EndEvent

Event OnPlayerLoadGame()
	DEST_ReferenceAliasExt.RegisterForSpellTomeReadEvent(self)
EndEvent

Event OnSpellTomeRead(Book akBook, Spell akSpell, ObjectReference akContainer)
	Debug.Notification("Spell Tome read: " + akSpell.GetName())
	if akContainer
		Debug.Notification("Container: " + akContainer.GetBaseObject().GetName())
	endif
EndEvent
