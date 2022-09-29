Scriptname DEST_ReferenceAliasExt Hidden

; DEPRECATED - Use DEST_AliasExt
Function RegisterForSpellTomeReadEvent(ReferenceAlias akAlias) global
	DEST_AliasExt.RegisterForSpellTomeReadEvent(akAlias)
EndFunction

; DEPRECATED - Use DEST_AliasExt
Function UnregisterForSpellTomeReadEvent(ReferenceAlias akAlias) global
	DEST_AliasExt.UnregisterForSpellTomeReadEvent(akAlias)
EndFunction

Event OnSpellTomeRead(Book akBook, Spell akSpell, ObjectReference akContainer)
EndEvent
