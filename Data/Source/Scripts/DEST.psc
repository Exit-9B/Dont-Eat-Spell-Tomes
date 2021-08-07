Scriptname DEST Hidden

; Current version is 2
int Function GetAPIVersion() global native

; Send event to listeners
Function SendSpellTomeReadEvent(Book akBook, Spell akSpell, ObjectReference akContainer = None) global native
