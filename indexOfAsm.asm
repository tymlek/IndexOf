; IndexOf function		(indexOfAsm.asm)

.586
.model flat, C
IndexOf Proto, srchVal:DWord, arrayPtr:Ptr DWord, count:DWord

.code
;------------------------------------------------------------------------------
; Performs a linear search of a 32-bit integer array, looking for a specific
; value. If the value is found, the matching index position is returned in EAX;
; otherwise, EAX equals -1.
;------------------------------------------------------------------------------
IndexOf Proc Uses ecx esi edi, srchVal:DWord, arrayPtr:Ptr DWord, count:DWord
	NOT_FOUND = -1

	mov eax,srchVal				; search value
	mov ecx,count				; array size
	mov esi,arrayPtr			; pointer to array
	mov edi,0					; index

	L1:
		cmp [esi+edi*4],eax
		je Found
		inc edi
	Loop L1
	
	NotFound:
		mov al,NOT_FOUND
		jmp short Exit

	Found:
		mov eax,edi

	Exit:
		ret
IndexOf EndP
End
