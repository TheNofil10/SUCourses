remove'values checks:

(sequence? '(a b c)) ----> evaluates to true
(sequence? '()) ---------> evaluates to true
(sequence? '(aa b c)) ---> evaluates to false since aa has length 2
(sequence? '(a 1 c)) ----> evaluates to false since 1 is not a symbol
(sequence? '(a (b c))) --> evaluates to false since (b c) is not a symbol

(same-sequence? '(a b c) '(a b c)) --> evaluates to true
(same-sequence? '() '()) ------------> evaluates to true
(same-sequence? '(a b c) '(b a c)) --> evaluates to false
(same-sequence? '(a b c) '(a b)) ----> evaluates to false
(same-sequence? '(aa b) '(a b c)) ---> produces an error
(same-sequence? '(a b) '(a ba c)) ---> produces an error

(reverse-sequence '(a b c)) --> evaluates to (c b a)
(reverse-sequence '()) -------> evaluates to ()
(reverse-sequence '(aa b)) ---> produces an error

(palindrome? '(a b a)) --> evaluates to true
(palindrome? '(a a a)) --> evaluates to true
(palindrome? '()) -------> evaluates to true
(palindrome? '(a a b)) --> evaluates to false
(palindrome? '(a 1 a)) --> produces an error

(member? 'b '(a b c)) ---> evaluates to true
(member? 'd '(a b c)) ---> evaluates to false
(member? 'd '()) --------> evaluates to false
(member? 5 '(a 5 c)) ----> produces an error
(member? 'd '(aa b c)) --> produces an error

(remove-member 'b '(a b a b c b)) --> evaluates to (a a b c b)
(remove-member 'd '(a b c)) --------> produces an error
(remove-member 'b '()) -------------> produces an error
(remove-member 'b '(a b 5 c)) ------> produces an error
(remove-member 5 '(a b c)) ---------> produces an error

(anagram? '(m a r y) '(a r m y)) --> evaluates to true
(anagram? '() '()) ----------------> evaluates to true
(anagram? '(a b b) '(b a a)) ------> evaluates to false
(anagram? '(a b b) '()) -----------> evaluates to false
(anagram? '(a bb) '(a bb)) --------> produces an error
(anagram? 5 '(a b b)) -------------> produces an error

(anapoli? '(a b b) '(b a b)) ----------> evaluates to true
(anapoli? '() '()) --------------------> evaluates to true
(anapoli? '(d a m a m) '(m a d a m)) --> evaluates to true
(anapoli? '(a b b c) '(a b c b)) ------> evaluates to false
(anapoli? '(a b b c) '(a bb bb)) ------> produces an error
(anapoli? '(a bb) '()) ----------------> produces an error
(anapoli? 5 '(a))----------------------> produces an error