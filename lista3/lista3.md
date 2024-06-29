# Analiza kosztów wywołania funkcji wirtualnych w porównaniu do funkcji niewirtualnych - Lista 3 Filip Żmuda 263631
Stworzono plik main.cpp w którego kodzie wywoływane są dwie funkcje wyświetlające imię danej osoby:
```
void niewirtualnaInfo() {  
    std::cout << imie << std::endl;  
}  
  
virtual void wirtualnaInfo() {  
    std::cout << imie << std::endl;  
}
```
Aby sprawdzić koszt wywołania tych funkcji wygenerowano kod assemblerowy:
```
g++ -S main.cpp
```
I otrzymano:
```
__Z19wywolajNiewirtualnaP5Osoba:
LFB1494:
	.cfi_startproc
	pushl	%esi
	.cfi_def_cfa_offset 8
	.cfi_offset 6, -8
	pushl	%ebx
	.cfi_def_cfa_offset 12
	.cfi_offset 3, -12
	subl	$20, %esp
	.cfi_def_cfa_offset 32
	movl	32(%esp), %eax
	movl	8(%eax), %edx
	movl	%edx, 8(%esp)
	movl	4(%eax), %eax
	movl	$__ZSt4cout, (%esp)
	movl	%eax, 4(%esp)
	call	__ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_i
	movl	%eax, %esi
	movl	(%eax), %eax
	movl	-12(%eax), %eax
	movl	124(%esi,%eax), %ebx
	testl	%ebx, %ebx
	je	L40
	cmpb	$0, 28(%ebx)
	je	L35
	movsbl	39(%ebx), %eax
```

```
__Z16wywolajWirtualnaP5Osoba:
LFB1495:
	.cfi_startproc
	pushl	%esi
	.cfi_def_cfa_offset 8
	.cfi_offset 6, -8
	pushl	%ebx
	.cfi_def_cfa_offset 12
	.cfi_offset 3, -12
	subl	$20, %esp
	.cfi_def_cfa_offset 32
	movl	32(%esp), %ecx
	movl	(%ecx), %eax  ; Załadowanie wskaźnika vtable
	movl	(%eax), %eax  ; Pobranie adresu funkcji z vtable
	cmpl	$__ZN5Osoba13wirtualnaInfoEv, %eax  ; Porównanie 			adresu funkcji z oczekiwanym adresem
	jne	L42  ; Skok warunkowy w przypadku niezgodności

	movl	8(%ecx), %eax
	movl	%eax, 8(%esp)
	movl	4(%ecx), %eax
	movl	$__ZSt4cout, (%esp)
	movl	%eax, 4(%esp)
	call	__ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_i
	movl	%eax, %esi
	movl	(%eax), %eax
	movl	-12(%eax), %eax
	movl	124(%esi,%eax), %ebx
	testl	%ebx, %ebx
	je	L49
	cmpb	$0, 28(%ebx)
	je	L44
	movsbl	39(%ebx), %eax
```

1.  **Wywołanie funkcji niewirtualnej**:
    -   Bezpośrednie wywołanie funkcji `niewirtualnaInfo` bez dodatkowych operacji.
    -   Proste odczytanie adresu funkcji i jej wywołanie.
    
2.  **Wywołanie funkcji wirtualnej**:
    -   Wymaga odczytania wskaźnika do tablicy wirtualnych metod (`vtable`).
    -   Następnie z tablicy vtable pobierany jest wskaźnik do właściwej funkcji wirtualnej.
    -   Dopiero potem następuje wywołanie funkcji.

Koszt użycia funkcji wirtualnych w porównaniu do funkcji niewirtualnych wynika z dodatkowych instrukcji potrzebnych do odczytania adresu funkcji z tablicy vtable. W przypadku funkcji niewirtualnej jest to bezpośrednie wywołanie funkcji, natomiast funkcja wirtualna wymaga dwóch dodatkowych operacji odczytu z pamięci.

#### Podsumowanie

Użycie funkcji wirtualnych wprowadza dodatkowy koszt w postaci dodatkowych instrukcji odczytu z tablicy vtable. Koszt ten jest relatywnie niski, jednak może się kumulować w przypadku częstych wywołań funkcji wirtualnych, co może wpływać na wydajność aplikacji. Dlatego decyzja o używaniu funkcji wirtualnych powinna być świadoma i uzasadniona specyfiką projektu.
