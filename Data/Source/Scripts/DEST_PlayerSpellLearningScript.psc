Scriptname DEST_PlayerSpellLearningScript extends ReferenceAlias

Event OnInit()
	DEST_ReferenceAliasExt.RegisterForSpellTomeReadEvent(self)
EndEvent

Event OnPlayerLoadGame()
	DEST_ReferenceAliasExt.RegisterForSpellTomeReadEvent(self)
EndEvent

Event OnSpellTomeRead(Spell akSpell)
	Debug.Notification("Spell Tome read: " + akSpell.GetName())
EndEvent
